//
// Created by jakub on 15.03.2026.
//

#ifndef RNNSOLVER_H
#define RNNSOLVER_H
#include "../include/ISolver.h"


class RNNSolver : public ISolver {
public:
    RNNSolver();
    ~RNNSolver() override;
    void solve(Graph& graph) override;
    void recursiveSolve(Graph& graph, int visited, int currCost,
                        int* currPath, int* unvisitedArr, int& bestCost,
                        int* bestPath);
    void print() override;

    double getPermutations() override;
    int* getAns() override;
    int getCost() override;

private:
    int* ans;
    int size, cost;
};



#endif //RNNSOLVER_H
