//
// Created by thiagofsr on 22/04/18.
//

#include <iostream>
#include "Graph.h"

void Graph::addNode(Node *node) {
    nodes.push_back(node);
}

int Graph::GetIndex(unsigned int u, unsigned int v) {
    return (matrixSize*u) + v;
}

Node *Graph::getNode(unsigned int identifier) {
    for(auto v: nodes){
        if(v->getIdentifier() == identifier){
            return v;
        }
    }
    return nullptr;
}

std::vector<Node*> Graph::getAllNodes() {
    return this->nodes;
}



long Graph::getWeigth(unsigned int u, unsigned int v) {
    return array[GetIndex(u,v)];
}


void Graph::setWeightMatrix(unsigned int u, unsigned int v,long weight) {
    int index = GetIndex(u,v);
    array[index] = weight;
}

Graph::Graph(int matrixSize) {
    this->matrixSize = matrixSize;
    this->array = new long[matrixSize*matrixSize]();

}

Graph::~Graph() {
    delete[] this->array;
};



void Graph::showMatrix(){
    for(int i = 0; i < (matrixSize*matrixSize);i++){
        std::cout << array[i] << " ";
        if((i + 1) % matrixSize == 0)
            std::cout << std::endl;
    }


}

void Graph::showNeighbors() {

    for(auto u:nodes){
        std::cout << "Neighbors of " << u->getIdentifier() << " :";
        for(auto v:nodes.at(u->getIdentifier())->getNeighbors()){
            std::cout << v->getIdentifier() << " ";

        }
        std::cout << std::endl;
    }

}




