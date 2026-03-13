//
// Created by jakub on 2026-03-13.
//

#ifndef PEA_PROJEKT1_GRAPH_H
#define PEA_PROJEKT1_GRAPH_H


class Graph {
public:
    Graph(int size);
    ~Graph();

    void print();

    int &at(int from, int to);
    void set(int from, int to, int weight);
    int get(int from, int to);

    int getSize();

    void generate();

private:
    int size;
    int** adjMat;

    void checkErr(int from, int to) const;
};


#endif //PEA_PROJEKT1_GRAPH_H
