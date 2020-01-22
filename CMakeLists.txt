cmake_minimum_required(VERSION 3.14)
project(C_DS C)

set(CMAKE_C_STANDARD 99)

add_executable(C_DS binary_tree.c binary_tree.h con_list.c con_list.h link_list.c link_list.h con_set.c con_set.h link_set.h con_stack.c con_stack.h test.c tree_priority_queue.c tree_priority_queue.h hashtable.h hashtable.c)