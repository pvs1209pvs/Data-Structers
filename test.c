#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"
#include "map.h"
#include "con_list.h"

int compare_to(const void * const x,  const void * const y){

    struct Pair * a = (struct Pair*)x;
    struct Pair * b = (struct Pair*)y;
    return *(int*)a->key -  *(int*)b->key;

}

int main() {

    int keys[] = {1,2,3,4,5};
    int values[] = {10,20,30,40,50};

    struct Pair int_pairs[] = { 
        {.key=&keys[0], .value=&values[0]},
        {.key=&keys[1], .value=&values[1]},
        {.key=&keys[2], .value=&values[2]},
        {.key=&keys[3], .value=&values[3]},
        {.key=&keys[4], .value=&values[4]},
        };


    struct Map * mapo = map_init(int_pairs[0]);

    map_add(mapo, int_pairs[1], compare_to);
    map_add(mapo, int_pairs[2], compare_to);
    map_add(mapo, int_pairs[3], compare_to);
    

    // char * f_name = "param";
    // char * l_name = "singh";
    // struct Pair name = {f_name, l_name};

    // printf("%s %s\n", (char*)name.key, (char*)name.value);

    // struct Map * map = map_init(name);

    // struct Pair * p = (struct Pair*)map->bnry_tree->key;
    // printf("%s %s\n", (char*)p->key, (char*)p->value);

    //printf("%s \n", map->bnry_tree->key);
    
    // int keys[] = {1, 2, 5, 3, 4, 6, 7, 9, 8, 10};

    // struct Binary_Node * root = binary_tree_init_node(&keys[0]);

    // for (size_t i = 1; i < sizeof(keys)/sizeof(keys[0]); i++){
    //       binary_tree_add(root, binary_tree_init_node(&keys[i]), compare_to);
    // }
    

    // struct List l = binary_tree_ele_array(root);
    
    

}