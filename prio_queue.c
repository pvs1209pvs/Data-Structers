#include <stdlib.h>
#include <stdio.h>
#include "prio_queue.h"

void prio_queue_new(struct prio_queue * my_queue, size_t typ_size, size_t cpcty) {
  my_queue->size = 0;
  my_queue->typ_size = typ_size*2;
  my_queue->cpcty = cpcty;
  my_queue->queue = calloc(my_queue->cpcty, my_queue->typ_size);
}

void prio_queue_add(struct prio_queue * my_queue, struct node * ele) {

  if(my_queue->size == my_queue->cpcty) prio_queue_grow(my_queue);

  if(my_queue->size == 0) {
    my_queue->queue[my_queue->size] = *ele;
  }
  else {

    size_t i = 0;
    for (; i < my_queue->size; i++) {
      if(ele->prio < my_queue->queue[i].prio) {
        break;
      }
    }

    for (size_t j = my_queue->size-1; j >= i; j--)
      my_queue->queue[j+1] = my_queue->queue[j];


    my_queue->queue[i] = *ele;

  }

  my_queue->size++;

}

struct node * prio_queue_del(struct prio_queue * my_queue) {
  return &my_queue->queue[--my_queue->size];
}

void prio_queue_grow(struct prio_queue * my_queue) {
  my_queue->cpcty = my_queue->cpcty*2;
  my_queue->queue = realloc(my_queue->queue, my_queue->cpcty);
}

void prio_queue_free(struct prio_queue * my_queue) {
  free(my_queue);
}
