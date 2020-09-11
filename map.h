#ifndef C_DS_MAP_H
#define C_DS_MAP_H

#include "binary_tree.h"

struct Map{
    struct Binary_Node * bnry_tree;
};

struct Pair{
    void * key;
    void * value;
};

struct Map * map_init(struct Pair init_pari);

void map_add(struct Map * my_map, struct Pair ele, int(compare_to)(const void * const x, const void * const y));

#endif //C_DS_MAP_H
