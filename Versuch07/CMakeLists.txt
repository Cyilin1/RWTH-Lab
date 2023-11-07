cmake_minimum_required(VERSION 3.5)

project(Versuch07 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Versuch07 Student.h Student.cpp main.cpp)
