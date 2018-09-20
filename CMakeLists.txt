cmake_minimum_required(VERSION 3.10)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Proyecto1 main.cpp)
add_library(MPointer SHARED MPointer.cpp MPointer.h LinkedList.cpp LinkedList.h Node.cpp Node.h)
