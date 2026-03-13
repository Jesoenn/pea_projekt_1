//
// Created by jakub on 13.03.2026.
//

#include "FileManager.h"

#include <fstream>
#include <iostream>
#include <utility>

FileManager::FileManager(std::string inputFileName, std::string outputFileName, std::string saveDataFileName):
    inputFileName(std::move(inputFileName)), outputFileName(std::move(outputFileName)), saveDataFileName(std::move(saveDataFileName)) {
}

Graph* FileManager::loadGraph() {
    std::ifstream file(inputFileName);
    if (!file.is_open())
        throw std::invalid_argument("File could not be opened");

    std::string in;

    file >> in; // Read graph size;
    int size = std::stoi(in);
    Graph* graph = new Graph(size);

    int row = 0, col = 0;
    // Fill graph
    while (file >> in) {
        if (col >= size) {
            row++;
            col = 0;
        }

        graph->at(row, col) = std::stoi(in);
        col++;
    }
    file.close();
    return graph;
}
