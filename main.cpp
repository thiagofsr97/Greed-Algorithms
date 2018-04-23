#include <iostream>
#include "cmake-build-debug/FileReader/FileReader.h"
#include "Dijkstra/Dijsktra.h"

int main() {


    FileReader file("test.txt");
    Graph* graph = file.createGraph();
    graph->showMatrix();
    Dijsktra dijsktra(graph);
    dijsktra.solveProblem();
    std::cout<< "Shortest Weight: " << dijsktra.getShortestWeight() <<std::endl;
    std::cout << "Path: ";
    for(auto v:dijsktra.getShortestPath()){
        std::cout << v << " ";
    }
    std::cout << std::endl;

    delete graph;

    return 0;
}