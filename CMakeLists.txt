cmake_minimum_required(VERSION 3.10)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Proyecto1 main.cpp MPointer.h MPointer.cpp LinkedList/LinkedList.h LinkedList/LinkedList.cpp LinkedList/Node/Node.h LinkedList/Node/Node.cpp)
