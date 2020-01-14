#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree_map.h"

//int compare(const void * const x, const void * const y) {
//    struct Person p_one, p_two;
//
//    p_one = *(struct Person *) x;
//    p_two = *(struct Person *) y;
//
//    return (strcmp(p_one.name, p_two.name)) + (p_one.age - p_two.age) + (int) (p_one.height - p_two.height);
//
//}

int compare(const void * const x, const void * const y) {
    return *(int *) x - *(int *) y;
}

int main() {

    int keys[] = {12, 1, 9, 2, 5, 6, 10, 13, 14, 8};

    /*                   An effort was made
     *                          12
     *                         /  \
     *                        1    13
     *                         \     \
     *                          9     14
     *                         / \
     *                        2  10
     *                         \
     *                          5
     *                           \
     *                            6
     *                             \
     *                              8
     *
     */


    int values[sizeof(keys)/sizeof(keys[0])];
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); ++i) {
        values[i] = keys[i]*10;
    }

    struct Node nodes[sizeof(keys)/sizeof(keys[0])];
    for (int j = 0; j < sizeof(nodes)/sizeof(nodes[0]); ++j) {
        nodes[j] = *map_tree_init_node(&keys[j], &values[j]);
    }

    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i)
        printf("%d,\t", keys[i]);
    printf("\n");
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i)
        printf("%d,", values[i]);
    printf("\n");

    struct Node tree;
    size_t size = 0;


    for (int k = 0; k < 10; ++k) {
        map_tree_add(&tree, &nodes[k], compare, &size);
    }

    map_tree_del(&tree, &nodes[7], compare, &size);
    //printf("%d\n", *(int *) tree.left->right->left->right->right->right->value);
    printf("%d\n", *(int *) tree.right->key);
}