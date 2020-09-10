#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"

int compare_to(const void * x, const void * y){
    return *(int*)x - *(int*)y;
}

int main() {

    
    int keys[] = {1,2,5,3,4};
    int values[] = {10,20,50,30,40};
    size_t size = 1;

    struct Binary_Node * root = binary_tree_init_node(&keys[0], &values[0]);

    for (size_t i = 1; i < 5; i++){
          binary_tree_add(root, binary_tree_init_node(&keys[i], &values[i]), compare_to);
    }

    binary_tree_inorder_traversal(root);
    
  
    
    //printf("%d %d", *(int*)root->right->key, *(int*)root->right->value);
    

}