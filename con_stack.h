#ifndef DATA_STRUCTERS_STACK_H
#define DATA_STRUCTERS_STACK_H

struct Stack {
    void* * head;
    size_t cpcty;
    size_t size;
};

void stack_con_init(struct Stack * stack, size_t capacity);

void stack_con_push(struct Stack * const stack, void * ele);

void * stack_con_pop(struct Stack * const stack);

size_t stack_con_size(const struct Stack * const stack);

_Bool stack_con_is_empty(const struct Stack * const stack);

void * stack_con_top(struct Stack * stack);

void stack_con_grow(struct Stack * stack);

void stack_stack_free(struct Stack * stack);

#endif //DATA_STRUCTERS_STACK_H