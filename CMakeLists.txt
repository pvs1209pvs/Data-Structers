cmake_minimum_required(VERSION 3.14)
project(C_DS C)

set(CMAKE_C_STANDARD 99)

add_executable(C_DS map_tree.c map_tree.h list_con.c list_con.h list_link.c list_link.h prio_queue.c prio_queue.h set_con.c set_con.h set_link.h stack_con.c stack_con.h test.c)