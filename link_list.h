// -1 improper termination
// 1 proper termination

struct List_Node {
    void * value; // literal values can't be passed in here, only address can be passed
    struct List_Node * next;
};

struct Link_List {
    size_t size;
    struct List_Node* head;

} list_link;

// array list : impl what
void link_list_int(struct Link_List * list);

void link_list_prepend_node(struct Link_List * link_list, struct List_Node * ele);

void link_list_prepend_ele(struct Link_List * link_list, void * ele);

void link_list_append_node(struct Link_List * link_list, struct List_Node * ele);

void link_list_append_ele(struct Link_List * link_list, void * ele);

void link_list_add_node_at(struct Link_List * link_list, struct List_Node * ele, size_t index);

void link_list_add_ele_at(struct Link_List * link_list, void * ele, size_t index);

void link_list_dlt_at(struct Link_List * link_list, size_t index);

void link_list_dlt_ele(struct Link_List * link_list, void * ele, int(compareTo)(const void * const x, const void * const y));

void * link_list_get(struct Link_List * link_list, size_t index);

void link_list_set_at(struct Link_List * link_list, void * new_value, size_t index);

int link_list_index_of(struct Link_List * link_list, void * ele, int(compareTo)(const void * const x, const void * const y));

_Bool link_list_cnts(struct Link_List * link_list, void * ele, int(compareTo)(const void * const x, const void * const y));

_Bool link_list_is_empty(struct Link_List * link_list);

void link_list_free(struct Link_List * link_list);

void ** link_list_to_array(struct Link_List * link_list);

void link_list_index_check(struct Link_List * list, size_t index);
