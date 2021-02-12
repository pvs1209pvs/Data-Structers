#ifndef C_DS_HASTTABLE_H
#define C_DS_HASTTABLE_H

#include<stddef.h>

struct Hash_Table {
    void ** arr;
    size_t size;
    size_t cpcty;
};

void hash_table_init(struct Hash_Table * hash_table, const size_t cpcty);

_Bool hash_table_insert(struct Hash_Table * hash_table, void * const ele, size_t (hash_func)(const void * const h));

void * hash_table_remove(struct Hash_Table * hash_table, void * ele, size_t (hash_func(const void * const h)), int(compare)(const void * const x, const void * const y));

static void hash_table_grow(struct Hash_Table * hashTable);

#endif //C_DS_HASTTABLE_H
