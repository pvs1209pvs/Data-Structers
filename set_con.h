#ifndef DATA_STRUCTURES_SET_H
#define DATA_STRUCTURES_SET_H

#include <fcntl.h>

struct Set{
    size_t size;    // size of the set
    size_t cpcty;   // current number of elements in the set
    void **head;    // pointer style dynamic head

};

void set_con_init(struct Set * set, size_t cpcty);

void set_con_add(struct Set * set, void *ele, int(*compare_to)(void * x, void * y));

void set_con_dlt_vle(struct Set * set, void * ele, int(*compare_to)(void * x, void * y));

void set_con_dlt_indx(struct Set * set, int index);

struct Set * set_con_union(struct Set * set_one, struct Set * set_two, int(*compare_to)(void * x, void * y));

int set_con_cntns(struct Set * set, void * ele, int(*compare_to)(void * x, void * y));

size_t set_con_size(struct Set * set);

_Bool set_con_is_empty(struct Set * set);

void set_con_grow(struct Set * set);

void set_con_free(struct Set * set);

#endif //DATA_STRUCTURES_SET_H

