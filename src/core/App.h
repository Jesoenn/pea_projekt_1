//
// Created by jakub on 15.03.2026.
//

#ifndef APP_H
#define APP_H
#include <string>

#include "FileManager.h"
#include "Graph.h"
#include "../include/algorithms.h"
#include "../include/answers.h"
#include "../include/inputs.h"
#include "../include/ISolver.h"


class App {
public:
    App();
    void run();

private:
    Input getInputOption();
    std::string getInputPath();
    int getGraphSize();
    Algorithm getAlgorithm();
    int getIterations();
    Answer getPrintAnswers();
    int getPermutations();

    void runAlgorithm(Algorithm algorithm, Graph* graph, FileManager& fileManager,
                      Input input, int iteration, int permutations);

};



#endif //APP_H
