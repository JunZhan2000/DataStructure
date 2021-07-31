cmake_minimum_required(VERSION 3.15)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(queue)
include_directories(stack)
include_directories(Tree)
include_directories(Graph)

add_executable(DataStructure
        Sort/Select/SelectSort.h Sort/Select/SelectSort.c Sort/Select/SelectSortTest.c)
