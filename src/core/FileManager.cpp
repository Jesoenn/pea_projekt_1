//
// Created by jakub on 13.03.2026.
//

#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <utility>

FileManager::FileManager(std::string inputFileName, std::string outputFileName):
    inputFileName(std::move(inputFileName)), outputFileName(std::move(outputFileName)) {
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

void FileManager::saveData(Algorithm algorithm, int size, double permutations, int time, Input input, int cost, int iteration) {
    std::ofstream file(outputFileName, std::ios_base::app);
    if (!file.is_open())
        throw std::invalid_argument("File could not be opened");

    file << iteration << ";" << algorithmToString(algorithm) << ";" << size << ";" << cost << ";" << permutations
        << ";" << time << ";" << inputToString(input) << "\n";
    file.close();
}

std::string FileManager::inputToString(Input input) {
    switch(input){
        case Input::RANDOM: return "RANDOM";
        case Input::FILE: return "FILE";
        default: return "ERROR";
    }
}

std::string FileManager::algorithmToString(Algorithm algorithm) {
    switch (algorithm) {
        case Algorithm::BF: return "BF";
        case Algorithm::NN: return "NN";
        case Algorithm::RAND: return "RAND";
        case Algorithm::RNN: return "RNN";
        default: return "ERROR";
    }
}

