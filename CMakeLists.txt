cmake_minimum_required(VERSION 3.10)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Proyecto1 main.cpp MPointer/MPointer.h LinkedList/LinkedList.h LinkedList/Node/Node.h MPointerGC/MPointerGC.h MPointerGC/MPointerGC.cpp MPointerGC/RC.cpp MPointerGC/RC.h)
