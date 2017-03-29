cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp data_structure/List/LinkedList.h data_structure/Stack/Stack.h)
add_executable(src ${SOURCE_FILES} data_structure/List/LinkedList.h data_structure/Stack/Stack.h)