#ifndef C_DS_HASTTABLE_H
#define C_DS_HASTTABLE_H

#include<stddef.h>

struct Hash_Table {
    void ** table;
    size_t size;
    size_t cpcty;
};

void hash_table_init
    (struct Hash_Table * hash_table, 
    size_t cpcty);


void _hash_table_add
    (struct Hash_Table * hash_table, 
    void * ele, 
    size_t (hash_func)(const void * const h, size_t));


void hash_table_insert
    (struct Hash_Table * hash_table, 
    void * ele, 
    size_t (hash_func)(const void * const h, size_t s));


void hash_table_remove
    (struct Hash_Table * hash_table, 
    void * ele, 
    size_t (hash_func(const void * const h, size_t s)),
    int(compare)(const void * const x, const void * const y));

struct Hash_Table * _hash_table_grow
    (struct Hash_Table hashTable);


#endif //C_DS_HASTTABLE_H
