#include <stdlib.h>
#include <stdio.h>
#include "set_con.h"

int compare(void * x, void * y) {
    return *(char *) x - *(char *) y;
}

int main() {


    char * data[26];

    for (int i = 0; i < 26; ++i) {
        char * c = malloc(sizeof(char));
        *c = (char) (i + 97);
        data[i] = c;
    }


    struct Set mySet;
    set_con_init(&mySet, 5);

    for (int k = 0; k < 10; ++k) {
        set_con_add(&mySet, data[k], compare);
    }

    set_con_dlt_indx(&mySet, 2);

    printf("Size %zu\n", mySet.size);
    for (int j = 0; j < mySet.size; ++j) {
        if (mySet.head[j] != NULL)
            printf("%c\n", *(char *) mySet.head[j]);
    }


//    printf("Addresses\n");
//    for (int l = 0; l < 10; ++l) {
//        if (mySet.head[l] != NULL)
//            free(mySet.head[l]);
//        else printf("huh");
//        printf("%p\n", mySet.head[l]);
//    }

    set_con_free(&mySet);


    for (int j = 0; j < 26; ++j) {
        free(data[j]);
    }

}