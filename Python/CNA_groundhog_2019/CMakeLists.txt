cmake_minimum_required(VERSION 3.15)
project(CNA_groundhog_2019)

set(CMAKE_CXX_STANDARD 14)

add_executable(CNA_groundhog_2019
        src/main.cpp
        include/groundhog.hpp src/groundhog.cpp)
