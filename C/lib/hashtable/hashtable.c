#include <stdlib.h>
#include "../../include/hashtable.h"

#define SIZE 128

hashtable_node_t *hashtable_node_create(int key, int value)
{
    hashtable_node_t *node = (hashtable_node_t *)malloc(sizeof(hashtable_node_t));
    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
}

int hashtable_hash(struct hashtable_t *ht, int key)
{
    return key % ht->capacity;
}

hashtable_t *hashtable_create()
{
    hashtable_t *ht = (hashtable_t *)malloc(sizeof(hashtable_t));
    ht->capacity = SIZE;
    ht->num_of_elements = 0;

    ht->list = (hashtable_node_t **)malloc(sizeof(hashtable_node_t *) * ht->capacity);
    for (int i = 0; i < SIZE; i++)
        ht->list[i] = NULL;
}

hashtable_t *hashtable_insert(hashtable_t *ht, int key, int value)
{
    int index = hashtable_hash(ht, key);

    hashtable_node_t *new_node = hashtable_node_create(key, value);
    hashtable_node_t *node = ht->list[index];
    if (node == NULL)
        ht->list[index] = new_node;
    else
    {
        new_node->next = node;
        new_node->prev = NULL;
        node->prev = new_node;
    }
}
