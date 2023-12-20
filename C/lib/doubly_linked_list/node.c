#include <stdlib.h>
#include <stdio.h>
#include "../../include/list.h"

list_node_t *list_node_create(int val)
{
    list_node_t *node = (list_node_t *)malloc(sizeof(list_node_t));
    node->next = NULL;
    node->prev = NULL;
    node->data = val;

    return node;
}