cmake_minimum_required(VERSION 3.15)
project(cpplus)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpplus main.cpp class.h extern.cpp "placement new.cpp" class.cpp operator.h operator.cpp vector_.h vector_.cpp)