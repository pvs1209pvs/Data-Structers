#include <stdlib.h>
#include <stdio.h>
#include "list_con.h"

int main(){

  con_list myList;
  con_list_new(&myList, sizeof(int), 4);

  int ** nums = malloc(sizeof(int*)*100);
  for (int i = 0; i < 100; i++) {
    nums[i] = malloc(sizeof(int*));
    int * x = malloc(sizeof(int));
    *x = i;
    nums[i] = x;
  }

  for (size_t i = 0; i < 3; i++) {
    con_list_add(&myList, nums[i]);
  }

  //con_list_clr(&myList);

  printf("cap %zu   size %zu\n", con_list_size(&myList), myList.cpcty);
  for (size_t i = 0; i < con_list_size(&myList); i++) {
    printf("%d\n", *(int*)con_list_get(&myList, i));
  }


  con_list_free(&myList);

  // for (size_t i = 0; i < 100; i++) {
  //   free(nums[i]);
  // }
  // free(nums);
  return 0;
}
