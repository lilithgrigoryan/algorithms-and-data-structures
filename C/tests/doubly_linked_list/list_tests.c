#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../include/list.h"

void test_01();
void test_02();
void test_03();
void test_04();
void test_05();
void test_06();
void test_07();
void test_08();
void test_09();
void test_10();
void test_11();
void test_12();
void test_13();
void test_14();
void test_15();
void test_16();
void test_17();
void test_18();
void test_19();
void test_20();
void test_21();
void test_22();
void test_23();
void test_24();
void test_25();

int main()
{
    printf("Running doubly linked list tests.\n");
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();
    test_08();
    test_09();
    test_10();
    test_11();
    test_12();
    test_13();
    test_14();
    test_15();
    test_16();
    test_17();
    test_18();
    test_19();
    test_20();
    test_21();
    test_22();
    test_23();
    test_24();
    test_25();

    return 0;
}

void test_01()
{
    printf("Running doubly linked list test 1\n");
    list_t *lst = list_create();
    assert(lst->back == NULL);
    assert(lst->front == NULL);
}

void test_02()
{
    printf("Running doubly linked list test 2\n");
    list_node_t *node = list_node_create(2);
    assert(node->data == 2);
}

void test_03()
{
    printf("Running doubly linked list test 3\n");
    list_t *lst = list_create();
    list_node_t *node = list_node_create(0);

    list_push_back(lst, node);
    assert(lst->back == node);
    assert(lst->front == node);
    assert(lst->length == 1);
}

