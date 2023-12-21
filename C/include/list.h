#ifndef LIST_H
#define LIST_H

typedef struct list_t
{
    struct list_node_t* front;
    struct list_node_t* back;
    unsigned int length;
} list_t;

typedef struct list_node_t
{
    int data;
    struct list_node_t* prev;
    struct list_node_t* next;
} list_node_t;

list_t *list_create();
list_node_t *list_node_create(int val);

/**
 * Adds a node to the end of list. Returns the node or NULL if node is NULL. 
*/
list_node_t *list_push_back(list_t *lst, list_node_t *node);

/**
 * Removes and returns the last node. NULL if list is empty.
*/
list_node_t *list_pop_back(list_t *lst);

/**
 * Adds node to the beggining of the list. Returns the node or NULL if node is NULL.
*/
list_node_t *list_push_front(list_t *lst, list_node_t *node);

/**
 * Returns the first appearance of val in list. NULL if val is absent.
*/
list_node_t *list_find(list_t *lst, int val);

/**
 * Returns index-th node.
*/
list_node_t *list_at(list_t *lst, int index);

/*
 * Removes node from list. Return node or NULL if node is not in list.
*/
list_node_t* list_remove(list_t *lst, list_node_t *node);

/**
 * Removes all elements from list and frees memory.
*/
void list_destroy(list_t **lst);

#endif