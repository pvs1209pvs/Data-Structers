#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include "con_set.h"

void set_con_init(struct Set * array_set, const size_t cpcty) {

    array_set->head = malloc(cpcty*sizeof(void *));

    array_set->cpcty = cpcty;
    array_set->size = 0;
    
}

void set_con_add(struct Set * array_set, void * const ele, int(* compare_to)(const void * const x, const void * const y)) {

    if (array_set->size == array_set->cpcty) {
        set_con_grow(array_set);
    }

    if (array_set->size == 0) {
        array_set->head[0] = ele;
        array_set->size++;
    } else {
        if (set_con_cntns(array_set, ele, compare_to) != 1) {
            array_set->head[array_set->size] = ele;
            array_set->size++;
        }
    }

}

void set_con_dlt_vle(struct Set * array_set, void * ele, int(* compareTo)(const void * const x, const void * const y)) {

    int i = 0;

    for (i = 0; i < array_set->size; ++i) {
        if (compareTo(array_set->head[i], ele) == 0) {
            array_set->head[i] = NULL;
            break;
        }
    }

    for (int j = i; i < array_set->size - 1; ++i)
        array_set->head[i] = array_set->head[i + 1];

    array_set->size--;
}

void set_con_dlt_indx(struct Set * array_set, int index) {

    //free(array_set->head[index]);

    for (int i = index; i < set_con_size(array_set) - 1; ++i) {
        array_set->head[i] = array_set->head[i + 1];
    }
    array_set->head[set_con_size(array_set) - 1] = NULL;


    array_set->size--;

}

struct Set * set_con_union(struct Set * set_one, struct Set * set_two, int(* compare_to)(const void * const x, const void * const y)) {

    struct Set * union_set = malloc(sizeof(struct Set));
    set_con_init(union_set, set_one->size > set_two->size ? set_one->size : set_two->size);


    for (int i = 0; i < set_one->size; ++i) {
        set_con_add(union_set, set_one->head[i], compare_to);
    }

    for (int i = 0; i < set_two->size; ++i) {
        set_con_add(union_set, set_two->head[i], compare_to);
    }

    return union_set;

}

int set_con_cntns(struct Set * array_set, void * ele, int(* compareTo)(const void * const x, const void * const y)) {

    _Bool bool = 0;

    for (int i = 0; i < array_set->size; ++i) {
        if (compareTo(array_set->head[i], ele) == 0) {
            bool = 1;
            break;
        }
    }

    return bool;

}

size_t set_con_size(struct Set * array_set) {
    return array_set->size;
}

_Bool set_isEmpty(struct Set * arrayset) {
    return arrayset->size == 0;
}

void set_con_grow(struct Set * array_set) {
    array_set->cpcty = array_set->cpcty*2;
    array_set->head = realloc(array_set->head, array_set->cpcty*sizeof(void *));
}

void set_con_free(struct Set * set) {
    free(set->head);
}