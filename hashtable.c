#include<stdlib.h>
#include<stdio.h>
#include "hashtable.h"

void hash_table_init(struct Hash_Table * hash_table, size_t cpcty) {
    hash_table->table = calloc(cpcty, sizeof(void *));
    hash_table->cpcty = cpcty;
    hash_table->size = 0;
}

void _hash_table_add(struct Hash_Table * hash_table, void * ele, size_t (hash_func)(const void * const h, size_t s)) {

    size_t index = hash_func(ele, hash_table->cpcty);


    if (hash_table->table[index] == NULL) {
        hash_table->table[index] = ele;
    } else {
        for (size_t i = index + 1; i < hash_table->cpcty && i != index; i = (i + 1)%hash_table->cpcty) {
            if (hash_table->table[i] == NULL) {
                hash_table->table[i] = ele;
                break;
            }
        }
    }

    hash_table->size++;

}

void hash_table_insert(struct Hash_Table * hash_table, void * ele, size_t (hash_func)(const void * const h, size_t s)) {

    if ((float)hash_table->size/hash_table->cpcty >= 0.7) {

        struct Hash_Table * ht = _hash_table_grow(*hash_table);

        for (int i = 0; i < hash_table->cpcty; ++i) {
            if (hash_table->table[i] != NULL) {
                _hash_table_add(ht, hash_table->table[i], hash_func);
            }
        }

        free(hash_table->table);
        *hash_table = *ht;

        _hash_table_add(hash_table, ele, hash_func);

    } else {
        _hash_table_add(hash_table, ele, hash_func);
    }

}


void hash_table_remove(struct Hash_Table * hash_table, void * ele, size_t (hash_func(const void * const h, size_t s)),
                       int(compare)(const void * const x, const void * const y)) {

    size_t index = hash_func(ele, hash_table->cpcty);

    if (compare(hash_table->table[index], ele) == 0) {
        hash_table->table[index] = NULL;
    } else {
        for (size_t i = index + 1; i < hash_table->cpcty && i != index; i = (i + 1)%hash_table->cpcty) {
            if (compare(hash_table->table[i], ele) == 0) {
                free(hash_table->table[i]);
                hash_table->table[i] = NULL;
                break;
            }
        }
    }

}

struct Hash_Table * _hash_table_grow(struct Hash_Table hash_table) {

    struct Hash_Table * ht = malloc(sizeof(struct Hash_Table));
    hash_table_init(ht, hash_table.cpcty*2);
    return ht;

}

void hash_table_print(struct Hash_Table hash_table) {
    printf("\n");
    for (int i = 0; i < hash_table.cpcty; ++i) {
        if (hash_table.table[i] != NULL)
            printf("%s\n", (char *) hash_table.table[i]);
        else
            printf(".\n");
    }
}

