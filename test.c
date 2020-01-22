#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtable.h"


size_t hash_func(const void * const h, size_t s) {
    return strlen((char *) h)%s;
}

int compare(const void * const x, const void * const y) {
    return strlen((char *) x) - strlen((char *) y);
}

int main() {

    char * names[] = {"param", "dea", "chahat", "asma", "fahad", "celebrimbor"};

    struct Hash_Table ht;
    hash_table_init(&ht, 5);

    for (int i = 0; i < sizeof(names)/sizeof(names[0]); ++i)
        hash_table_insert(&ht, names[i], hash_func);

    hash_table_remove(&ht, names[5], hash_func, compare);
    hash_table_remove(&ht, names[0], hash_func, compare);
    hash_table_remove(&ht, names[3], hash_func, compare);
    hash_table_remove(&ht, names[1], hash_func, compare);

    hash_table_print(ht);

}