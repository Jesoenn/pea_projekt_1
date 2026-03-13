cmake_minimum_required(VERSION 3.30)
project(pea_projekt_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(pea_projekt_1 main.cpp
        src/include/ISolver.h
        src/utils/Timer.h
        src/utils/Timer.cpp
        src/core/Graph.h
        src/core/Graph.cpp
        src/core/FileManager.cpp
        src/core/FileManager.h
        src/algorithms/BFSolver.cpp
        src/algorithms/BFSolver.h
        src/algorithms/RANDSOLVER.cpp
        src/algorithms/RANDSOLVER.h
        src/algorithms/NNSolver.cpp
        src/algorithms/NNSolver.h
)
