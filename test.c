#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "con_stack.h"
#include "link_list.h"

int compare_to(const void * const a, const void * const b){
    return *(int*)a-*(int*)b;
}

int main() {

    struct Link_List list;
    link_list_init(&list);

    int a = 5;
    int b = 10;
    int c = 15;

    link_list_prepend_ele(&list, &a);
    link_list_prepend_ele(&list, &b);
    link_list_prepend_ele(&list, &c);


    for (size_t i = 0; i < 3; i++){
        printf("%d\n", *(int*)link_list_get(&list, i));
    }

    printf("%d\n", *(int*)link_list_get(&list, 10));
    
    

}