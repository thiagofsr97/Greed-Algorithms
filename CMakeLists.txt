cmake_minimum_required(VERSION 3.10)
project(GreedyAlgorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(GreedyAlgorithms main.cpp cmake-build-debug/Node/Node.cpp cmake-build-debug/Node/Node.h Graph/Graph.cpp Graph/Graph.h cmake-build-debug/FileReader/FileReader.cpp cmake-build-debug/FileReader/FileReader.h Dijkstra/Dijsktra.cpp Dijkstra/Dijsktra.h Heap/Heap.h)