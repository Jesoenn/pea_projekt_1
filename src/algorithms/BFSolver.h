//
// Created by jakub on 13.03.2026.
//

#ifndef BFSOLVER_H
#define BFSOLVER_H

#include "../include/ISolver.h"

class BFSolver : public ISolver {
public:
    BFSolver();
    ~BFSolver() override;
    void solve(Graph& graph) override;
    void print() override;

    int* getAns() override;
    int getCost() override;

private:
    int* ans;
    int size, cost;
    double permutations;

    bool nextPermutation(int* arr, int size);
};



#endif //BFSOLVER_H
