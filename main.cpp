#include <iostream>

#include "src/algorithms/BFSolver.h"
#include "src/algorithms/NNSolver.h"
#include "src/algorithms/RANDSolver.h"
#include "src/algorithms/RNNSolver.h"
#include "src/core/FileManager.h"
#include "src/core/Graph.h"

int main() {
    FileManager fileManager("../data/tsp_6_1", "", "");
    Graph* graph = fileManager.loadGraph();
    // Graph* graph = new Graph(11);
    graph->generate();
    graph->print();

    BFSolver bfSolver;
    bfSolver.solve(*graph);
    bfSolver.print();

    NNSolver nnSolver;
    nnSolver.solve(*graph);
    nnSolver.print();

    RNNSolver rnnSolver;
    rnnSolver.solve(*graph);
    rnnSolver.print();

    RANDSolver randSolver;
    randSolver.solve(*graph);
    randSolver.print();

    return 0;
}



// ATSP - Asymmetric Traveling Salesman Problem
// Macierz sasiedstwa n x n (FROM(row) - TO(col))
// Algorytmy:
// 1. Brute Force - O(n!)
// 2. Nearest Neighbour - O(n^2)
// 3. Repetetive Nearest Neighbour - O(n^3)
// 4. Random Search - O(n^2) - losowe permutacje

// Założenia:
// 1. Graf pełny - waga INT
// 2. Odwiedzenie kazdego miasta tylko raz i powrot na start