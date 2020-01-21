#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

void list_link_init(struct Link_List * list) {
    list->size = 0;
    list->head = NULL;
}


void link_list_prepend_node(struct Link_List  * list, struct List_Node * ele) {

    if (list->size == 0) {
        list->head = ele;
        ele->next = NULL;
    } else {
        ele->next = list->head;
        list->head = ele;
    }

}


void link_list_prepend_ele(struct Link_List  * list, void * ele) {

    struct List_Node * eleNode = malloc(sizeof(struct List_Node));
    eleNode->value = ele;
    eleNode->next = NULL;

    link_list_prepend_node(list, eleNode);
    list->size++;

}


void link_list_append_node(struct Link_List * list, struct List_Node * ele) {
    link_list_add_node_at(list, ele, list->size);
}


void link_list_append_ele(struct Link_List * list, void * ele) {

    struct List_Node * eleNode = malloc(sizeof(struct List_Node));
    eleNode->value = ele;
    eleNode->next = NULL;

    link_list_append_node(list, eleNode);
    list->size++;
}


void link_list_add_node_at(struct Link_List * list, struct List_Node * ele, size_t index) {

    if (index == 0) {
        ele->next = list->head;
        list->head = ele;
    } else {

        struct List_Node * p = list->head;
        struct List_Node * q = list->head;

        for (size_t i = 0; i < index; i++) {
            q = p;
            p = p->next;
        }

        ele->next = p;
        q->next = ele;

    }

}


void link_list_add_ele_at(struct Link_List * list, void * ele, size_t index) {

    link_list_index_check(list, index);

    struct List_Node * eleNode = malloc(sizeof(struct List_Node));
    eleNode->value = ele;
    eleNode->next = NULL;

    link_list_add_node_at(list, eleNode, index);
    list->size++;

}


void link_list_dlt_at(struct Link_List * list, size_t index) {

    link_list_index_check(list, index);

    struct List_Node * p = list->head;
    struct List_Node * q = list->head;

    if (index == 0) {
        list->head = p->next;
    } else {
        for (size_t i = 0; i < index; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }

    list->size--;

}


void link_list_dlt_ele(struct Link_List * list, void * ele, int(compareTo)(const void * const x, const void * const y)) {

    struct List_Node * p = list->head;
    struct List_Node * q = list->head;

    if (link_list_index_of(list, ele, compareTo) == 0) {
        list->head = p->next;
        list->size--;
        free(p);
        printf("%s\n", "yes");
    } else {

        for (size_t i = 1; i < list->size; i++) {

            q = p;
            p = p->next;
            if (compareTo(ele, p->value) == 0) {
                q->next = p->next;
                list->size--;
                free(p);
                break;
            }
        }

    }

}


void * link_list_get(struct Link_List * list, size_t index) {

    struct List_Node * p = list->head;

    for (size_t i = 0; i < index; i++) {
        p = p->next;
    }

    return p->value;

}


void link_list_set_at(struct Link_List * list, void * new_value, size_t index) {

    link_list_index_check(list, index);

    struct List_Node * p = list->head;

    for (size_t i = 0; i < index; i++) {
        p = p->next;
    }

    p->value = new_value;

}


int link_list_index_of(struct Link_List * list, void * ele, int(compareTo)(const void * const x, const void * const y)) {

    struct List_Node * p = list->head;
    int ele_index = -1;

    for (int i = 0; i < list->size; i++) {
        if (compareTo(ele, p->value) == 0) {
            ele_index = i;
            break;
        }
        p = p->next;
    }

    return ele_index;

}


_Bool link_list_cnts(struct Link_List * list, void * ele, int(compareTo)(const void * const x, const void * const y)) {

    struct List_Node * p = list->head;

    for (size_t i = 0; i < list->size; i++) {
        // if compareTo return 0 then it means the compared elements are the same
        if (compareTo(ele, p->value) == 0) {
            return 1;
        }
        p = p->next;
    }

    return 0;

}


_Bool link_list_is_empty(struct Link_List * list) {
    return list->size == 0 ? 1 : 0;
}


void link_list_free(struct Link_List * list) {

    struct List_Node * p = list->head;

    for (size_t i = 0; i < list->size; i++) {
        free(p);
        p = p->next;
    }

    list->size = 0;

}


void ** link_list_to_array(struct Link_List * list) {

    if (list->size == 0) {
        return NULL;
    }

    struct List_Node * p = list->head;

    void ** array = malloc(sizeof(void *)*list->size);

    for (size_t i = 0; i < list->size; i++) {
        array[i] = p->value;
        p = p->next;
    }

    return array;

}


void link_list_index_check(struct Link_List * list, size_t index) {
    if (index < 0 || index >= list->size) {
        exit(1);
    }
}
