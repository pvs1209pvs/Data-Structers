#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "con_stack.h"

int main() {

    struct Stack my_stack;
    stack_con_init(&my_stack, 2);

    int a, b, c, d;
    a = 5;
    b = 10;
    c = 15;
    d = 20;

    
    
    stack_con_push(&my_stack, &a);
    // stack_con_push(&my_stack, &b);
    // stack_con_push(&my_stack, &c);
    // stack_con_push(&my_stack, &d);

    printf("%d \n", NULL==stack_con_pop(&my_stack));
 
    // for (size_t i = 0; i < ; i++){
    //     printf("%d \n", *(int*)stack_con_pop(&my_stack));
    // }
    
    
    

}