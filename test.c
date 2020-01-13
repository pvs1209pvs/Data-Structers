#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "con_set.h"

struct Person{
    char name[64];
    int age;
    float height;
};


int compare(const void * const x, const void * const y) {
    struct Person p_one, p_two;

    p_one=*(struct Person*)x;
    p_two=*(struct Person*)y;

    return (strcmp(p_one.name,p_two.name)) + (p_one.age-p_two.age) + (int)(p_one.height-p_two.height);


}


int main() {

    struct Person people[5];
    people[0] = (struct Person){"param", 20, 5.10};
    people[1] = (struct Person){"simar", 22, 5.9};
    people[2] = (struct Person){"dea", 20, 0.10};
    people[3] = (struct Person){"chahat", 21, 5.2};
    people[4] = (struct Person){"asma", 21, 5.4};

    struct Set set_one;
    set_con_init(&set_one, 2);

    struct Set set_two;
    set_con_init(&set_two, 2);

    set_con_add(&set_one, &people[0], compare);
    set_con_add(&set_one, &people[1], compare);
    set_con_add(&set_one, &people[2], compare);

    set_con_add(&set_two, &people[3], compare);
    set_con_add(&set_two, &people[4], compare);

    struct Set set_three = *set_con_union(&set_one, &set_two, compare);

    for (int i = 0; i < set_three.size; ++i) {
        struct Person p = *(struct Person*)set_three.head[i];
        printf("%s \t %d \t %f \n", p.name, p.age, p.height);
    }

}