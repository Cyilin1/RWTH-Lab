cmake_minimum_required(VERSION 3.5)

project(Lab08 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab08 Buecherei.cpp Datum.cpp Datum.h Medium.cpp Medium.h Person.cpp Person.h
    buch.h buch.cpp
    magazin.h magazin.cpp
    DVD.h DVD.cpp)

include(GNUInstallDirs)
install(TARGETS Lab08
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
