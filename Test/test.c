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

    

    

}