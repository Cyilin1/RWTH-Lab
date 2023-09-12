cmake_minimum_required(VERSION 3.5)

project(untitled4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(untitled4 Liste.h Liste.cpp Student.h Student.cpp ListenElement.h ListenElement.cpp main.cpp)
