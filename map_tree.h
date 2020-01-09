#include <stddef.h>
#include <stdbool.h>

struct Node {
  void * key; // key
  void * value; // value
  struct Node * left; // left child
  struct Node * right; // right child
};

struct Node * map_tree_init_node(void * k, void * v);

void map_tree_add(struct Node * tree,  struct Node * ele, int(compare_to)(void * x, void * y), size_t * size);

struct Node * map_tree_del(struct Node * tree,  struct Node * ele, int(compare_to)(void * x, void * y), size_t * size);

struct Node * map_tree_min(struct Node * tree);

struct Node * map_tree_max(struct Node * tree);

size_t map_tree_height(struct Node * tree);

bool is_equal(struct Node * a, struct Node * b, int(compare_to)(void * x, void * y));

// 0 absent
// 1 present
struct Node * map_tree_contains(struct Node * tree, struct Node ele, int(compare_to)(void * x, void * y));
