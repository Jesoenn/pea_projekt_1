//
// Created by jakub on 13.03.2026.
//

#include "NNSolver.h"

#include <iostream>

NNSolver::NNSolver(): ans(nullptr), size(0), cost(-1) {
}

NNSolver::~NNSolver() {
    delete[] ans;
}

void NNSolver::solve(Graph& graph) {
    // TODO: NAJPIERW ZOBACZYC KSIAZKE
    // Nowoczesna heurystyka
    // str 87 Metody wyliczeniowe TSP
    // brute-force iteracyjny + rekurencyjny
    //
    // str 117 zachłanny
    // najbliższy sąsiad
    //
    // TODO: ZOBACZYC STRONY:
    // https://openstax.org/books/contemporary-mathematics/pages/12-9-traveling-salesperson-problem
    // https://swistak.codes/post/problem-komiwojazera/
    // TODO: zobaczyc pdfy wyslane z1_z2
    // TODO: WYMYSLEC JAK ROZWIAZAC ALGORYTM

}

void NNSolver::print() {
    if (!ans) {
        std::cout<<"No solution found."<<std::endl;
        return;
    }

    std::cout<<"Best NEAREST NEIGHBOUR ALGORITHM path: ";
    for (int i = 0; i<size; i++) {
        std::cout << ans[i] << " ";
    }

    std::cout << "\n\tCost = "<<cost<<std::endl;
}

int* NNSolver::getAns() {
    return ans;
}

int NNSolver::getCost() {
    return cost;
}
