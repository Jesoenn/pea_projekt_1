//
// Created by jakub on 12.03.2026.
//

#ifndef SOLVER_H
#define SOLVER_H

#include "../core/Graph.h"

class ISolver {
public:
    virtual ~ISolver() = default;
    virtual void solve(Graph& graph) = 0;
    virtual int* getAns() = 0;
    virtual int getCost() = 0;
    virtual double getPermutations() = 0;
    virtual void print() = 0;
};


#endif //SOLVER_H
