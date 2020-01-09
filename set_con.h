#ifndef DATA_STRUCTURES_SET_H
#define DATA_STRUCTURES_SET_H

#include <fcntl.h>

typedef struct {
    size_t size;    // size of the set
    size_t cpcty;   // current number of elements in the set
    size_t typSze;  // size of the elements to be stored in the set
    void **head;    // pointer style dynamic head

} set;

void set_new(set *, size_t, size_t);

void set_add(set *, void *ele, int(*compareTo)(void *, void *));

void set_dltVle(set *, void *, int(*fctPtr)(void *, void *));

void set_dltIndx(set *, int index);

void set_union(set *, set *, int(*compareTo)(void *, void *));

_Bool set_cntns(set *, void *, int(*compareTo)(void *, void *));

size_t set_getSize(set *);

_Bool set_isEmpty(set *);

void set_grow_by(set *, size_t);

#endif //DATA_STRUCTURES_SET_H

