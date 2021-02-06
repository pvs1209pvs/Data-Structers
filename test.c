#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "con_list.h"

int compare_to(const void * const a, const void * const b){
    return *(int*)a-*(int*)b;
}

int main() {

    int * list = calloc(5, sizeof(int));

    if(list == NULL){
        printf("everything is good\n");
    }
    else{
        printf("Not so good \n");
    }

    // for (size_t i = 0; i < 5; i++){
       
    //     printf("%d\n", list[i]);
    // }
    

    // int nums[5];

    // for (size_t i = 0; i < 5; i++){
    //     nums[i] = (i+1)*10;
    // }
    

    // struct List list;
    // con_list_init(&list, 2);

    // con_list_add(&list, &nums[0]);
    // con_list_add(&list, &nums[1]);
    // con_list_add(&list, &nums[2]);
    // con_list_add(&list, &nums[3]);
    // con_list_add(&list, &nums[4]);

    // for (size_t i = 0; i < con_list_size(&list); i++){
    //     printf("%d\n", *(int*)con_list_get(&list, i));
    // }

    // free(list.head);
    

    

}