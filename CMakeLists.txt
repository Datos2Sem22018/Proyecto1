cmake_minimum_required(VERSION 3.10)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp MPointerGC.cpp RC.cpp ClientSocket.cpp ServerSocket.cpp Server.cpp Client.cpp)

add_library(Proyecto1 ${SOURCE_FILES})
SET(CMAKE_CXX_FLAGS -pthread)
