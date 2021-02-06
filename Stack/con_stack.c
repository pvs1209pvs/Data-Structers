#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "con_stack.h"

/**
 * @param stack_array
 * @param capacity
 */
void stack_con_init(struct Stack * const stack_array, const size_t capacity) {

    stack_array->head = malloc(capacity*sizeof(void*));

    if(stack_array->head == NULL){
        printf("Init failed.\n");
        exit(1);
    }

    stack_array->cpcty = capacity;
    stack_array->size = 0;

} 

/**
 * @param stack_array
 * @param ele
 */
void stack_con_push(struct Stack * const stack_array, void * const ele) {

    if (stack_array->cpcty == stack_array->size) {
        stack_con_grow(stack_array);
    }

    stack_array->head[stack_array->size] = ele;

    stack_array->size++;

} 

/**
 * @param stack_array
 * @return 
 */
void * stack_con_pop(struct Stack * const stack_array) {
    return stack_con_is_empty(stack_array) ? NULL : stack_array->head[--(stack_array->size)];
} 

/**
 * @param stack_array
 * @return 
 */
size_t stack_con_size(const struct Stack * const stack_array) {
    return stack_array->size;
}

/**
 * @param stack_array
 * @return
 */
_Bool stack_con_is_empty(const struct Stack * const stack_array) {
    return stack_con_size(stack_array) == 0;
} 

/**
 * @param stack_array
 * @return 
 */
void * stack_con_top(struct Stack * const stack_array) {
    return stack_con_is_empty(stack_array) ? NULL : stack_array->head[stack_array->size-1];
} 

/**
 * @param stack_array
 */
void stack_con_grow(struct Stack * stack_array) {

    stack_array->cpcty *= 2;
    stack_array->head = realloc(stack_array->head, stack_array->cpcty*sizeof(void*));

    if (stack_array->head == NULL) {
        printf("Stack grow failed.\n");
        exit(1);
    }

} 
