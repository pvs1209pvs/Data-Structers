// -1 improper termination
// 1 proper termination

struct node {
  void* value; // literal values can't be passed in here, only address can be passed
  struct node* next;
};

typedef struct {
  size_t size;
  struct node* head;

} list_link;

void list_link_new(list_link * list);

void list_link_prepend_node(list_link * list, struct node * ele);

void list_link_prepend_ele(list_link * list, void * ele);

void list_link_append_node(list_link * list, struct node * ele);

void list_link_append_ele(list_link * list, void * ele);

void list_link_add_node_at(list_link * list, struct node * ele, size_t index);

void list_link_add_ele_at(list_link * list, void * ele, size_t index);

void list_link_dlt_at(list_link * list, size_t index);

void list_link_dlt_ele(list_link * list, void * ele, int(compareTo)(void * x, void * y));

void * list_link_get(list_link * list, size_t index);

void list_link_set_at(list_link * list, void * new_value, size_t index);

int list_link_index_of(list_link * list, void * ele, int(compareTo)(void * x, void * y));

_Bool list_link_cnts(list_link * list, void * ele, int(compareTo)(void * x, void * y));

_Bool list_link_is_empty(list_link * list);

void list_link_free(list_link * list);

void** list_link_to_array(list_link * list);

void list_link_index_check (list_link * list, size_t index);
