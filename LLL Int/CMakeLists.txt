cmake_minimum_required(VERSION 3.30.4)

project(LLLint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
add_executable(tests tests.cpp lllint.cpp)
