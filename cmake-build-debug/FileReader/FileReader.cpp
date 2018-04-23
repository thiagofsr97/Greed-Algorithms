//
// Created by thiagofsr on 22/04/18.
//


#include <sstream>
#include "FileReader.h"

FileReader::FileReader(const std::string &pathFile) {
    this->inputFile = new std::fstream(pathFile,std::ios::in);
    if(!inputFile->is_open()){
        std::cout << "Error opening file, check path.\n";
        exit(1);
    }

}

FileReader::~FileReader() {
    delete this->inputFile;

}

Graph *FileReader::createGraph() {
    int offset = 1;
    int currentLine = 0;
    int j;
    int matrixSize = 0;
    std::string line,numbers;
    getline(*inputFile,line);
    std::vector<std::string> weights;
    matrixSize = std::stoi(line);
    Graph *graph = new Graph(matrixSize);

    for(int i = 0; i < matrixSize;i++)
        graph->addNode(new Node(i));

    while(!inputFile->eof()){
      getline(*inputFile,line);
      if(!line.empty()){
          std::stringstream ss{line};

          while(ss >> numbers) weights.push_back(numbers);

          for( j = 0; j <offset;j++){
            if(j == currentLine){
                //One node is not neighbor to itself
                graph->setWeightMatrix((unsigned int)currentLine,(unsigned int)j,0);
            }
          }

          while(!weights.empty()){
              //setting the adjacency matrix
              graph->setWeightMatrix((unsigned int)currentLine,(unsigned int)(j),std::stol(weights.front()));
              graph->setWeightMatrix((unsigned int)(j),(unsigned int)currentLine,std::stol(weights.front()));

              //setting neighbors of a node
              graph->getNode((unsigned int)currentLine)->addNeighbor(graph->getNode((unsigned int)j));
              graph->getNode((unsigned int)j)->addNeighbor(graph->getNode((unsigned int)currentLine));


              weights.erase(weights.begin());
              j++;

          }

          currentLine++;
          offset++;


      }
    }

//    graph->showMatrix();
//    graph->showNeighbors();

    return graph;
}


