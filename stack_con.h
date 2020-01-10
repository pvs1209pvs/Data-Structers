#ifndef DATA_STRUCTERS_STACK_H
#define DATA_STRUCTERS_STACK_H

struct Stack {
    size_t cpcty;
    size_t size;
    void ** head;
};

void stack_init(struct Stack * stack, size_t capacity);

void stack_push(struct Stack * stack, void * ele);

void * stack_pop(struct Stack * stack);

size_t stack_size(struct Stack * stack);

_Bool stack_is_empty(struct Stack * stack);

void * stack_top(struct Stack * stack);

void grow(struct Stack * stack);

void stack_free(struct Stack * stack);

void stack_print_info(struct Stack stack);

#endif //DATA_STRUCTERS_STACK_H