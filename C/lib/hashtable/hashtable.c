#include <stdlib.h>
#include "../../include/hashtable.h"

#define SIZE 128

// private functions
int _hashtable_hash(struct hashtable_t *ht, int key);
hashtable_node_t *_hashtable_get_node(hashtable_t *ht, int key);
hashtable_node_t *_hashtable_get_node_index(hashtable_t *ht, int key, int index);

int _hashtable_hash(struct hashtable_t *ht, int key)
{
    return key % ht->capacity;
}

hashtable_node_t *hashtable_node_create(int key, void *value)
{
    hashtable_node_t *node = (hashtable_node_t *)malloc(sizeof(hashtable_node_t));
    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
}

hashtable_t *hashtable_create()
{
    hashtable_t *ht = (hashtable_t *)malloc(sizeof(hashtable_t));
    ht->capacity = SIZE;
    ht->num_of_elements = 0;

    ht->list = (hashtable_node_t **)malloc(sizeof(hashtable_node_t *) * ht->capacity);
    for (int i = 0; i < SIZE; i++)
        ht->list[i] = NULL;

    return ht;
}

void hashtable_insert(hashtable_t *ht, int key, void *value)
{
    int index = _hashtable_hash(ht, key);

    hashtable_node_t *new_node = hashtable_node_create(key, value);
    hashtable_node_t *node = ht->list[index];
    if (node == NULL)
        ht->list[index] = new_node;
    else
    {
        new_node->next = node;
        new_node->prev = NULL;
        node->prev = new_node;
        ht->list[index] = new_node;
    }

    ht->num_of_elements++;
}

void *hashtable_get(hashtable_t *ht, int key)
{
    hashtable_node_t *node = _hashtable_get_node(ht, key);
    return node ? node->value : NULL;
}

void *hashtable_remove(hashtable_t *ht, int key)
{
    int index = _hashtable_hash(ht, key);
    hashtable_node_t *node = _hashtable_get_node_index(ht, key, index);
    if (!node)
        return NULL;

    hashtable_node_t *prev_node = node->prev;
    hashtable_node_t *next_node = node->next;

    if (next_node)
        next_node->prev = prev_node;

    if (prev_node)
        prev_node->next = next_node;
    else
        ht->list[index] = next_node;

    ht->num_of_elements--;
    void *value = node->value;
    free(node);

    return value;
}

bool hashtable_has(hashtable_t *ht, int key)
{
    hashtable_node_t *node = _hashtable_get_node(ht, key);
    return node ? true : false;
}

void hashtable_destroy(hashtable_t **ht)
{
    for (int i = 0; i < (*ht)->capacity; i++)
    {
        hashtable_node_t *node = (*ht)->list[i];
        while (node)
        {
            hashtable_node_t *next_node = node->next;
            free(node);
            node = next_node;
        }
    }

    free(*ht);
}

hashtable_node_t *_hashtable_get_node_index(hashtable_t *ht, int key, int index)
{
    hashtable_node_t *node = ht->list[index];

    while (node && node->key != key)
        node = node->next;

    return (node && node->key == key) ? node : NULL;
}

hashtable_node_t *_hashtable_get_node(hashtable_t *ht, int key)
{
    int index = _hashtable_hash(ht, key);
    return _hashtable_get_node_index(ht, key, index);
}