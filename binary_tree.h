#ifndef C_DS_BINARY_TREE_H
#define C_DS_BINARY_TREE_H

#include <stddef.h>
#include <stdbool.h>
#include "con_list.h"

struct Binary_Node {
    void * key; // key
    struct Binary_Node * left; // left child
    struct Binary_Node * right; // right child
};


struct Binary_Node * binary_tree_init_node(void * k);

void binary_tree_add(struct Binary_Node * tree, struct Binary_Node * ele, int(compare_to)(const void * const x, const void * const y));

struct Binary_Node * binary_tree_del(struct Binary_Node * tree, struct Binary_Node * ele, int(compare_to)(const void * const x, const void * const y));

struct Binary_Node * binary_tree_min(struct Binary_Node * tree);

struct Binary_Node * binary_tree_max(struct Binary_Node * tree);

size_t binary_tree_height(struct Binary_Node * tree);

struct Binary_Node * binary_tree_update_node(struct Binary_Node * tree, struct Binary_Node * trgt_node, void * new_value, int(compare_to)(const void * const x, const void * const y));

struct Binary_Node * binary_tree_contains(struct Binary_Node * tree, struct Binary_Node ele, int(compare_to)(const void * const x, const void * const y));

struct List binary_tree_ele_array(struct Binary_Node * tree);

bool binary_tree_is_equal(struct Binary_Node * a, struct Binary_Node * b, int(compare_to)(void * x, void * y));

void binary_tree_inorder_traversal(struct Binary_Node * tree, struct List * list);

#endif //C_DS_BINARY_TREE_H
