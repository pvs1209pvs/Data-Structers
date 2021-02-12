#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"

size_t func(const void * const a){
    return (size_t)(*(int*)a);
}

int compare(const void * const x, const void * const y){
    return *(int*)x-*(int*)y;
}

int main(){

    int num[7] = {10, 20, 30, 40, 50, 60, 70};

    struct Hash_Table table;
    hash_table_init(&table, 6);

    for (size_t i = 0; i < 7; i++){
       hash_table_insert(&table, &num[i], func);
    } 
  
    for (size_t i = 0; i < table.cpcty; i++){
        if(table.arr[i] != NULL){
            printf("%d\n", *(int*)table.arr[i]);
        }
        else{
            printf(".\n");
        }
    }

    for (size_t i = 0; i < 7; i++){
        int * a = (int*)hash_table_remove(&table, &num[i], func, compare);
        printf("returned %d \n", *a);
        free(a);
    }
    

    free(table.arr);
    
    

    return 0;

}

// 30
// 60
// 20
// 50
// 10
// 40
