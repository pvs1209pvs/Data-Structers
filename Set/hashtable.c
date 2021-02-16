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

    table->arr = malloc(cpcty * sizeof(struct KeyValue));
    table->cpcty = cpcty;
    table->size = 0;

    for (size_t i = 0; i < cpcty; ++i){
        table->arr[i] = EMPTY_KV;
    }

}


/**
 * @param table
 * @param ele
 * @param hash_func
 * @return 
 */
_Bool hash_table_insert(struct Hash_Table * table, void * const key, void * const value, size_t (hash_func)(const void * const h)){

    if((float)table->size/table->cpcty >= 0.75) {
        hash_table_grow(table);
    }

    size_t index = hash_func(key)%table->cpcty;

    for (size_t i = index; i != index-1; i = (i + 1)%table->cpcty) {

        if(hash_table_is_blank(table, i)){
            table->arr[i] = (struct KeyValue){.key=key, .value=value};
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
void * hash_table_remove(struct Hash_Table * table, const void * const key, size_t (hash_func(const void * const h)), int(compare)(const void * const x, const void * const y)) {

    size_t index = hash_func(key)%table->cpcty;

    for (size_t i = index; i != index-1; i = (i + 1)%table->cpcty){

       if(!hash_table_is_blank(table, i) && compare(key, table->arr[i].key)==0){
            void * value = malloc(sizeof(void*));
            memcpy(value, table->arr[i].value, sizeof(void*));
            table->arr[i] = EMPTY_KV;
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
    table->arr = realloc(table->arr, sizeof(struct KeyValue)*table->cpcty);

    if(table->arr == NULL){
        printf("ERROR: hash_table_grow failed.\n");
        exit(1);
    }

    for (size_t i = table->cpcty/2; i < table->cpcty; ++i){
        table->arr[i] = EMPTY_KV;
    }

}


/**
 * @param table
 * @param index
 * @return 
 */
_Bool hash_table_is_blank(struct Hash_Table * table, const size_t index){
    return table->arr[index].key == NULL && table->arr[index].value == NULL;
}