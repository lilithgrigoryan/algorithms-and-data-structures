#include <stdlib.h>
#include <stdio.h>
#include "../../include/list.h"

list_t *list_create()
{
    list_t *lst = (list_t *)malloc(sizeof(list_t));
    lst->front = NULL;
    lst->back = NULL;
    lst->length = 0;

    return lst;
}

list_node_t *list_push_back(list_t *lst, list_node_t *node)
{
    if (!node)
        return NULL;

    // just to make sure
    node->next = NULL;
    if (lst->length == 0)
    {
        lst->front = node;
        lst->back = node;
    }
    else
    {
        list_node_t *back_node = lst->back;
        back_node->next = node;
        node->prev = back_node;
        lst->back = node;
    }

    lst->length++;

    return node;
}

list_node_t *list_pop_back(list_t *lst)
{
    if (lst->length == 0)
        return NULL;

    list_node_t *back_node = lst->back;
    if (lst->length == 1)
    {
        lst->front = NULL;
        lst->back = NULL;
    }
    else
    {
        lst->back = back_node->prev;
        lst->back->next = NULL;
    }

    lst->length--;
    return back_node;
}

list_node_t *list_push_front(list_t *lst, list_node_t *node)
{
    if (!node)
        return NULL;

    node->prev = NULL;
    if (lst->length == 0)
    {
        node->next = NULL;
        lst->front = node;
        lst->back = node;
    }
    else
    {
        list_node_t *top_node = lst->front;
        node->next = top_node;
        lst->front = node;
        top_node->prev = node;
    }

    lst->length++;
    return node;
}

list_node_t *list_find(list_t *lst, int val)
{
    list_node_t *node = lst->front;
    while (node)
    {
        if (node->data == val)
            break;

        node = node->next;
    }

    return node;
}

list_node_t *list_at(list_t *lst, int index)
{
    int i = 0;
    list_node_t *node;
    if (index >= 0)
    {
        node = lst->front;
        while (node && i++ < index)
            node = node->next;
    }
    else
    {
        node = lst->back;
        while (node && i++ < (-index - 1))
            node = node->prev;
    }

    return node;
}

list_node_t *list_remove(list_t *lst, list_node_t *node)
{
    if (lst->length == 0)
        return NULL;

    list_node_t *curr_node = lst->front;
    while (curr_node)
    {
        if (node == curr_node)
        {
            if (node->prev)
                node->prev->next = node->next;
            else
                lst->front = node->next;

            if (node->next)
                node->next->prev = node->prev;
            else
                lst->back = node->prev;

            lst->length--;
            break;
        }

        curr_node = curr_node->next;
    }
    return curr_node;
}

void list_destroy(list_t **lst)
{
    list_node_t *node = (*lst)->front;
    while (node)
    {
        list_node_t *next_node = node->next;
        free(node);
        node = next_node;
    }

    free(*lst);
}