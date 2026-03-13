//
// Created by jakub on 2026-03-13.
//

#include <iostream>
#include "Graph.h"
#include <random>

Graph::Graph(int size) {
    this->size = size;
    // Initialize empty adjacency matrix
    adjMat = new int*[size];
    for (int i = 0; i < size; ++i) {
        adjMat[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            adjMat[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < size; ++i) {
        delete[] adjMat[i];
    }
    delete[] adjMat;
}

int &Graph::at(int from, int to) {
    checkErr(from, to);
    return adjMat[from][to];
}

void Graph::set(int from, int to, int weight) {
    checkErr(from, to);
    adjMat[from][to] = weight;
}

int Graph::get(int from, int to) {
    checkErr(from, to);
    return adjMat[from][to];
}

int Graph::getSize() {
    return size;
}

void Graph::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distWeight(1, 1000);  //Generated weight from 1 to 1000

    // Fill graph with random weights
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j) {
                adjMat[i][j] = distWeight(gen);
            } else {
                adjMat[i][j] = -1;
            }
        }
    }
}

void Graph::print() {
    std::cout<<"==============================="<<std::endl;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            std::cout << adjMat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<"==============================="<<std::endl;
}

void Graph::checkErr(int from, int to) const {
    if(from < 0 || from >= size || to < 0 || to >= size) {
        throw std::out_of_range("Index out of bounds");
    }
}
