#include <malloc.h>
#include "con_list.h"


void con_list_init(struct List *list, size_t cpcty) {
  list->head = malloc(cpcty * sizeof(void*));
  list->cpcty = cpcty;
  list->size = 0;
}


void con_list_add(struct List *list, void *ele) {
  if (list->size == list->cpcty) con_list_grow(list);
  list->head[list->size++] = ele;
  //*(list->head + list->size++) = ele;
}


void con_list_dltIndx(struct List *list, size_t i) {
  free(list->head[i]);
  for (size_t j = i; j < list->size-1; ++j)
      list->head[j] = list->head[j + 1];
  list->head[list->size - 1] = NULL;
  list->size--;
}


void *con_list_get(struct List *list, size_t i) {
  return list->head[i];
}


size_t con_list_size(struct List *list) {
  return list->size;
}


void con_list_clr(struct List *list) {
  for (int i = 0; i < list->size; ++i)
    free(list->head[i]);
  list->cpcty = 10;
  list->size = 0;
}


void con_list_setAt(struct List *list, size_t i, void *ele) {
  list->head[i] = ele;
}


_Bool con_list_cntns(struct List *list, void *ele, int(compareTo)(const void * const x, const void * const y)) {
  for (int i = 0; i < list->size; ++i) {
    if (compareTo(list->head[i], ele) == 0) return 1;
  }
  return 0;
}


_Bool con_list_isEmpty(struct List *list) {
  return list->size == 0;
}


void con_list_grow(struct List *list) {
  list->cpcty = 2 * list->cpcty;
  list->head = realloc(list->head, list->cpcty * sizeof(void*));
}


void con_list_free(struct List *list) {
  free(list->head);
}
