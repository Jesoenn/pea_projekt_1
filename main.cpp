#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
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
