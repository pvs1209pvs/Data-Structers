#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "con_stack.h"

void stack_con_init(struct Stack * stack_array, size_t capacity) {

    stack_array->head = malloc(capacity*sizeof(void*));
    if(stack_array->head == NULL){
        printf("%s\n", "NOT ENOUGH MEMORY AVAILABLE");
        exit(1);
    }

    stack_array->cpcty = capacity;
    stack_array->size = 0;

} // init

void stack_con_push(struct Stack * stack_array, void * ele) {

    if (stack_array->cpcty == stack_array->size) {
        stack_con_grow(stack_array);
    }

    stack_array->head[stack_array->size] = ele;

    stack_array->size++;

} // push

void * stack_con_pop(struct Stack * stack_array) {
    if (stack_array->size == 0) return NULL;
    return stack_array->head[--(stack_array->size)];
} // pop

size_t stack_con_size(struct Stack * stack_array) {
    return stack_array->size;
} // size

_Bool stack_con_is_empty(struct Stack * stack_array) {
    return stack_con_size(stack_array) == 0;
} // is_empty

void * stack_con_top(struct Stack * stack_array) {
    if (stack_array->size == 0) return NULL;
    return stack_array->head[stack_array->size-1];
} // top

void stack_con_grow(struct Stack * stack_array) {

    stack_array->cpcty = 2*stack_array->cpcty;
    stack_array->head = realloc(stack_array->head, stack_array->cpcty*sizeof(void*));

    if (stack_array->head == NULL) {
        printf("NOT ENOUGH MEMORY TO GROW THE STACK : ABORTING THE PROGRAM");
        exit(1);
    }

} // grow

void stack_con_free(struct Stack * stack){
    free(stack->head);
} // free

void stack_con_print_info(struct Stack stack){
    printf("Cap %zu: ", stack.cpcty);
    printf("Size %zu: \n", stack.size);
} // print_info