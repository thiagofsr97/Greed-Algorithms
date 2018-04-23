//
// Created by thiagofsr on 22/04/18.
//

#ifndef GREEDYALGORITHMS_NODE_H
#define GREEDYALGORITHMS_NODE_H

#include <string>
#include <map>
#include <climits>
#include <vector>

class Node {
private:
    unsigned int identifier;
    bool visited;
    long weight;
    unsigned int predecessorId;
    std::vector<Node*> neighbors;
public:
    Node(const unsigned int& id);

    void addNeighbor(Node* node);
    std::vector<Node*> getNeighbors();
    unsigned getIdentifier();
    bool beenVisited();
    void switchState();
    long getWeight();
    void setWeight(long weight);
    void setPredecessorId(unsigned int id);
    unsigned int getPredecessorId();
    void clearSettings();

    bool operator==(const Node& other);
    bool operator<(const Node& other);
};

#endif //GREEDYALGORITHMS_NODE_H
