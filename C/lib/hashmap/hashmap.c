#include "../../include/list.h"

struct hashMap {
    int numOfElements;
    int capacity;
    struct list_node_t** arr;
};