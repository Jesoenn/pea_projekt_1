cmake_minimum_required(VERSION 3.26.4)
project(pea_projekt_1)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")

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
        src/include/helpers.cpp
        src/include/helpers.h
        src/algorithms/RNNSolver.cpp
        src/algorithms/RNNSolver.h
        src/include/algorithms.h
        src/core/App.cpp
        src/core/App.h
        src/include/answers.h
        src/include/inputs.h
)
