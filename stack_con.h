#ifndef DATA_STRUCTERS_STACK_H
#define DATA_STRUCTERS_STACK_H

#include <fcntl.h>

typedef struct {
    size_t cpcty;
    size_t size;
    size_t typeSize;
    void **head;
} stack;

void stack_new(stack *, size_t, size_t);

void stack_push(stack *, void *);

void *stack_pop(stack *);

size_t stack_getSize(stack *);

_Bool stack_isEmpty(stack *);

void *stack_top(stack *);

void grow(stack *);

#endif //DATA_STRUCTERS_STACK_H