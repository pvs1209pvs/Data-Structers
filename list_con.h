#ifndef DATA_STRUCTERS_con_list_H
#define DATA_STRUCTERS_con_list_H

typedef struct {
    size_t size;
    size_t typSze;
    size_t cpcty;
    void* *head;
} con_list;

void con_list_init(con_list *, size_t, size_t);

void con_list_add(con_list *, void *);

void con_list_dltIndx(con_list *, size_t);

void *con_list_get(con_list *, size_t);

size_t con_list_size(con_list *);

void con_list_clr(con_list *);

void con_list_setAt(con_list *, size_t, void *);

_Bool con_list_cntns(con_list *, void *ele, int(compareTo)(void *, void *));

_Bool con_list_isEmpty(con_list *);

void con_list_grow(con_list *);

void con_list_free(con_list *);

#endif //DATA_STRUCTERS_con_list_H
