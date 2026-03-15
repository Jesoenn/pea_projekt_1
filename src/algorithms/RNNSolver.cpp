//
// Created by jakub on 15.03.2026.
//

#include "RNNSolver.h"

#include <iostream>

RNNSolver::RNNSolver(): ans(nullptr), size(0), cost(-1) {
}

RNNSolver::~RNNSolver() {
    delete[] ans;
}

void RNNSolver::solve(Graph& graph) {
    // TODO:
    /*
w algorytmie RNN należy uwzględnić możliwość istnienia dla każdego węzła krawędzi o takich
samych kosztach (wagach), co oznacza, że należy sprawdzić każdą z możliwości wyboru, a nie
tylko jedną wybraną. W praktyce należy zapamiętać taki węzeł i dokończyć poszukiwanie ścieżki
z tego węzła, tyle razy, ile krawędzi o tej samej wadze jest dostępnych.
     */




}

void RNNSolver::print() {
    if (!ans) {
        std::cout<<"No solution found."<<std::endl;
        return;
    }

    std::cout<<"Best REPETITIVE NEAREST NEIGHBOUR ALGORITHM path: ";
    for (int i = 0; i<size; i++) {
        std::cout << ans[i] << " ";
    }

    std::cout << "\n\tCost = "<<cost<<std::endl;
}

double RNNSolver::getPermutations() {
    return -1.;
}

int* RNNSolver::getAns() {
    return ans;
}

int RNNSolver::getCost() {
    return cost;
}
