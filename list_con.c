#include <malloc.h>
#include "list_con.h"

/*
Initializes con_list.
list: list that has to be initialized.
typSze: size of the elements this list will be storing.
cpty: how many elements list can hold.
*/
void con_list_init(struct List *list, size_t cpcty) {
  list->head = malloc(cpcty * sizeof(void*));
  list->cpcty = cpcty;
  list->size = 0;
}

/*
Appends elements at the end of the list.
list: list to which elements will be appended.
ele: address of the elements that the list will be storing.
*/
void con_list_add(struct List *list, void *ele) {
  if (list->size == list->cpcty) con_list_grow(list);
  *(list->head + list->size++) = ele;
}

/*
Deletes the element at the valid index.
list: list from whic the element will be deleted.
i: index of the element that has to be deleted.
*/
void con_list_dltIndx(struct List *list, size_t i) {
  free(list->head[i]);
  for (size_t j = i; j < list->size-1; ++j)
      list->head[j] = list->head[j + 1];
  list->head[list->size - 1] = NULL;
  list->size--;
}

/*
Returns the element from a valid index.
list: list from which the element has to be returned.
i: index of the element to be returned.
*/
void *con_list_get(struct List *list, size_t i) {
  return list->head[i];
}

/*
Returns the size of the list.
list: list whose size we wish get.
*/
size_t con_list_size(struct List *list) {
  return list->size;
}

/*
Removes all the elements from the list.
list: list to be cleared.
*/
void con_list_clr(struct List *list) {
  for (int i = 0; i < list->size; ++i)
    free(list->head[i]);
  list->cpcty = 10;
  list->size = 0;
}

/*
Adds the element at the valid index.
list: list in which element is to be added.
i: index at which the element has to be added.
ele: ele that is be added at the index i.
*/
void con_list_setAt(struct List *list, size_t i, void *ele) {
  list->head[i] = ele;
}

/*
Checks if the list contains the desired element.
list: list in which the presence of the element has to checked.
ele: element that to be checked for.
compareTo: function poninter that dictates how the elements should be compared.
return value: 1 is the element is present in the list, else 0.
*/
_Bool con_list_cntns(struct List *list, void *ele, int(compareTo)(const void * const x, const void * const y)) {
  for (int i = 0; i < list->size; ++i) {
    if (compareTo(list->head[i], ele) == 0) return 1;
  }
  return 0;
}

/*
Checks if the list is empty.
list: list that has to be checked.
return value: 1 is the list is empty, else 0.
*/
_Bool con_list_isEmpty(struct List *list) {
  return list->size == 0;
}

/*
Doubles the capacity of the list once it is full.
list: list whose capacity has to be doubled.
*/
void con_list_grow(struct List *list) {
  list->cpcty = 2 * list->cpcty;
  list->head = realloc(list->head, list->cpcty * sizeof(void*));
}

/*
Removes list from the heap.
list: list that needs to be freeed.
*/
void con_list_free(struct List *list) {
  free(list->head);
}
