//
// Created by jakub on 13.03.2026.
//

#include "RANDSolver.h"
#include <iostream>
#include <random>
#include "../include/helpers.h"

RANDSolver::RANDSolver(): ans(nullptr), size(0), cost(-1), permutations(-1) {
}

RANDSolver::~RANDSolver() {
    delete[] ans;
}

void RANDSolver::solve(Graph& graph) {
    // Delete previous answer
    delete[] ans;
    size = graph.getSize();

    int* currPath = new int[size];
    // Assign initial path [0, 1, ..., n-1]
    for (int i =0; i<size; i++) {
        currPath[i] = i;
    }

    int currCost = 0, bestCost = INT_MAX;
    int* bestPath = new int[size];

    std::random_device rd;
    std::mt19937 gen(rd());

    // 10*N random paths
    permutations = 10*size;
    for (int it = 0; it<permutations; it++) {
        currCost = 0;

        // Randomly shuffle vertices
        // Fisher–Yates shuffle Algorithm
        // https://www.geeksforgeeks.org/dsa/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
        // (For each index, starting from the last one, swap it with a random index from the beginning to the current index)
        for (int i = size-1; i>=1; i--) {
            std::uniform_int_distribution<int> distIndex(0, i);
            int swapIndex = distIndex(gen);
            swap(currPath, i, swapIndex);
        }

        // Calculate path cost
        for (int i = 0; i<size-1; i++) {
            currCost += graph.get(currPath[i], currPath[i+1]);
        }
        currCost += graph.get(currPath[size-1], currPath[0]); // From last element to first

        // Compare to the best solution
        if (currCost < bestCost) {
            bestCost = currCost;
            // Copy path
            for (int i = 0; i<size; i++) {
                bestPath[i] = currPath[i];
            }
        }
    }

    delete[] currPath;
    ans = bestPath;
    cost = bestCost;
}

void RANDSolver::print() {
    if (!ans) {
        std::cout<<"No solution found."<<std::endl;
        return;
    }

    std::cout<<"Best RANDOM ALGORITHM path: ";
    for (int i = 0; i<size; i++) {
        std::cout << ans[i] << " ";
    }

    std::cout << "\n\tCost = "<<cost<<std::endl;
    std::cout << "\tPermutations = "<<permutations<<std::endl;
}

int* RANDSolver::getAns() {
    return ans;
}

int RANDSolver::getCost() {
    return cost;
}
