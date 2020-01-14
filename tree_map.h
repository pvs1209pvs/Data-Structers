#include <stddef.h>
#include <stdbool.h>

struct Node {
    void * key; // key
    void * value; // value
    struct Node * left; // left child
    struct Node * right; // right child
};


/*
 * sets and key and value for the struct Node where left and right and NULL.
 * k is the key.
 * v is the value.
 * return the struct Node with key equal to k and value equal to v and both the children pointers equal to NULL.
 */
struct Node * tree_map_init_node(void * k, void * v);


/*
 * Adds ele to the map_tree. Nodes are compared by the comparing function passed.
 * tree: is the current tree.
 * ele: node to be added.
 * compare_to: dictates how the nodes are compared.
 * size: number of nodes in the tree map.
 */
void tree_map_add(struct Node * tree, struct Node * ele, int(compare_to)(const void * const x, const void * const y), size_t * size);


/*
 * Deletes a node from the tree.
 * tree: current tree.
 * ele: node to be removed.
 * compare_to: dictates how the values are compared.
 * size: number of nodes in the tree.
 * return: deleted node.
 */
struct Node * tree_map_del(struct Node * tree, struct Node * ele, int(compare_to)(const void * const x, const void * const y), size_t * size);


/*
 * Returns the node with the smallest value.
 * return: node with the smallest value.
 */
struct Node * tree_map_min(struct Node * tree);


/*
 * Returns the node with the largest value.
 * return: node with the smallest value.
 */
struct Node * tree_map_max(struct Node * tree);


/*
 * return: height of the tree.
 */
size_t tree_map_height(struct Node * tree);

struct Node * tree_map_update_node(struct Node * tree, struct Node * trgt_node, void * new_value, int(compare_to)(const void * const x, const void * const y));

void tree_map_inorder_traversal(struct Node * tree);


/*
 * Checks if two map_tree are equal or not.
 */
bool tree_map_is_equal(struct Node * a, struct Node * b, int(compare_to)(void * x, void * y));

// 0 absent
// 1 present
struct Node * tree_map_contains(struct Node * tree, struct Node ele, int(compare_to)(void * x, void * y));
