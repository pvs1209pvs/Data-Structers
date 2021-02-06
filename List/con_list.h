#ifndef DATA_STRUCTERS_con_list_H
#define DATA_STRUCTERS_con_list_H

struct List {
    void ** head;
    size_t size;
    size_t cpcty;
};

void con_list_init(struct List *list, const size_t cpcty);

void con_list_add(struct List * list, void * const ele);

void * con_list_dlt_at(struct List * const list, const size_t i);

void * con_list_get(const struct List * const list, const size_t i);

size_t con_list_size(const struct List * const list);

void con_list_clr(struct List * const list);

void * con_list_shrink(struct List * list);

void con_list_set_at(const struct List * const list , size_t i, void * const ele);

_Bool con_list_cntns(struct List * const list, void * const ele, int(compare_to)(const void * const x, const void * const y));

_Bool con_list_is_empty(const struct List * const list);

void con_list_grow(struct List * list);

#endif //DATA_STRUCTERS_con_list_H
