#ifndef DATA_STRUCTERS_con_list_H
#define DATA_STRUCTERS_con_list_H

struct List {
    size_t size;
    size_t cpcty;
    void ** head;
};

void con_list_init(struct List * list, size_t cpcty);

void con_list_add(struct List * list, void * ele);

void con_list_dltIndx(struct List * list, size_t i);

void * con_list_get(struct List * list, size_t i);

size_t con_list_size(struct List * list);

void con_list_clr(struct List * list);

void con_list_setAt(struct List * list , size_t i, void * ele);

_Bool con_list_cntns(struct List * list, void * ele, int(compareTo)(const void * const x, const void * const y));

_Bool con_list_is_empty(struct List * list);

void con_list_grow(struct List * list);

void con_list_free(struct List * list);

#endif //DATA_STRUCTERS_con_list_H
