#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../include/hashtable.h"

void hashtable_test_01()
{
    printf("Running hashtable test 1\n");
    hashtable_t *ht = hashtable_create();

    for (int i = 0; i < ht->capacity; i++)
        assert(ht->list[i] == NULL);
    assert(ht->num_of_elements == 0);

    hashtable_destroy(&ht);
}

void hashtable_test_02()
{
    printf("Running hashtable test 2\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1;
    int v1 = 5;

    hashtable_insert(ht, k1, (void *)&v1);

    assert(ht->num_of_elements == 1);
    assert(ht->list[1]->key == k1);
    assert(ht->list[1]->value == &v1);

    hashtable_destroy(&ht);
}

void hashtable_test_03()
{
    printf("Running hashtable test 3\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 5;
    int v1 = 5, v2 = 10;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);

    assert(ht->num_of_elements == 2);
    assert(ht->list[1]->key == k1);
    assert(ht->list[1]->value == &v1);
    assert(ht->list[5]->key == k2);
    assert(ht->list[5]->value == &v2);

    hashtable_destroy(&ht);
}

void hashtable_test_04()
{
    printf("Running hashtable test 4\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 5, k3 = 129;
    int v1 = 5, v2 = 10, v3 = 4;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);

    assert(ht->num_of_elements == 3);
    assert(ht->list[1]->key == k3);
    assert(ht->list[1]->value == &v3);
    assert(ht->list[1]->next->key == k1);
    assert(ht->list[1]->next->value == &v1);
    assert(ht->list[5]->key == k2);
    assert(ht->list[5]->value == &v2);

    hashtable_destroy(&ht);
}

void hashtable_test_05()
{
    printf("Running hashtable test 5\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 5, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k3);

    assert(removed_value == &v3);
    assert(ht->num_of_elements == 2);
    assert(ht->list[1]->key == k1);
    assert(ht->list[1]->value == &v1);
    assert(ht->list[1]->next == NULL);
    assert(ht->list[1]->prev == NULL);
    assert(ht->list[5]->key == k2);
    assert(ht->list[5]->value == &v2);

    hashtable_destroy(&ht);
}

void hashtable_test_06()
{
    printf("Running hashtable test 6\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 5, k3 = 129;
    int v1 = 5, v2 = 10, v3 = 4;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k2);

    assert(removed_value == &v2);
    assert(ht->num_of_elements == 2);
    assert(ht->list[1]->key == k3);
    assert(ht->list[1]->value == &v3);
    assert(ht->list[1]->next->key == k1);
    assert(ht->list[1]->next->value == &v1);
    assert(ht->list[5] == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_07()
{
    printf("Running hashtable test 7\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 5, k3 = 129;
    int v1 = 5, v2 = 10, v3 = 4;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, 17);

    assert(removed_value == NULL);
    assert(ht->num_of_elements == 3);

    hashtable_destroy(&ht);
}

void hashtable_test_08()
{
    printf("Running hashtable test 8\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k1);

    assert(removed_value == &v1);
    assert(ht->num_of_elements == 2);
    assert(ht->list[1]->prev == NULL);
    assert(ht->list[1]->key == k3);
    assert(ht->list[1]->value == &v3);
    assert(ht->list[1]->next->key == k2);
    assert(ht->list[1]->next->value == &v2);
    assert(ht->list[1]->next->next == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_09()
{
    printf("Running hashtable test 9\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k2);

    assert(removed_value == &v2);
    assert(ht->num_of_elements == 2);
    assert(ht->list[1]->prev == NULL);
    assert(ht->list[1]->key == k3);
    assert(ht->list[1]->value == &v3);
    assert(ht->list[1]->next->key == k1);
    assert(ht->list[1]->next->value == &v1);
    assert(ht->list[1]->next->next == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_10()
{
    printf("Running hashtable test 10\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k3);

    assert(removed_value == &v3);
    assert(ht->num_of_elements == 2);
    assert(ht->list[1]->prev == NULL);
    assert(ht->list[1]->key == k2);
    assert(ht->list[1]->value == &v2);
    assert(ht->list[1]->next->key == k1);
    assert(ht->list[1]->next->value == &v1);
    assert(ht->list[1]->next->next == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_11()
{
    printf("Running hashtable test 11\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k1);
    assert(removed_value == &v1);
    removed_value = hashtable_remove(ht, k3);
    assert(removed_value == &v3);

    assert(ht->num_of_elements == 1);
    assert(ht->list[1]->prev == NULL);
    assert(ht->list[1]->key == k2);
    assert(ht->list[1]->value == &v2);
    assert(ht->list[1]->next == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_12()
{
    printf("Running hashtable test 12\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k3);
    assert(removed_value == &v3);
    removed_value = hashtable_remove(ht, k2);
    assert(removed_value == &v2);

    assert(ht->num_of_elements == 1);
    assert(ht->list[1]->prev == NULL);
    assert(ht->list[1]->key == k1);
    assert(ht->list[1]->value == &v1);
    assert(ht->list[1]->next == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_13()
{
    printf("Running hashtable test 13\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k1);
    assert(removed_value == &v1);
    removed_value = hashtable_remove(ht, k3);
    assert(removed_value == &v3);

    assert(ht->num_of_elements == 1);
    assert(ht->list[1]->prev == NULL);
    assert(ht->list[1]->key == k2);
    assert(ht->list[1]->value == &v2);
    assert(ht->list[1]->next == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_14()
{
    printf("Running hashtable test 14\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *removed_value = hashtable_remove(ht, k1);
    assert(removed_value == &v1);
    removed_value = hashtable_remove(ht, k2);
    assert(removed_value == &v2);
    removed_value = hashtable_remove(ht, k3);
    assert(removed_value == &v3);

    assert(ht->num_of_elements == 0);
    assert(ht->list[1] == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_15()
{
    printf("Running hashtable test 15\n");
    hashtable_t *ht = hashtable_create();
    void *removed_value = hashtable_remove(ht, 1);
    assert(removed_value == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_16()
{
    printf("Running hashtable test 16\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 257, k3 = 129;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *value = hashtable_get(ht, k1);
    assert(value == &v1);
    value = hashtable_get(ht, k2);
    assert(value == &v2);
    value = hashtable_get(ht, k3);
    assert(value == &v3);
    value = hashtable_get(ht, 0);
    assert(value == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_17()
{
    printf("Running hashtable test 17\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1, k2 = 2, k3 = 3;
    int v1 = 1, v2 = 2, v3 = 3;

    hashtable_insert(ht, k1, (void *)&v1);
    hashtable_insert(ht, k2, (void *)&v2);
    hashtable_insert(ht, k3, (void *)&v3);
    void *value = hashtable_get(ht, k1);
    assert(value == &v1);
    value = hashtable_get(ht, k2);
    assert(value == &v2);
    value = hashtable_get(ht, k3);
    assert(value == &v3);
    value = hashtable_get(ht, 0);
    assert(value == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_18()
{
    printf("Running hashtable test 18\n");
    hashtable_t *ht = hashtable_create();
    void *value = hashtable_get(ht, 0);
    assert(value == NULL);

    hashtable_destroy(&ht);
}

void hashtable_test_19()
{
    printf("Running hashtable test 19\n");
    hashtable_t *ht = hashtable_create();
    bool has = hashtable_has(ht, 0);

    assert(!has);

    hashtable_destroy(&ht);
}

void hashtable_test_20()
{
    printf("Running hashtable test 20\n");
    hashtable_t *ht = hashtable_create();
    int k1 = 1;
    int v1 = 1;

    hashtable_insert(ht, k1, (void *)&v1);
    bool has = hashtable_has(ht, k1);

    assert(has);

    hashtable_destroy(&ht);
}
