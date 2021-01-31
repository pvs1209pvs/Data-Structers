#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "con_list.h"



int main() {

    struct List myList;
    con_list_init(&myList, 2);

    int a, b, c, d;
    a = 5;
    b = 10;
    c = 15;
    d = 20;

    con_list_add(&myList, &a);
    con_list_add(&myList, &b);
    con_list_add(&myList, &c);
    con_list_add(&myList, &d);

   (con_list_dlt_indx(&myList, 2));

    for (size_t i = 0; i < con_list_size(&myList); i++){
        printf("%d \n", *(int*)con_list_get(&myList, i));
    }

    
    
    free(myList.head);
    
    

}