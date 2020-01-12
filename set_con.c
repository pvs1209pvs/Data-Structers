#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include "set_con.h"

void set_con_init(struct Set * arraySet, size_t cpcty) {
    arraySet->head = malloc(cpcty*sizeof(void *));
    arraySet->cpcty = cpcty;
    arraySet->size = 0;
}

void set_con_add(struct Set * arraySet, void * ele, int(* compareTo)(const void * const x, const void * const y)) {

    if (arraySet->size == arraySet->cpcty) set_con_grow(arraySet);

    if (arraySet->size == 0) {
        arraySet->head[0] = ele;
        arraySet->size++;
    } else {
        if (set_con_cntns(arraySet, ele, compareTo) != 1) {
            arraySet->head[arraySet->size] = ele;
            arraySet->size++;
        }
    }


}

void set_con_dlt_vle(struct Set * arraySet, void * ele, int(* compareTo)(const void * const x, const void * const y)) {

    int i = 0;

    for (i = 0; i < arraySet->size; ++i) {
        if (compareTo(arraySet->head[i], ele) == 0) {
            arraySet->head[i] = NULL;
            break;
        }
    }

    for (int j = i; i < arraySet->size - 1; ++i)
        arraySet->head[i] = arraySet->head[i + 1];

    arraySet->size--;
}

void set_con_dlt_indx(struct Set * arraySet, int index) {

    //free(arraySet->head[index]);

    for (int i = index; i < set_con_size(arraySet) - 1; ++i) {
        arraySet->head[i] = arraySet->head[i + 1];
    }
    arraySet->head[set_con_size(arraySet) - 1] = NULL;


    arraySet->size--;

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

int set_con_cntns(struct Set * arraySet, void * ele, int(* compareTo)(const void * const x, const void * const y)) {

    _Bool bool = 0;

    for (int i = 0; i < arraySet->size; ++i) {

        if (compareTo(arraySet->head[i], ele) == 0) {
            bool = 1;
            break;
        }

    }

    return bool;

}

size_t set_con_size(struct Set * arraySet) {
    return arraySet->size;
}

_Bool set_isEmpty(struct Set * arrayset) {
    return arrayset->size == 0;
}

void set_con_grow(struct Set * arraySet) {
    arraySet->cpcty = arraySet->cpcty*2;
    arraySet->head = realloc(arraySet->head, arraySet->cpcty*sizeof(void *));
}

void set_con_free(struct Set * set) {
    free(set->head);
}