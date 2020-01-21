//#include <stdlib.h>
//#include <stdio.h>
//#include <zconf.h>
//#include "prio_queue.h"
//
//void prio_queue_init(struct Priority_Queue * my_queue, size_t cpcty) {
//    my_queue->size = 0;
//    my_queue->cpcty = cpcty;
//    my_queue->queue = malloc(sizeof(struct PQ_Node *)*my_queue->cpcty);
//}
//
//void prio_queue_add(struct Priority_Queue * my_queue, struct PQ_Node * ele) {
//
//    if (my_queue->size == my_queue->cpcty) prio_queue_grow(my_queue);
//
//    if (my_queue->size == 0) {
//        my_queue->queue[my_queue->size] = ele;
//    } else {
//
//        int i = 0;
//        while (1) {
//            if (i >= my_queue->size || my_queue->queue[i]->prio > ele->prio) break;
//            else i++;
//        }
//
//        for (int j = my_queue->size - 1; j >= i; j--) {
//            my_queue->queue[j + 1] = my_queue->queue[j];
//        }
//
//        my_queue->queue[i] = ele;
//
//    }
//
//    my_queue->size++;
//
//}
//
//struct PQ_Node * prio_queue_del(struct Priority_Queue * my_queue, struct PQ_Node value, int(compare)(struct PQ_Node a, struct PQ_Node b)) {
//    struct PQ_Node * return_value = my_queue->queue[my_queue->size];
//}
//
//void prio_queue_grow(struct Priority_Queue * my_queue) {
//
//    my_queue->cpcty = my_queue->cpcty*2;
//    my_queue->queue = realloc(my_queue->queue, sizeof(struct PQ_Node *)*my_queue->cpcty);
//
//    if (my_queue->queue == NULL) {
//        printf("NOT ENOUGH MEMORY FOR ALLOCATION");
//        exit(1);
//    }
//
//}
//
//void prio_queue_free(struct Priority_Queue * my_queue) {
//    free(my_queue);
//}
