struct node{
  void * ele;
  int prio;
};

struct prio_queue {
  struct node * queue;
  size_t size;
  size_t cpcty;
  size_t typ_size;
};

void prio_queue_new(struct prio_queue * my_queue, size_t typ_size, size_t cpcty);

void prio_queue_add(struct prio_queue * queue, struct node * ele);

struct node * prio_queue_del(struct prio_queue * my_queue);

void prio_queue_grow(struct prio_queue * my_queue);

void prio_queue_free(struct prio_queue * my_queue);
