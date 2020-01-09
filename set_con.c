#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include "set.h"

void set_new(set *arraySet, size_t cpcty, size_t typSze) {
    arraySet->head = calloc(cpcty, typSze * 2);
    arraySet->typSze = typSze * 2;
    arraySet->cpcty = cpcty;
    arraySet->size = 0;
}

void set_add(set *arraySet, void *ele, int(*compareTo)(void *, void *)) {

    if (arraySet->size == arraySet->cpcty) set_grow_by(arraySet, 2);

    if (arraySet->size == 0) {
        arraySet->head[0] = ele;
        arraySet->size++;
    } else {
        if (!set_cntns(arraySet, ele, compareTo)) {
            arraySet->head[arraySet->size] = ele;
            arraySet->size++;
        }
    }


}

void set_dltVle(set *arraySet, void* ele, int(*compareTo)(void *, void *)) {

    int i = 0;

    for (i = 0; i < arraySet->size; ++i) {
        printf("%i  %i \n", *(int*)ele, *(int*)arraySet->head[i]);
        if (compareTo(arraySet->head[i], ele) == 0) {
            arraySet->head[i] = NULL;
            arraySet->size--;
            break;
        }
    }

/*    for (int j = i; i < arraySet->size - 1; ++i)
        arraySet->head[i] = arraySet->head[i + 1];*/
}

void set_dltIndx(set *arraySet, int index) {
    arraySet->head[index] = NULL;
    arraySet->size--;
}

void set_union(set *setOne, set *setTwo, int(*compareTo)(void *, void *)) {

    for (int i = 0; i < setTwo->size; ++i) {
        set_add(setOne, setTwo->head[i], compareTo);
    }
}

_Bool set_cntns(set *arraySet, void *ele, int(*compareTo)(void *, void *)) {

    _Bool bool = 0;

    for (int i = 0; i < arraySet->size; ++i) {

        void *a = arraySet->head[i];
        void *b = ele;

        if (compareTo(&a, &b) == 0) {
            bool = 1;
            break;
        }

    }

    return bool;

}

size_t set_getSize(set *arraySet) {
    return arraySet->size;
}

_Bool set_isEmpty(set *arrayset) {
    return arrayset->size == 0;
}

void set_grow_by(set *arraySet, size_t by) {
    arraySet->cpcty = by * arraySet->cpcty;
    void **dummy = realloc(arraySet->head, arraySet->cpcty * arraySet->typSze);
    arraySet->head = dummy;
    dummy = NULL;
    free(dummy);
}

