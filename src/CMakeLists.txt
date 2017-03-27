cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp data_structure/List/DNode.h data_structure/List/DList.h)
add_executable(src ${SOURCE_FILES} data_structure/List/DNode.h data_structure/List/DList.h)