cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp data_structure/List/Node.h data_structure/List/List.cpp data_structure/List/List.h)
add_executable(src ${SOURCE_FILES} data_structure/List/Node.h data_structure/List/List.cpp data_structure/List/List.h)