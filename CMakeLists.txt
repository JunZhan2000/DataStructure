cmake_minimum_required(VERSION 3.15)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(queue)
include_directories(stack)
include_directories(Tree)

add_executable(DataStructure
        Tree/ThreadTree/ThreadTree.h Tree/ThreadTree/ThreadTree.c Tree/ThreadTree/ThreadTreeTest.c
        )
