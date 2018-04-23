//
// Created by thiagofsr on 22/04/18.
//

#include "Node.h"

Node::Node( unsigned int const &id) {
    this->identifier  = id;
    this->visited = false;
    this->weight = LONG_MAX; //the algorithms requires this property to be initialized with infinity value
    this->predecessorId = 0;
}

void Node::addNeighbor(Node *node) {
    this->neighbors.push_back(node);

}

std::vector<Node*> Node::getNeighbors() {
    return this->neighbors;
}

unsigned Node::getIdentifier() {
    return this->identifier;
}

bool Node::beenVisited() {
    return this->visited;
}

void Node::switchState(){
    this->visited?this->visited = false:this->visited = true;
}

long Node::getWeight() {
    return this->weight;
}

void Node::setWeight(long weight) {
    this->weight = weight;

}

bool Node::operator==(const Node &second) {
    return this->identifier == second.identifier;
}

void Node::clearSettings() {
    this->weight = LONG_MAX;
    this->visited = false;
}

void Node::setPredecessorId(unsigned int id) {
    this->predecessorId = id;

}

unsigned int Node::getPredecessorId() {
    return this->predecessorId;
}

bool Node::operator<(const Node &other) {
    return this->weight < other.weight;
}


