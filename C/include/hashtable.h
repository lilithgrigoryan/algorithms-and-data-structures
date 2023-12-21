#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct hashtable_node_t
{
    int key, value;
    struct hashtable_node_t* next;
    struct hashtable_node_t* prev;
} hashtable_node_t;

typedef struct hashtable_t {
    int num_of_elements;
    int capacity;
    struct hashtable_node_t** list;
} hashtable_t;

hashtable_t* hashtable_create();

#endif