void test_04()
{
    printf("Running doubly linked list test 4\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);

    list_push_back(lst, node1);
    list_push_back(lst, node2);

    assert(lst->front == node1);
    assert(lst->back == node2);
    assert(lst->front->next == node2);
    assert(lst->back->prev == node1);
    assert(lst->back->next == NULL);
    assert(lst->front->prev == NULL);
    assert(lst->length == 2);
}

void test_05()
{
    printf("Running doubly linked list test 5\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);

    list_push_back(lst, node1);
    list_push_back(lst, node2);

    assert(lst->front == node1);
    assert(lst->back == node2);
    assert(lst->front->next == node2);
    assert(lst->back->prev == node1);
    assert(lst->back->next == NULL);
    assert(lst->front->prev == NULL);
    assert(lst->length == 2);
}

void test_06()
{
    printf("Running doubly linked list test 6\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    assert(lst->front == node1);
    assert(lst->back == node3);
    assert(lst->front->next == node2);
    assert(lst->back->prev == node2);
    assert(lst->back->next == NULL);
    assert(lst->front->prev == NULL);
    assert(lst->length == 3);
}

void test_07()
{
    printf("Running doubly linked list test 7\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);

    list_push_back(lst, node1);

    list_node_t *back_node = list_pop_back(lst);
    assert(lst->front == NULL);
    assert(lst->back == NULL);
    assert(back_node == node1);
    assert(lst->length == 0);
}

void test_08()
{
    printf("Running doubly linked list test 8\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);

    list_push_back(lst, node1);
    list_push_back(lst, node2);

    list_node_t *back_node1 = list_pop_back(lst);
    assert(lst->front == node1);
    assert(lst->back == node1);
    assert(back_node1 == node2);
    assert(lst->length == 1);

    list_node_t *back_node2 = list_pop_back(lst);
    assert(lst->front == NULL);
    assert(lst->back == NULL);
    assert(back_node2 == node1);
    assert(lst->length == 0);
}

void test_09()
{
    printf("Running doubly linked list test 9\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *back_node1 = list_pop_back(lst);
    assert(lst->front == node1);
    assert(lst->back == node2);
    assert(lst->back->next == NULL);
    assert(back_node1 == node3);
    assert(lst->length == 2);

    list_node_t *back_node2 = list_pop_back(lst);
    assert(lst->front == node1);
    assert(lst->back == node1);
    assert(lst->back->next == NULL);
    assert(back_node2 == node2);
    assert(lst->length == 1);

    list_node_t *back_node3 = list_pop_back(lst);
    assert(lst->front == NULL);
    assert(lst->back == NULL);
    assert(back_node3 == node1);
    assert(lst->length == 0);
}

void test_10()
{
    printf("Running doubly linked list test 10\n");
    list_t *lst = list_create();
    list_node_t *node = list_node_create(0);

    list_push_front(lst, node);
    assert(lst->back == node);
    assert(lst->front == node);
    assert(lst->length == 1);
}

void test_11()
{
    printf("Running doubly linked list test 11\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);

    list_push_front(lst, node1);
    list_push_front(lst, node2);
    assert(lst->front == node2);
    assert(lst->front->next == node1);
    assert(lst->front->prev == NULL);
    assert(lst->back == node1);
    assert(lst->back->prev == node2);
    assert(lst->back->next == NULL);
    assert(lst->length == 2);
}

void test_12()
{
    printf("Running doubly linked list test 12\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_front(lst, node1);
    list_push_front(lst, node2);
    list_push_front(lst, node3);
    assert(lst->front == node3);
    assert(lst->front->next == node2);
    assert(lst->front->prev == NULL);
    assert(lst->back == node1);
    assert(lst->back->prev == node2);
    assert(lst->back->next == NULL);
    assert(lst->length == 3);
}

void test_13()
{
    printf("Running doubly linked list test 13\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_front(lst, node1);
    list_push_back(lst, node2);
    list_push_front(lst, node3);
    assert(lst->front == node3);
    assert(lst->front->next == node1);
    assert(lst->front->prev == NULL);
    assert(lst->back == node2);
    assert(lst->back->prev == node1);
    assert(lst->back->next == NULL);
    assert(lst->length == 3);
}

void test_14()
{
    printf("Running doubly linked list test 14\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_front(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);
    assert(lst->front == node1);
    assert(lst->front->next == node2);
    assert(lst->front->prev == NULL);
    assert(lst->back == node3);
    assert(lst->back->prev == node2);
    assert(lst->back->next == NULL);
    assert(lst->length == 3);
}

void test_15()
{
    printf("Running doubly linked list test 15\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_front(lst, node1);
    list_push_front(lst, node2);
    list_push_front(lst, node3);
    assert(list_find(lst, 0) == node1);
    assert(list_find(lst, 1) == node2);
    assert(list_find(lst, 2) == node3);
    assert(list_find(lst, 3) == NULL);
}

void test_16()
{
    printf("Running doubly linked list test 16\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);
    assert(list_at(lst, 0) == node1);
    assert(list_at(lst, 1) == node2);
    assert(list_at(lst, 2) == node3);

    assert(list_at(lst, -1) == node3);
    assert(list_at(lst, -2) == node2);
    assert(list_at(lst, -3) == node1);

    assert(list_at(lst, -8) == NULL);
    assert(list_at(lst, 7) == NULL);
    assert(list_at(lst, 10) == NULL);
}

void test_17()
{
    printf("Running doubly linked list test 17\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);
    list_node_t *node4 = list_node_create(3);
    list_node_t *node5 = list_node_create(4);
    list_node_t *node6 = list_node_create(5);
    list_node_t *node7 = list_node_create(6);

    list_push_front(lst, node1);
    list_push_front(lst, node2);
    list_push_front(lst, node3);
    list_push_front(lst, node4);
    list_push_front(lst, node5);
    list_push_front(lst, node6);
    list_push_front(lst, node7);
    assert(list_at(lst, 0) == node7);
    assert(list_at(lst, 1) == node6);
    assert(list_at(lst, 2) == node5);
    assert(list_at(lst, 3) == node4);
    assert(list_at(lst, 4) == node3);
    assert(list_at(lst, 5) == node2);
    assert(list_at(lst, 6) == node1);

    assert(list_at(lst, -1) == node1);
    assert(list_at(lst, -2) == node2);
    assert(list_at(lst, -3) == node3);
    assert(list_at(lst, -4) == node4);
    assert(list_at(lst, -5) == node5);
    assert(list_at(lst, -6) == node6);
    assert(list_at(lst, -7) == node7);

    assert(list_at(lst, -8) == NULL);
    assert(list_at(lst, 7) == NULL);
    assert(list_at(lst, 10) == NULL);
}

void test_18()
{
    printf("Running doubly linked list test 18\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *node = list_remove(lst, node1);
    assert(node == node1);
    assert(lst->front == node2);
    assert(lst->front->prev == NULL);
    assert(lst->back == node3);
    assert(lst->back->next == NULL);
    assert(lst->length == 2);
}

void test_19()
{
    printf("Running doubly linked list test 19\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *node = list_remove(lst, node2);
    assert(node == node2);
    assert(lst->front == node1);
    assert(lst->front->prev == NULL);
    assert(lst->back == node3);
    assert(lst->back->next == NULL);
    assert(lst->length == 2);
}

void test_20()
{
    printf("Running doubly linked list test 20\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *node = list_remove(lst, node3);
    assert(node == node3);
    assert(lst->front == node1);
    assert(lst->front->prev == NULL);
    assert(lst->back == node2);
    assert(lst->back->next == NULL);
    assert(lst->length == 2);
}

void test_21()
{
    printf("Running doubly linked list test 21\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *rm_node1 = list_remove(lst, node1);
    list_node_t *rm_node2 = list_remove(lst, node2);
    assert(rm_node1 == node1);
    assert(rm_node2 == node2);
    assert(lst->front == node3);
    assert(lst->front->prev == NULL);
    assert(lst->back == node3);
    assert(lst->back->next == NULL);
    assert(lst->length == 1);
}

void test_22()
{
    printf("Running doubly linked list test 22\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *rm_node1 = list_remove(lst, node1);
    list_node_t *rm_node2 = list_remove(lst, node3);
    assert(rm_node1 == node1);
    assert(rm_node2 == node3);
    assert(lst->front == node2);
    assert(lst->front->prev == NULL);
    assert(lst->back == node2);
    assert(lst->back->next == NULL);
    assert(lst->length == 1);
}

void test_23()
{
    printf("Running doubly linked list test 23\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *rm_node1 = list_remove(lst, node2);
    list_node_t *rm_node2 = list_remove(lst, node3);
    assert(rm_node1 == node2);
    assert(rm_node2 == node3);
    assert(lst->front == node1);
    assert(lst->front->prev == NULL);
    assert(lst->back == node1);
    assert(lst->back->next == NULL);
    assert(lst->length == 1);
}

void test_24()
{
    printf("Running doubly linked list test 24\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);

    list_push_back(lst, node1);
    list_push_back(lst, node2);
    list_push_back(lst, node3);

    list_node_t *rm_node1 = list_remove(lst, node1);
    list_node_t *rm_node2 = list_remove(lst, node2);
    list_node_t *rm_node3 = list_remove(lst, node3);
    assert(rm_node1 == node1);
    assert(rm_node2 == node2);
    assert(rm_node3 == node3);
    assert(lst->front == NULL);
    assert(lst->back == NULL);
    assert(lst->length == 0);
}

void test_25()
{
    printf("Running doubly linked list test 25\n");
    list_t *lst = list_create();
    list_node_t *node1 = list_node_create(0);
    list_node_t *node2 = list_node_create(1);
    list_node_t *node3 = list_node_create(2);
    list_node_t *node4 = list_node_create(3);
    list_node_t *node5 = list_node_create(4);
    list_node_t *node6 = list_node_create(5);
    list_node_t *node7 = list_node_create(6);

    list_push_front(lst, node1);
    list_push_front(lst, node2);
    list_push_front(lst, node3);
    list_push_front(lst, node4);
    list_push_front(lst, node5);
    list_push_front(lst, node6);
    list_push_front(lst, node7);
    
    list_destroy(&lst);
}