//
// Created by jakub on 13.03.2026.
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>

#include "Graph.h"
#include "../include/algorithms.h"
#include "../include/inputs.h"


class FileManager {
public:
    FileManager(std::string inputFileName, std::string outputFileName);

    Graph* loadGraph();
    void saveData(Algorithm algorithm, int size, double permutations, int time, Input input, int cost, int iteration);

private:
    std::string inputFileName, outputFileName;

    static std::string inputToString(Input input);
    static std::string algorithmToString(Algorithm algorithm);
};



#endif //FILEMANAGER_H
