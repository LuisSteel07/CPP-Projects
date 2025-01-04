cmake_minimum_required(VERSION 3.31)
project(Todo_List)

set(CMAKE_CXX_STANDARD 17)

add_executable(Todo_List main.cpp
        utils.h
        utils.cpp)
