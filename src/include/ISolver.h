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
};


#endif //SOLVER_H
