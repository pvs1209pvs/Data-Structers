#include "map_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int compare_to(void *x, void *y) {
    return *(int *) x - *(int *) y;
}

int main() {

    int key[] = {1, 2, 3, 4, 5, 6, 7};
    int value[] = {10, 20, 30, 40, 50, 60, 70};
    size_t size = 0;

    struct Node root = *map_tree_init_node(NULL, NULL);

    struct Node *nodes[] = {
            map_tree_init_node(&key[0], &value[0]),
            map_tree_init_node(&key[1], &value[1]),
            map_tree_init_node(&key[2], &value[2]),
            map_tree_init_node(&key[3], &value[3]),
            map_tree_init_node(&key[4], &value[4]),
            map_tree_init_node(&key[5], &value[5]),
            map_tree_init_node(&key[6], &value[6])};

    map_tree_add(&root, nodes[3], compare_to, &size);
    map_tree_add(&root, nodes[1], compare_to, &size);
    map_tree_add(&root, nodes[5], compare_to, &size);
    map_tree_add(&root, nodes[0], compare_to, &size);
    map_tree_add(&root, nodes[2], compare_to, &size);
    map_tree_add(&root, nodes[4], compare_to, &size);
    map_tree_add(&root, nodes[6], compare_to, &size);

}

struct Node *map_tree_init_node(void *k, void *v) {

    struct Node *result = malloc(sizeof(struct Node));
    result->key = k;
    result->value = v;
    result->left = NULL;
    result->right = NULL;
    return result;

} // init_node

void map_tree_add(struct Node *tree, struct Node *ele, int(compare_to(void *x, void *y)), size_t *size) {

    if (*size == 0) { // tree is empty
        *tree = *ele;
        (*size)++;
    } else {

        if (compare_to(ele->key, tree->key) < 0) { // ele < tree
            if (tree->left == NULL) {
                tree->left = ele;
                (*size)++;
            } else {
                map_tree_add(tree->left, ele, compare_to, size);
            }
        } else if (compare_to(ele->key, tree->key) > 0) { // ele > tree
            if (tree->right == NULL) {
                tree->right = ele;
                (*size)++;
            } else {
                map_tree_add(tree->right, ele, compare_to, size);
            }
        } else { // ele == tree
            return;
        }

    }

} // add

struct Node *map_tree_min(struct Node *tree) {

    if (tree->left != NULL) map_tree_min(tree->left);
    else return tree;

} // min

struct Node *map_tree_max(struct Node *tree) {

    if (tree->right != NULL) map_tree_max(tree->right);
    else return tree;

} // max

struct Node *map_tree_del(struct Node *tree, struct Node *ele, int(compareTo)(void *x, void *y), size_t *size) {

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
            struct Node *replacer = map_tree_min(tree->right);
            tree->key = replacer->key;
            tree->value = replacer->value;
            tree->left = NULL;
            tree->right = map_tree_del(tree->right, replacer, compareTo, size);
            return tree;
        }

    }
    if (compareTo(ele->key, tree->key) < 0 && tree->left != NULL) {
        tree->left = map_tree_del(tree->left, ele, compareTo, size);
    } else if (compareTo(ele->key, tree->key) > 0 && tree->right != NULL) {
        tree->right = map_tree_del(tree->right, ele, compareTo, size);
    }


} // delete


struct Node *map_tree_contains(struct Node *tree, struct Node ele, int(compareTo(void *x, void *y))) {

    if (compareTo(ele.key, tree->key) < 0 && tree->left != NULL) {
        map_tree_contains(tree->left, ele, compareTo);
    } else if (compareTo(ele.key, tree->key) > 0 && tree->right != NULL) {
        map_tree_contains(tree->right, ele, compareTo);
    } else if (compareTo(ele.key, tree->key) == 0) {
        return tree;
    }

} // contains

size_t map_tree_height(struct Node *tree) {

    size_t leftHght, rightHght;
    leftHght = rightHght = 0;

    if (tree->left != NULL) leftHght += map_tree_height(tree->left) + 1;
    if (tree->right != NULL) rightHght += map_tree_height(tree->right) + 1;

    return leftHght > rightHght ? leftHght : rightHght;

} // height

bool is_equal(struct Node *a, struct Node *b, int(compareTo)(void *x, void *y)) {

    if (a->left == NULL ^ b->left == NULL || a->right == NULL ^ b->right == NULL) return false;

    if (compareTo(a->key, b->key) != 0) return false;

    is_equal(a->left, b->left, compareTo);
    is_equal(a->right, b->right, compareTo);

    return true;

} // is_equal
