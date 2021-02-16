#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>
#include "hashtable.h"


/**
 * @param table
 * @param cpcty
 */
void hash_table_init(struct Hash_Table * table, const size_t cpcty) {

    table->arr = calloc(cpcty, sizeof(void *));
    table->cpcty = cpcty;
    table->size = 0;

}


/**
 * @param table
 * @param ele
 * @param hash_func
 * @return 
 */
_Bool hash_table_insert(struct Hash_Table * table, void * const ele, size_t (hash_func)(const void * const h)){

    if((float)table->size/table->cpcty >= 0.75) {
        hash_table_grow(table);
    }

    size_t index = hash_func(ele)%table->cpcty;

    for (size_t i = index; i != index-1; i = (i + 1)%table->cpcty) {
        if (table->arr[i] == NULL) {
            table->arr[i] = ele;
            ++table->size;
            return true;
        }
    }

    return false;

}


/**
 * @param table
 * @param ele
 * @param hash_func
 * @param compare
 * @return 
 */
void * hash_table_remove(struct Hash_Table * table, void * ele, size_t (hash_func(const void * const h)), int(compare)(const void * const x, const void * const y)) {

    size_t index = hash_func(ele)%table->cpcty;

    for (size_t i = index; i != index-1; i = (i + 1)%table->cpcty){
        if(table->arr[i] != NULL && compare(table->arr[i], ele)==0){
            void * value = malloc(sizeof(void*));
            memcpy(value, ele, sizeof(void*));
            table->arr[i] = NULL;
            return value;
        }
    }

    return NULL;
    
}


/**
 * @param table
 */
static void hash_table_grow(struct Hash_Table * table) {

    table->cpcty *= 2; 
    table->arr = realloc(table->arr, sizeof(void*)*table->cpcty);

    if(table->arr == NULL){
        printf("hash table grow failed.\n");
        exit(1);
    }

    for (size_t i = table->cpcty/2; i < table->cpcty; ++i){
        table->arr[i] = NULL;
    }

}
