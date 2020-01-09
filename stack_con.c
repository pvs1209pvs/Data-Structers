#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_new(stack *arraystack, size_t capacity, size_t typeSize) {
    arraystack->head = (void **) calloc(capacity, typeSize * 2);
    if (arraystack->head == NULL) {
        printf("NOT ENOUGH MEMORY FOR STACK : ABORTING THE PROGRAM");
        exit(1);
    }
    arraystack->cpcty = capacity;
    arraystack->typeSize = typeSize * 2;
    arraystack->size = 0;
}

void stack_push(stack *arraystack, void *ele) {
    if (arraystack->cpcty == arraystack->size)
        grow(arraystack);
    *(arraystack->head + arraystack->size) = ele;
    arraystack->size++;
}

void *stack_pop(stack *arraystack) {
    if (arraystack->size == 0) return NULL;
    return arraystack->head[--(arraystack->size)];
}

size_t stack_getSize(stack *arrayStack) {
    return arrayStack->size;
}

_Bool stack_isEmpty(stack *arrayStack) {
    return stack_getSize(arrayStack) == 0;
}

void *stack_top(stack *arrayStack) {
    if (arrayStack->size == 0) return NULL;
    size_t index = arrayStack->size - 1;
    return arrayStack->head[index];
}

void grow(stack *arraystack) {
    arraystack->cpcty = 2 * arraystack->cpcty;
    void **dummy = (void **) realloc(arraystack->head, arraystack->cpcty * arraystack->typeSize);
    if (dummy == NULL) {
        printf("NOT ENOUGH MEMORY TO GROW THE STACK : ABORTING THE PROGRAM");
        exit(1);
    }
    arraystack->head = dummy;
    dummy = NULL;
}