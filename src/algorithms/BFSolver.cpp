//
// Created by jakub on 13.03.2026.
//

#include "BFSolver.h"
#include <climits>
#include <iostream>
#include "../include/helpers.h"

BFSolver::BFSolver(): ans(nullptr), size(0), cost(-1), permutations(-1) {
}

BFSolver::~BFSolver() {
    delete[] ans;
}

void BFSolver::solve(Graph& graph) {
    // Delete previous answer
    delete[] ans;
    size = graph.getSize();

    // Assign initial path [0, 1, ..., n-1]
    int* currPath = new int[size];
    for (int i =0; i<size; i++) {
        currPath[i] = i;
    }

    int currCost = 0, bestCost = INT_MAX;
    int* bestPath = new int[size];

    // Brute Force Algorithm
    permutations = 0;
    do {
        permutations++;
        // Calculate path weight for current path
        currCost = 0;
        for (int i = 0; i<size-1; i++) {
            currCost += graph.get(currPath[i], currPath[i+1]);
        }
        currCost += graph.get(currPath[size-1], currPath[0]); // From last element to first

        // Compare to best solution
        if (currCost < bestCost) {
            bestCost = currCost;
            // Copy path
            for (int i = 0; i<size; i++) {
                bestPath[i] = currPath[i];
            }
        }
    } while (nextPermutation(currPath, size)); // While next permutation exists

    delete[] currPath;
    ans = bestPath;
    cost = bestCost;
}

void BFSolver::print() {
    if (!ans) {
        std::cout<<"No solution found."<<std::endl;
        return;
    }

    std::cout<<"Best BRUTE FORCE ALGORITHM path: ";
    for (int i = 0; i<size; i++) {
        std::cout << ans[i] << " ";
    }

    std::cout << "\n\tCost = "<<cost<<std::endl;
    std::cout << "\tPermutations = "<<permutations<<std::endl;
}

int* BFSolver::getAns() {
    return ans;
}

int BFSolver::getCost() {
    return cost;
}

// Narayana Algorithm For Next Lexicographic Permutation
// https://planetcalc.com/8520/
bool BFSolver::nextPermutation(int* arr, int size) {
    int k = -1, l = 0;

    // Find largest k for which arr[k] < arr[k+1]. If no index exists, the permutation is the last permutation
    for (int i = 0; i<size-1; i++) {
        if (arr[i] < arr[i+1])
            k = i;
    }
    if (k == -1)
        return false;
    // Find largest l for which arr[k] < arr[l]
    for (int i = 0; i<size; i++) {
        if (arr[k] < arr[i])
            l = i;
    }

    // Swap elements k and l
    swap(arr, k, l);

    // Reverse array from index k+1 to size-1
    int start = k+1, end = size-1;
    for (int i = 0; i<=(end-start-1)/2; i++) {
        swap(arr, start+i, end-i);
    }

    return true;
}
