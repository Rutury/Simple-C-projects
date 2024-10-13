cmake_minimum_required(VERSION 3.30.4)

project(HeapSortTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
add_executable(tests tests.cpp heapsort.cpp)
