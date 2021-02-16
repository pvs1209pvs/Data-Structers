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
    
    int nums[5] = {20, 40, 10, 50 ,30};
    int cools[5] = {100, 200, 300, 400, 500};

    struct Hash_Table table;
    hash_table_init(&table, 4);

    for (size_t i = 0; i < 5; i++){
        hash_table_insert(&table, &nums[i], &cools[i], func);
    }

    printf("----\n\n");


    for (size_t i = 0; i < table.cpcty; i++){
        if(hash_table_is_blank(&table, i)){
            printf(".\n");
        }
        else{
            printf("%d %d \n", *(int*)table.arr[i].key, *(int*)table.arr[i].value);
        }
    }

    printf("%zu %zu \n", table.size, table.cpcty);
   
    


    
    
    return 0;

}