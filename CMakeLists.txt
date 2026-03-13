cmake_minimum_required(VERSION 3.30)
project(pea_projekt_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(pea_projekt_1 main.cpp
        src/include/ISolver.cpp
        src/include/ISolver.h
        src/core/Graph.cpp
        src/core/Graph.h
        src/utils/timer.cpp
        src/utils/timer.h)
