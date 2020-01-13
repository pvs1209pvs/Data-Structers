cmake_minimum_required(VERSION 3.14)
project(C_DS C)

set(CMAKE_C_STANDARD 99)

add_executable(C_DS tree_map.c tree_map.h con_list.c con_list.h link_list.c link_list.h prio_queue.c prio_queue.h con_set.c con_set.h link_set.h con_stack.c con_stack.h test.c)