#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>
#include "hashtable.h"

/**
 * Initialzes the hashtable. 
 * @param table Container for the key-value pair.
 * @param cpcty Initial capacity for the table. 
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
 * Insert the value to the hashtable.
 * @param table Container for the key-value pair.
 * @param key Hashtable key.
 * @param value Hashtable value.
 * @param hash_func Hashing function.
 * @return True if the value was added, else false.
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
 * Remove the value mapped with the key. 
 * @param table Container for the key-value pair.
 * @param key Hashtable key.
 * @param hash_func Hashing function.
 * @param compare Functions to compare keys. 
 * @return Value to which the key has been mapped, NULL if it doesn't exist. 
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
 */
_Bool hash_table_contains(struct Hash_Table * table){
    return false;
}


/**
 */
void ** hash_table_keys(struct Hash_Table * table){
    return NULL;
}


/**
 */
void ** hash_table_values(struct Hash_Table * table){
    return NULL;
}


/**
 * Increase the size of the hashtable.
 * @param table Container for the key-value pair.
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
 * Check if the index is empty. 
 * @param table Container for the key-value pair.
 * @param index Index to be checked for the existance of a value.
 * @return True if no value exist at the index, else false. 
 */
_Bool hash_table_is_blank(struct Hash_Table * table, const size_t index){
    return table->arr[index].key == NULL && table->arr[index].value == NULL;
}