#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"
#include "map.h"

int compare_to(const void * const x, const void *const  y){
    return *(int*)x - *(int*)y;
}

int main() {

    char * f_name = "param";
    char * l_name = "singh";
    struct Pair name = {f_name, l_name};

    printf("%s %s\n", (char*)name.key, (char*)name.value);

    struct Map * map = map_init(name);

    struct Pair * p = (struct Pair*)map->bnry_tree->key;
    printf("%s %s\n", (char*)p->key, (char*)p->value);
    //printf("%s \n", map->bnry_tree->key);
    
    // int keys[] = {1,2,5,3,4};
    // size_t size = 1;

    // struct Binary_Node * root = binary_tree_init_node(&keys[0]);

    // for (size_t i = 1; i < 5; i++){
    //       binary_tree_add(root, binary_tree_init_node(&keys[i]), compare_to);
    // }

    // struct Binary_Node * probe = binary_tree_contains(root, *binary_tree_init_node(&keys[2]), compare_to);
    // int new_value = 89;
    // binary_tree_update_node(root, probe, &new_value, compare_to);
    
    // binary_tree_inorder_traversal(root);
    

}