cmake_minimum_required(VERSION 3.10)

project(Data-Structures)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-g")

include_directories(List Map Set Stack Test)

add_executable(
    Data-Structures 
    List/con_list.c List/link_list.c
    Map/binary_tree.c
    Set/con_set.c Set/hashtable.c 
    Stack/con_stack.c
    Test/test.c
)
