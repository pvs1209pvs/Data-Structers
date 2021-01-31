#include <malloc.h>
#include "con_list.h"


/**
 * Initializes con_list.
 * @param list List that has to be initialized.
 * @param cpty How many elements list can hold.
*/
void con_list_init(struct List *list, const size_t cpcty) {
  list->head = malloc(cpcty * sizeof(void*));
  list->cpcty = cpcty;
  list->size = 0;
}


/**
 * Appends elements at the end of the list.
 * @param list List to which elements will be appended.
 * @param ele Address of the elements that the list will be storing.
*/
void con_list_add(struct List *list, void * const ele) {
  if (list->size == list->cpcty) con_list_grow(list);
  list->head[list->size++] = ele;
}


/**
 * Deletes the element at the valid index.
 * @param list List from whic the element will be deleted.
 * @parem i Index of the element that has to be deleted.
*/
void * con_list_dlt_indx(struct List * const list, const size_t i) {

  void * r = list->head[i];

  for (size_t j = i; j < list->size-1; ++j){
    list->head[j] = list->head[j + 1];
  }

  list->size--;

  return r;

}


/**
 * Returns the element from a valid index.
 * @param list List from which the element has to be returned.
 * @param i Index of the element to be returned.
*/
void *con_list_get(const struct List * const list, const size_t i) {
  return list->head[i];
}


/**
 * Returns the size of the list.
 * @param list List whose size we wish get.
*/
size_t con_list_size(const struct List * const list) {
  return list->size;
}


/**
 * Removes all the elements from the list.
 * @param list List to be cleared.
*/
void con_list_clr(struct List * const list) {

  for (int i = 0; i < list->size; ++i){
    con_list_dlt_indx(list, i);
  }

  list->size = 0;

}


/**
 * Adds the element at the valid index.
 * @param list List in which element is to be added.
 * @param i Index at which the element has to be added.
 * @param ele: ele that is be added at the index i.
*/
void con_list_set_at(const struct List * const list, size_t i, void * const ele) {
  list->head[i] = ele;
}


/**
 * Checks if the list contains the desired element.
 * @param list List in which the presence of the element has to checked.
 * @param ele Element that to be checked for.
 * @param compareTo function poninter that dictates how the elements should be compared.
 * @return 1 is the element is present in the list, else 0.
*/
_Bool con_list_cntns(struct List *list, void *ele, int(compareTo)(const void * const x, const void * const y)) {
  for (int i = 0; i < list->size; ++i) {
    if (compareTo(list->head[i], ele) == 0) return 1;
  }
  return 0;
}


/**
 * Checks if the list is empty.
 * @param list List that has to be checked.
 * @return 1 is the list is empty, else 0.
*/
_Bool con_list_isEmpty(const struct List * const list) {
  return list->size == 0;
}


/**
 * Doubles the capacity of the list once it is full.
 * @param list List whose capacity has to be doubled.
*/
void con_list_grow(struct List *list) {
  list->cpcty = 2 * list->cpcty;
  list->head = realloc(list->head, list->cpcty * sizeof(void*));
}


/**
 * Removes list from the heap.
 * @param list List that needs to be freeed.
*/
void con_list_free(struct List *list) {
  free(list->head);
}
