cmake_minimum_required(VERSION 2.8)
project(project4)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Functions.h Functions.cpp Variable.cpp Variable.h Value.cpp Value.h)
add_executable(project3 ${SOURCE_FILES})