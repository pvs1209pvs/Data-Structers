#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Binary_Node * binary_tree_init_node(void * k, void * v) {

    struct Binary_Node * result = malloc(sizeof(struct Binary_Node));
    result->key = k;
    result->value = v;
    result->left = NULL;
    result->right = NULL;
    return result;

} // init_node

void binary_tree_add(struct Binary_Node * tree, struct Binary_Node * ele,
                     int(compare_to(const void * const x, const void * const y)), size_t * size) {

    if (*size == 0) { // tree is empty
        *tree = *ele;
        (*size)++;
    } else {

        if (compare_to(ele->key, tree->key) < 0) { // ele < tree
            if (tree->left == NULL) {
                tree->left = ele;
                (*size)++;
            } else {
                binary_tree_add(tree->left, ele, compare_to, size);
            }
        } else if (compare_to(ele->key, tree->key) > 0) { // ele > tree
            if (tree->right == NULL) {
                tree->right = ele;
                (*size)++;
            } else {
                binary_tree_add(tree->right, ele, compare_to, size);
            }
        } else { // ele == tree
            return;
        }

    }

} // add

struct Binary_Node * binary_tree_min(struct Binary_Node * tree) {

    if (tree->left != NULL) binary_tree_min(tree->left);
    else return tree;

} // min

struct Binary_Node * binary_tree_max(struct Binary_Node * tree) {

    if (tree->right != NULL) binary_tree_max(tree->right);
    else return tree;

} // max

struct Binary_Node * binary_tree_del(struct Binary_Node * tree, struct Binary_Node * ele,
                                     int(compareTo)(const void * const x, const void * const y), size_t * size) {

    if (compareTo(ele->key, tree->key) == 0) {

        if (tree->left == NULL && tree->right == NULL) { // zero children
            (*size)--;
            return NULL;
        } else if (tree->left != NULL && tree->right == NULL) { // only left child
            (*size)--;
            return tree->left;
        } else if (tree->right != NULL && tree->left == NULL) { // only right child
            (*size)--;
            return tree->right;
        } else if (tree->left != NULL && tree->right != NULL) { // two children
            struct Binary_Node * replacer = binary_tree_max(tree->left);
            tree->key = replacer->key;
            tree->value = replacer->value;
            tree->left = binary_tree_del(tree->left, replacer, compareTo, size);
            (*size)--;
//            struct Binary_Node * replacer = map_tree_min(tree->right);
//            tree->key = replacer->key;
//            tree->value = replacer->value;
//            tree->left = NULL;
//            tree->right = map_tree_del(tree->right, replacer, compareTo, size);
//            (*size)--;
            return tree;
        }

    }
    if (compareTo(ele->key, tree->key) < 0 && tree->left != NULL) {
        tree->left = binary_tree_del(tree->left, ele, compareTo, size);
    } else if (compareTo(ele->key, tree->key) > 0 && tree->right != NULL) {
        tree->right = binary_tree_del(tree->right, ele, compareTo, size);
    }


} // delete


struct Binary_Node *
binary_tree_contains(struct Binary_Node * tree, struct Binary_Node ele, int(compareTo(void * x, void * y))) {

    if (compareTo(ele.key, tree->key) < 0 && tree->left != NULL) {
        binary_tree_contains(tree->left, ele, compareTo);
    } else if (compareTo(ele.key, tree->key) > 0 && tree->right != NULL) {
        binary_tree_contains(tree->right, ele, compareTo);
    } else if (compareTo(ele.key, tree->key) == 0) {
        return tree;
    }

} // contains

size_t binary_tree_height(struct Binary_Node * tree) {

    size_t leftHght, rightHght;
    leftHght = rightHght = 0;

    if (tree->left != NULL) leftHght += binary_tree_height(tree->left) + 1;
    if (tree->right != NULL) rightHght += binary_tree_height(tree->right) + 1;

    return leftHght > rightHght ? leftHght : rightHght;

} // height


struct Binary_Node *
binary_tree_update_node(struct Binary_Node * tree, struct Binary_Node * trgt_node, void * new_value,
                        int(compare_to)(const void * const x, const void * const y)) {


    //printf("check:  %d %d \n", *(int*)tree->value, *(int*)trgt_node->value);

    if (compare_to(tree->value, trgt_node->value) == 0) {
        tree->value = new_value;
    }

    if (tree->left != NULL)
        binary_tree_update_node(tree->left, trgt_node, new_value, compare_to);


    if (tree->right != NULL)
        binary_tree_update_node(tree->right, trgt_node, new_value, compare_to);


}

void binary_tree_inorder_traversal(struct Binary_Node * tree) {

    if(tree == NULL) return;

    if (tree->left != NULL)
        binary_tree_inorder_traversal(tree->left);

    printf("%d %d\n", *(int *) tree->key, *(int *) tree->value);

    if (tree->right != NULL)
        binary_tree_inorder_traversal(tree->right);

}

bool binary_tree_is_equal(struct Binary_Node * a, struct Binary_Node * b, int(compareTo)(void * x, void * y)) {

    if (a->left == NULL ^ b->left == NULL || a->right == NULL ^ b->right == NULL) return false;

    if (compareTo(a->key, b->key) != 0) return false;

    binary_tree_is_equal(a->left, b->left, compareTo);
    binary_tree_is_equal(a->right, b->right, compareTo);

    return true;

} // is_equal
