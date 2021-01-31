// -1 improper termination
// 1 proper termination

#ifndef C_DS_LINK_LIST_H
#define C_DS_LINK_LIST_H


struct List_Node {
    void * value; //only address can be passed, not literal values.
    struct List_Node * next;
};

struct Link_List {
    size_t size;
    struct List_Node* head;

} list_link;


void link_list_init(struct Link_List * list);

void link_list_prepend_node(struct Link_List * const link_list, struct List_Node * const ele);

void link_list_prepend_ele(struct Link_List * const link_list, void * const ele);

void link_list_append_node(struct Link_List * const link_list, struct List_Node * const ele);

void link_list_append_ele(struct Link_List * const link_list, void * const ele);

void link_list_add_node_at(struct Link_List * const link_list, struct List_Node * const ele, const size_t index);

void link_list_add_ele_at(struct Link_List * const link_list, void * const ele, const size_t index);

void link_list_dlt_at(struct Link_List * const link_list, const size_t index);

void link_list_dlt_ele(struct Link_List * link_list, void * ele, int(compareTo)(const void * const x, const void * const y));

void * link_list_get(const struct Link_List * const link_list, const size_t index);

void link_list_set_at(struct Link_List * const link_list, void * const new_value, const size_t index);

int link_list_index_of(struct Link_List * const link_list, const void * const ele, int(compareTo)(const void * const x, const void * const y));

_Bool link_list_cnts(struct Link_List * const link_list, const void * const ele, int(compareTo)(const void * const x, const void * const y));

_Bool link_list_is_empty(const struct Link_List * const link_list);

void link_list_free(struct Link_List * link_list);

void ** link_list_to_array(struct Link_List * const link_list);

void link_list_index_check(const struct Link_List * const list, const size_t index);

#endif