#ifndef C_DS_HASTTABLE_H
#define C_DS_HASTTABLE_H

#include<stddef.h>

#define EMPTY_KV (struct KeyValue){.key=NULL, .value=NULL}

struct KeyValue{
    void * key;
    void * value;
};

struct Hash_Table {
    struct KeyValue * arr;
    size_t size;
    size_t cpcty;
};

void hash_table_init(struct Hash_Table * hash_table, const size_t cpcty);

_Bool hash_table_insert(struct Hash_Table * hash_table, void * const key, void * const value, size_t (hash_func)(const void * const h));

void * hash_table_remove(struct Hash_Table * hash_table, const void * const key, size_t (hash_func(const void * const h)), int(compare)(const void * const x, const void * const y));

static void hash_table_grow(struct Hash_Table * hashTable);

_Bool hash_table_is_blank(struct Hash_Table * table, const size_t index);

#endif //C_DS_HASTTABLE_H
