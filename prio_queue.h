struct PQ_Node {
    void * ele;
    int prio;
};

struct Priority_Queue {
    struct PQ_Node * queue;
    size_t size;
    size_t cpcty;
    size_t typ_size;
};

void prio_queue_init(struct Priority_Queue * my_queue, size_t cpcty);

void prio_queue_add(struct Priority_Queue * queue, struct PQ_Node * ele);

struct PQ_Node * prio_queue_del(struct Priority_Queue * my_queue);

void prio_queue_grow(struct Priority_Queue * my_queue);

void prio_queue_free(struct Priority_Queue * my_queue);
