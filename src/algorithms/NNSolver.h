//
// Created by jakub on 13.03.2026.
//

#ifndef NNSOLVER_H
#define NNSOLVER_H
#include "../include/ISolver.h"


class NNSolver : public ISolver {
public:
    NNSolver();
    ~NNSolver() override;
    void solve(Graph& graph) override;
    void print() override;

    int* getAns() override;
    int getCost() override;

private:
    int* ans;
    int size, cost;
};



#endif //NNSOLVER_H
