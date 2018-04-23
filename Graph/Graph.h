//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_GRAPH_H
#define GREEDYALGORITHMS_GRAPH_H


#include <vector>
#include <array>
#include "../cmake-build-debug/Node/Node.h"
class Graph {
private:
    std::vector<Node*> nodes;
    long *array;
    int matrixSize;
    int GetIndex(unsigned int u, unsigned int v);
public:
    Graph(int matrixSize);
    ~Graph();
    void addNode(Node* node);
    Node* getNode(unsigned int identifier);
    std::vector<Node*> getAllNodes();
    void setWeightMatrix(unsigned int u, unsigned int v,long weight);
    long getWeigth(unsigned int u , unsigned int v);
    void showMatrix();
    void showNeighbors();


};


#endif //GREEDYALGORITHMS_GRAPH_H
