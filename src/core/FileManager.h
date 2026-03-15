//
// Created by jakub on 13.03.2026.
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>

#include "Graph.h"


class FileManager {
public:
    FileManager(std::string inputFileName, std::string outputFileName);

    Graph* loadGraph();
    // void saveData(); algorithm/size/time

private:
    std::string inputFileName, outputFileName;
};



#endif //FILEMANAGER_H
