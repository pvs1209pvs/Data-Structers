#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree_priority_queue.h"


int compare(const void * const x, const void * const y) {
    return *(int *) x - *(int *) y;
}

int main() {

    int keys[10];
    int values[10];

    for (int i = 0; i < 10; ++i) {
        keys[i] = i;
        values[i] = i*10;
    }

    struct Priority_Queue myPQ;
    tree_priority_queue_init(&myPQ);

    tree_priority_queue_add(&myPQ, &values[7], compare);
    tree_priority_queue_add(&myPQ, &values[2], compare);
    tree_priority_queue_add(&myPQ, &values[1], compare);
    tree_priority_queue_add(&myPQ, &values[3], compare);
    tree_priority_queue_add(&myPQ, &values[5], compare);

    tree_priority_queue_remove(&myPQ, &values[5], compare);

    for (int j = 0; j < 5; ++j) {

//        printf("%d \n", *(int*)a[j]);
    }



//    printf("%d \n", *(int*)tree_priority_queue_peek(&myPQ));


//    struct Binary_Node root;
//
//    tree_map_add(&root, &nodes[6], compare, &size);
//    tree_map_add(&root, &nodes[2], compare, &size);
//    tree_map_add(&root, &nodes[1], compare, &size);
//    tree_map_add(&root, &nodes[3], compare, &size);
//    tree_map_add(&root, &nodes[5], compare, &size);
//    tree_map_add(&root, &nodes[7], compare, &size);
//    tree_map_add(&root, &nodes[0], compare, &size);
//    tree_map_add(&root, &nodes[8], compare, &size);
//    tree_map_add(&root, &nodes[4], compare, &size);



//    int nums[10];
//    struct PQ_Node nodes[10];
//
//    for (int i = 0; i < 10; ++i) {
//        nums[i] = i*10;
//        nodes[i] = (struct PQ_Node) {&nums[i], i};
//    }
//
//    for (int j = 0; j < 10; ++j) {
//        printf("%d %d \n", nodes[j].prio, *(int *) nodes[j].ele);
//    }
//
//    printf("\nTesting \n");
//
//    struct Priority_Queue pq;
//
//    prio_queue_init(&pq, 2);
//
//    prio_queue_add(&pq, &nodes[2]);
//    prio_queue_add(&pq, &nodes[1]);
//    prio_queue_add(&pq, &nodes[7]);
//    prio_queue_add(&pq, &nodes[6]);
//    prio_queue_add(&pq, &nodes[4]);
//    prio_queue_add(&pq, &nodes[5]);
//    prio_queue_add(&pq, &nodes[3]);
//
//    printf("Debug %zu %zu \n", pq.size, pq.cpcty);
//
//    for (int k = 0; k < pq.size; ++k) {
//        printf("%d %d\n", pq.queue[k]->prio, *(int *) pq.queue[k]->ele);
//    }


}