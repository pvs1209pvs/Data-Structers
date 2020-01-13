#ifndef DATA_STRUCTERS_STACK_H
#define DATA_STRUCTERS_STACK_H

struct Stack {
    size_t cpcty;
    size_t size;
    void ** head;
};

void stack_con_init(struct Stack * stack, size_t capacity);

void stack_con_push(struct Stack * stack, void * ele);

void * stack_con_pop(struct Stack * stack);

size_t stack_con_size(struct Stack * stack);

_Bool stack_con_is_empty(struct Stack * stack);

void * stack_con_top(struct Stack * stack);

void stack_con_grow(struct Stack * stack);

void stack_stack_free(struct Stack * stack);

void stack_con_print_info(struct Stack stack);

#endif //DATA_STRUCTERS_STACK_H