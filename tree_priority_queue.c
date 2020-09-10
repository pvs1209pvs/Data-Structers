#include "tree_priority_queue.h"
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void tree_priority_queue_init(struct Priority_Queue * priority_queue) {
    priority_queue->p_queue = (struct Binary_Node) {0};
    priority_queue->size = 0;
}

void tree_priority_queue_add(struct Priority_Queue * priority_queue, void * ele,
                             int(compare)(const void * const x, const void * const y)) {

    binary_tree_add(&priority_queue->p_queue, binary_tree_init_node(ele, ele), compare);

}

void tree_priority_queue_remove(struct Priority_Queue * priority_queue, void * ele,
                                int(compare)(const void * const x, const void * const y)) {
    struct Binary_Node * bn = binary_tree_init_node(ele, ele);
    binary_tree_del(&priority_queue->p_queue, bn, compare);
    free(bn);
}

void * tree_priority_queue_peek(struct Priority_Queue * priority_queue) {
    return priority_queue->p_queue.key;
}

void tree_priority_queue_print(struct Priority_Queue priority_queue) {
    struct Binary_Node bn = priority_queue.p_queue;
    binary_tree_inorder_traversal(&bn);
}