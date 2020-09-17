cmake_minimum_required(VERSION 3.17)
project(erban)

set(CMAKE_CXX_STANDARD 14)

add_executable(erban main.cpp EBUrlParser.cpp EBUrlParser.h)