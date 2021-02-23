#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "hashtable.h"
#include "con_list.h"
#include "binary_tree.h"

size_t func(const void * const a){
    return (size_t)(*(int*)a);
}

int compare(const void * const x, const void * const y){
    return *(int*)x-*(int*)y;
}

int main(){
    
    const int N = 8;
    int nums[] = {100, 75, 150, 125, 175, 160, 200, 155};

    struct Binary_Node root;
    binary_tree_init(&root);

    for (size_t i = 0; i < N; i++){
        binary_tree_add(&root, &nums[i], compare);
    }
    
   

    printf("%d\n", *(int*)root.right->right->left->key);

  



    
   

    
    
    return 0;

}