// -1 improper termination
// 1 proper termination

struct node {
    void * value; // literal values can't be passed in here, only address can be passed
    struct node * next;
};

typedef struct {
    size_t size;
    struct node * head;

} list_link;

// array list : impl what
void link_list_int(list_link * list);

void link_list_prepend_node(list_link * list, struct node * ele);

void link_list_prepend_ele(list_link * list, void * ele);

void link_list_append_node(list_link * list, struct node * ele);

void link_list_append_ele(list_link * list, void * ele);

void link_list_add_node_at(list_link * list, struct node * ele, size_t index);

void link_list_add_ele_at(list_link * list, void * ele, size_t index);

void link_list_dlt_at(list_link * list, size_t index);

void link_list_dlt_ele(list_link * list, void * ele, int(compareTo)(const void * const x, const void * const y));

void * link_list_get(list_link * list, size_t index);

void link_list_set_at(list_link * list, void * new_value, size_t index);

int link_list_index_of(list_link * list, void * ele, int(compareTo)(const void * const x, const void * const y));

_Bool link_list_cnts(list_link * list, void * ele, int(compareTo)(const void * const x, const void * const y));

_Bool link_list_is_empty(list_link * list);

void link_list_free(list_link * list);

void ** link_list_to_array(list_link * list);

void link_list_index_check(list_link * list, size_t index);
