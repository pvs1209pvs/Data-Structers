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
    struct Binary_Node nodes[N];

    for (size_t i = 1; i < N; i++){
        nodes[i] = *binary_tree_init_node(&nums[i]);
    }
    
    struct Binary_Node * root = binary_tree_init_node(&nums[0]);

    for (size_t i = 1; i < N; i++){
        binary_tree_add(root, &nodes[i], compare);
    }


    printf("%d\n", binary_tree_height(root));




    
   

    
    
    return 0;

}