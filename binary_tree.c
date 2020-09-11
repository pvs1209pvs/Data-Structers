#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "map.h"

struct Binary_Node * binary_tree_init_node(void * k) {

    struct Binary_Node * result = malloc(sizeof(struct Binary_Node));
    result->key = k;
    result->left = NULL;
    result->right = NULL;
    return result;

} // init_node

void binary_tree_add(struct Binary_Node * tree, struct Binary_Node * ele,
                     int(compare_to(const void * const x, const void * const y))) {

                       

    if (tree == NULL) { // tree is empty
        printf("Error: Root node cannot be NULL. Give it a value key-value values before adding elements to the binary tree.");
        exit(1);
    } else {

        if (compare_to(ele->key, tree->key) < 0) { // ele < tree
            if (tree->left == NULL) {
                tree->left = ele;
                struct Pair * p = (struct Pair*)ele;
                printf("%d \n", *(int*)p->key);
            } else {
                binary_tree_add(tree->left, ele, compare_to);
            }
        } else if (compare_to(ele->key, tree->key) > 0) { // ele > tree
            if (tree->right == NULL) {
                tree->right = ele;
               
            } else {
                binary_tree_add(tree->right, ele, compare_to);
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
                                     int(compareTo)(const void * const x, const void * const y)) {

    if (compareTo(ele->key, tree->key) == 0) {

        if (tree->left == NULL && tree->right == NULL) { // zero children
            return NULL;
        } else if (tree->left != NULL && tree->right == NULL) { // only left child
            return tree->left;
        } else if (tree->right != NULL && tree->left == NULL) { // only right child
            return tree->right;
        } else if (tree->left != NULL && tree->right != NULL) { // two children
            struct Binary_Node * replacer = binary_tree_max(tree->left);
            tree->key = replacer->key;
            tree->left = binary_tree_del(tree->left, replacer, compareTo);
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
        tree->left = binary_tree_del(tree->left, ele, compareTo);
    } else if (compareTo(ele->key, tree->key) > 0 && tree->right != NULL) {
        tree->right = binary_tree_del(tree->right, ele, compareTo);
    }


} // delete


struct Binary_Node *
binary_tree_contains(struct Binary_Node * tree, struct Binary_Node ele, int(compareTo(const void * const x, const void * const y))) {

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

    if (compare_to(tree->key, trgt_node->key) == 0) {
        tree->key = new_value;
    }

    if (tree->left != NULL)
        binary_tree_update_node(tree->left, trgt_node, new_value, compare_to);


    if (tree->right != NULL)
        binary_tree_update_node(tree->right, trgt_node, new_value, compare_to);


}

void binary_tree_inorder_traversal(struct Binary_Node * tree, struct List * list) {

    if(tree == NULL) return;

    if (tree->left != NULL){
        binary_tree_inorder_traversal(tree->left, list);
    }

    con_list_add(list, tree->key);

    //printf("%d\n", *(int *) tree->key);

    if (tree->right != NULL){
        binary_tree_inorder_traversal(tree->right, list);
    }

}

struct List binary_tree_ele_array(struct Binary_Node * tree){

   struct List l;
   con_list_init(&l, 2);

   binary_tree_inorder_traversal(tree, &l);

   return l;

}


bool binary_tree_is_equal(struct Binary_Node * a, struct Binary_Node * b, int(compareTo)(void * x, void * y)) {

    if (a->left == NULL ^ b->left == NULL || a->right == NULL ^ b->right == NULL) return false;

    if (compareTo(a->key, b->key) != 0) return false;

    binary_tree_is_equal(a->left, b->left, compareTo);
    binary_tree_is_equal(a->right, b->right, compareTo);

    return true;

} // is_equal
