#include <iostream>

#include "src/algorithms/BFSolver.h"
#include "src/algorithms/RANDSolver.h"
#include "src/core/FileManager.h"
#include "src/core/Graph.h"

bool nextPermutation(int* arr, int size) {
    int k=-1, l=0;

    // Find largest k for which arr[k] < arr[k+1]. If no index exists, the permutation is the last permutation
    for (int i = 0; i<size-1; i++) {
        if (arr[i] < arr[i+1])
            k = i;
    }
    if (k == -1)
        return false;
    // Find largest l for which arr[k] < arr[l]
    for (int i = 0; i<size; i++) {
        if (arr[k] < arr[i])
            l = i;
    }

    // Swap elements k and l
    int tmp = arr[k];
    arr[k] = arr[l];
    arr[l] = tmp;

    // Reverse from k+1 to size-1
    int start = k+1, end = size-1;
    for (int i = 0; i<=(end-start-1)/2; i++) {
        tmp = arr[start+i];
        arr[start+i] = arr[end-i];
        arr[end-i] = tmp;
    }

    return true;
}


int main() {
    // int size =5;
    // int* arr = new int[5]{0, 1, 2, 3, 4};
    //
    // do {
    //     for (int i =0; i<size; i++) {
    //         std::cout<<arr[i]<<" ";
    //     }
    //     std::cout<<std::endl;
    // } while (nextPermutation(arr, size));

    FileManager fileManager("../data/tsp_6_1", "", "");
    Graph* graph = fileManager.loadGraph();
    // Graph* graph = new Graph(12);
    // graph->generate();
    graph->print();

    BFSolver bfSolver;
    bfSolver.solve(*graph);
    bfSolver.print();

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

// Zrobić interfejs - klasa abstrakcyjna ktora ma solve i cos jeszcze.
// Klasy BFSolver, itd.. Timer, FileManager, Graph, GraphGenerator