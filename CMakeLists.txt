cmake_minimum_required(VERSION 3.21)
project(Kruskal_and_Prim_Implementation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Kruskal_and_Prim_Implementation
        Driver.cpp
        Graph.h
        GraphUtil.cpp
        GraphUtil.h
        KruskalSolver.cpp
        KruskalSolver.h
        MSTSolver.h
        PrimSolver.cpp
        PrimSolver.h)
