#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Sets and key and value for the struct Binary_Node where left and right and NULL.
 * @param k is the key.
 * @return the struct Binary_Node with key equal to k and value equal to v and both the children pointers equal to NULL.
 */
struct Binary_Node * binary_tree_init_node(void * k) {

    struct Binary_Node * result = malloc(sizeof(struct Binary_Node));
    
    result->key = k;
    result->left = NULL;
    result->right = NULL;
    
    return result;

} 


/**
 * Adds ele to the binary tree.
 * @param tree Is the current tree.
 * @param ele Node to be added.
 * @param compare_to Dictates how the nodes are compared.
 */
void binary_tree_add(struct Binary_Node * tree, struct Binary_Node * ele, int(compare_to(const void * const x, const void * const y))) {

    if (tree == NULL) { // tree is empty
        printf("Error: Root node cannot be NULL. Give it a value key-value values before adding elements to the binary tree.");
        exit(1);
    } else {

        if (compare_to(ele->key, tree->key) < 0) { // ele < tree
            if (tree->left == NULL) {
                tree->left = ele;
            } 
            else {
                binary_tree_add(tree->left, ele, compare_to);
            }
        } 
        else if (compare_to(ele->key, tree->key) > 0) { // ele > tree
            if (tree->right == NULL) {
                tree->right = ele;
            } 
            else {
                binary_tree_add(tree->right, ele, compare_to);
            }
        } else { // ele == tree
            return;
        }

    }

}

/**
 * Deletes the node from the tree.
 * @param tree Current tree.
 * @param ele Node to be removed.
 * @param compare_to Dictates how the values are compared.
 * @return Modified tree.
 */
static struct Binary_Node * binary_tree_del_node(struct Binary_Node * tree, struct Binary_Node * ele, int(compareTo)(const void * const x, const void * const y)) {

    if(tree == NULL){
        return NULL;
    }

    if (compareTo(ele->key, tree->key) < 0) {
        tree->left = binary_tree_del_node(tree->left, ele, compareTo);
    } 
    else if (compareTo(ele->key, tree->key) > 0 ) {
        tree->right = binary_tree_del_node(tree->right, ele, compareTo);
    }
    else{

        if (tree->left == NULL) { 
            return tree->right;
        } 
        else if (tree->right == NULL) {
            return tree->left;
        } 
        else{

            struct Binary_Node * replacement = binary_tree_min(tree->right);

            tree->key = replacement->key;

            tree->right = binary_tree_del_node(tree->right, replacement, compareTo);

        }

    }

    return tree;

} 


/**
 * Deletes a node from the tree.
 * @param tree Current tree.
 * @param ele Node to be removed.
 * @param compare_to Dictates how the values are compared.
 */
void binary_tree_del(struct Binary_Node * tree, struct Binary_Node * ele, int(compare_to)(const void * const x, const void * const y)){
    tree = binary_tree_del_node(tree, ele, compare_to);
}


/**
 * Finds the node with the smallest value.
 * @param tree Current tree.
 * @return Node with the smallest value.
 */
struct Binary_Node * binary_tree_min(struct Binary_Node * tree) {
    if (tree->left != NULL) binary_tree_min(tree->left);
    else return tree;
} 


/**
 * Finds the node with the largest value.
 * @param tree Current tree.
 * @return Node with the largest value.
 */
struct Binary_Node * binary_tree_max(struct Binary_Node * tree) {
    if (tree->right != NULL) binary_tree_max(tree->right);
    else return tree;
} 


/**
 * Checks presence of the element.
 * @param tree Current tree.
 * @param ele Element to be searched for. 
 * @param compare_to Dictates how the values are compared.  
 * @return 
 */
struct Binary_Node * binary_tree_contains(struct Binary_Node * tree, struct Binary_Node ele, int(compareTo(const void * const x, const void * const y))) {

    if (compareTo(ele.key, tree->key) < 0 && tree->left != NULL) {
        binary_tree_contains(tree->left, ele, compareTo);
    }
    else if (compareTo(ele.key, tree->key) > 0 && tree->right != NULL) {
        binary_tree_contains(tree->right, ele, compareTo);
    }
    else if (compareTo(ele.key, tree->key) == 0) {
        return tree;
    }

} 


/**
 * Height of the tree.
 * @param tree Current tree.
 * @return Height of the tree.
 */
size_t binary_tree_height(struct Binary_Node * tree) {

    size_t leftHght, rightHght;
    leftHght = rightHght = 0;

    if (tree->left != NULL) leftHght += binary_tree_height(tree->left) + 1;
    if (tree->right != NULL) rightHght += binary_tree_height(tree->right) + 1;

    return leftHght > rightHght ? leftHght : rightHght;

} 


/**
 * Updates the node in the tree.
 * @param tree Current Tree.
 * @param trgt_node Node to be modified.
 * @param new_value New value.
 */ 
void binary_tree_update_node(struct Binary_Node * tree, struct Binary_Node * trgt_node, void * new_value, int(compare_to)(const void * const x, const void * const y)) {

    if (compare_to(tree->key, trgt_node->key) == 0) {
        tree->key = new_value;
    }

    if (tree->left != NULL){
        binary_tree_update_node(tree->left, trgt_node, new_value, compare_to);
    }
    
    if (tree->right != NULL){
        binary_tree_update_node(tree->right, trgt_node, new_value, compare_to);
    }    

}


/**
 * Performs inorder traversal.
 * @param tree Current tree.
 */
void binary_tree_inorder_traversal(struct Binary_Node * tree) {

    if (tree->left != NULL){
        binary_tree_inorder_traversal(tree->left);
    }

    //printf("%d\n", *(int*)tree->key);

    if (tree->right != NULL){
        binary_tree_inorder_traversal(tree->right);
    }

}


/**
 * Checks if two map_tree are equal or not.
 * @param a First tree.
 * @param b Second tree.
 * @param compare_to Dictates how the values are compared.  
 * @return True if the trees are equal else false.
 */
bool binary_tree_is_equal(struct Binary_Node * a, struct Binary_Node * b, int(compareTo)(void * x, void * y)) {

    if (a->left == NULL ^ b->left == NULL || a->right == NULL ^ b->right == NULL) return false;

    if (compareTo(a->key, b->key) != 0) return false;

    binary_tree_is_equal(a->left, b->left, compareTo);
    binary_tree_is_equal(a->right, b->right, compareTo);

    return true;

} 