#ifndef C_DS_BINARY_TREE_H
#define C_DS_BINARY_TREE_H

#include <stddef.h>
#include <stdbool.h>

struct Binary_Node {
    void * key; // key
    void * value; // value
    struct Binary_Node * left; // left child
    struct Binary_Node * right; // right child
};


/*
 * sets and key and value for the struct Binary_Node where left and right and NULL.
 * k is the key.
 * v is the value.
 * return the struct Binary_Node with key equal to k and value equal to v and both the children pointers equal to NULL.
 */
struct Binary_Node * binary_tree_init_node(void * k, void * v);


/*
 * Adds ele to the map_tree. Nodes are compared by the comparing function passed.
 * tree: is the current tree.
 * ele: node to be added.
 * compare_to: dictates how the nodes are compared.
 * size: number of nodes in the tree map.
 */
void binary_tree_add(struct Binary_Node * tree, struct Binary_Node * ele, int(compare_to)(const void * const x, const void * const y), size_t * size);


/*
 * Deletes a node from the tree.
 * tree: current tree.
 * ele: node to be removed.
 * compare_to: dictates how the values are compared.
 * size: number of nodes in the tree.
 * return: deleted node.
 */
struct Binary_Node * binary_tree_del(struct Binary_Node * tree, struct Binary_Node * ele, int(compare_to)(const void * const x, const void * const y), size_t * size);


/*
 * Returns the node with the smallest value.
 * return: node with the smallest value.
 */
struct Binary_Node * binary_tree_min(struct Binary_Node * tree);


/*
 * Returns the node with the largest value.
 * return: node with the smallest value.
 */
struct Binary_Node * binary_tree_max(struct Binary_Node * tree);


/*
 * return: height of the tree.
 */
size_t binary_tree_height(struct Binary_Node * tree);

struct Binary_Node * binary_tree_update_node(struct Binary_Node * tree, struct Binary_Node * trgt_node, void * new_value, int(compare_to)(const void * const x, const void * const y));

void binary_tree_inorder_traversal(struct Binary_Node * tree);


/*
 * Checks if two map_tree are equal or not.
 */
bool binary_tree_is_equal(struct Binary_Node * a, struct Binary_Node * b, int(compare_to)(void * x, void * y));

// 0 absent
// 1 present
struct Binary_Node * binary_tree_contains(struct Binary_Node * tree, struct Binary_Node ele, int(compare_to)(void * x, void * y));

#endif //C_DS_BINARY_TREE_H
