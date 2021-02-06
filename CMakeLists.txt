cmake_minimum_required(VERSION 3.10)

project(Data-Structures)

set(CMAKE_C_STANDARD 99)

include_directories(List Map Set Stack Test)

add_executable(
    Data-Structures 
    List/con_list.c List/link_list.c
    Map/binary_tree.c Map/tree_priority_queue.c
    Set/con_set.c Set/hashtable.c Set/map.c
    Stack/con_stack.c
    Test/test.c
)