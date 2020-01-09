struct node {
    void* value;
    struct node* next;
}

typedef struct {
  size_t size;
  struct node* head;
} set_link;

void set_link_new(set_link * set);

void set_link_add_node_(set_link * set, struct node * ele);

void set_link_add_ele(set_link * set, void * ele);

void set_link_remove(set_link * set, void * ele);

set_link set_link_union(set_link * a, set_link * b);

set_link set_link_intrsctn(set_link * a, set_link * b);

_Bool set_link_cntns(set_link * set, void * ele, int(compareTo)(void * x, void * y));

void set_link_free(set_link * set);
