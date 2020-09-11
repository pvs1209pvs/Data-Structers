#include <malloc.h>
#include "map.h"

struct Map * map_init(struct Pair init_pair){

    struct Map * map = malloc(sizeof(struct Map));
    map->bnry_tree = binary_tree_init_node(&init_pair);
    return map;

}

void map_add(struct Map * my_map, struct Pair ele, int(compare_to)(const void * const x, const void * const y)){
    binary_tree_add(my_map->bnry_tree, binary_tree_init_node(&ele), compare_to);
}