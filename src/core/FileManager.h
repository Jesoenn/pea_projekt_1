//
// Created by jakub on 13.03.2026.
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>

#include "Graph.h"
#include "../include/algorithms.h"


class FileManager {
public:
    FileManager(std::string inputFileName, std::string outputFileName);

    Graph* loadGraph();
    void saveData(Algorithm algorithm, int size, double permutations, int time);

private:
    std::string inputFileName, outputFileName;
};



#endif //FILEMANAGER_H
