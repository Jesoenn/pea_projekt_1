//
// Created by jakub on 13.03.2026.
//

#ifndef RANDSOLVER_H
#define RANDSOLVER_H

#include "../include/ISolver.h"

class RANDSolver : public ISolver{
public:
    RANDSolver(int permutations);
    ~RANDSolver() override;
    void solve(Graph& graph) override;
    void print() override;

    double getPermutations() override;
    int* getAns() override;
    int getCost() override;

private:
    int* ans;
    int size, cost;
    double permutations;
};



#endif //RANDSOLVER_H



// DLA WYBRANEJ LICZBY PERMUTACJI -> 10N ?