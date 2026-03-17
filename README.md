# Asymmetric Travelling Salesman Problem (ATSP) in C++

## Description

This project implements and compares algorithms for solving the Asymmetric Travelling Salesman Problem (ATSP) for complete directed graphs:
File structure was implemented with OOP approach and with modularity in mind.

- **Brute Force (BF):** Checks all possible permutations of cities to find the shortest possible route. Algorithm was written without trying to speed it up using sooner loop breaks.
- **Nearest Neighbour (NN):** Starts from a random vertex and always moves to the nearest unvisited city.
- **Repetitive Nearest Neighbour (RNN):** Runs the recursive version of Nearest Neighbour algorithm from every starting vertex. All same weight edges are visited. 
- **Random Search (RAND):** Generates multiple random paths and selects the shortest one.

The program allows loading a graph from a file or generating a random graph. Algorithm results are saved to a CSV file.

## Input Data

- Text file with a weight matrix (first line: graph size, following lines: weights)
- Option to generate a random graph

## Results

- Results are saved in the `wyniki_jf.csv` file
- Include: iteration, algorithm, graph size, cost, number of permutations, execution time in ms, input data type
- Generated graphs are saved in folder `graphs_jf` as text files named `graph_gen_<NUM>`.
