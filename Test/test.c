#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<time.h>
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
    
    srand(time(0));

    const long N = 1000000;

    int num[N];
    for (long i = 0; i < N; i++){
        num[i] = rand()%10000;
    }

    struct List list;
    con_list_init(&list, 10);

    for (size_t i = 0; i < N; i++){
        con_list_add(&list, &num[i]);
    }

    printf("%d\n", con_list_cntns(&list, &num[1000000/2], compare));


    // struct Binary_Node tree;
    // binary_tree_init(&tree);

    // for (size_t i = 0; i < N; i++){
    //     binary_tree_add(&tree, &num[i], compare);
    // }

    // struct Binary_Node ele;
    // binary_tree_init(&ele);
    // ele.key = &num[1000000/2];
    // printf("%d\n", *(int*)binary_tree_contains(&tree, ele, compare)->key);

    
    
    
    return 0;

}