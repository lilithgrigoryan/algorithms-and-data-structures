#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

typedef struct hashtable_node_t
{
    int key;
    void *value;
    struct hashtable_node_t *next;
    struct hashtable_node_t *prev;
} hashtable_node_t;

typedef struct hashtable_t
{
    int num_of_elements;
    int capacity;
    struct hashtable_node_t **list;
} hashtable_t;

hashtable_t *hashtable_create();
void hashtable_destroy();
void hashtable_insert(hashtable_t *ht, int key, void *value);
void *hashtable_get(hashtable_t *ht, int key);
bool hashtable_has(hashtable_t *ht, int key);
void *hashtable_remove(hashtable_t *ht, int key);

#endif
