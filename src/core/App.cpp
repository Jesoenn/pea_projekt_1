//
// Created by jakub on 15.03.2026.
//

#include "App.h"

#include <iostream>

#include "FileManager.h"
#include "../algorithms/BFSolver.h"
#include "../algorithms/NNSolver.h"
#include "../algorithms/RANDSolver.h"
#include "../algorithms/RNNSolver.h"
#include "../utils/Timer.h"


App::App() {
}

void App::run() {
    // Get input data from user
    Input inputOption = getInputOption();
    std::string inputPath = "";
    int graphSize = 2;
    if(inputOption == Input::FILE)
        inputPath = getInputPath();
    else
        graphSize = getGraphSize();
    Algorithm algorithm = getAlgorithm();
    int permutations = 10;
    if(algorithm == Algorithm::RAND || algorithm == Algorithm::ALL)
        permutations = getPermutations();
    int iterations = getIterations();
    Answer printAnswers = getPrintAnswers();

    // Get graph
    FileManager fileManager(inputPath, "wyniki_jf.csv");
    Graph* graph = nullptr;
    if (inputOption == Input::FILE) {
        graph = fileManager.loadGraph();
    } else {
        graph = new Graph(graphSize);
    }

    for (int i = 0; i < iterations; i++) {
        // Setup graph
        if (inputOption == Input::RANDOM)
            graph->generate();
        std::cout<<"====================================================\n"
                   "Iteracja "<<i<<" z "<<iterations<<"\n"
                   "====================================================\n";
        if (printAnswers == Answer::WITH_GRAPH)
            graph->print();

        // Run algorithms
        if (algorithm == Algorithm::BF || algorithm == Algorithm::ALL)
            runAlgorithm(Algorithm::BF, graph, fileManager, inputOption, i, permutations);
        if (algorithm == Algorithm::NN || algorithm == Algorithm::ALL)
            runAlgorithm(Algorithm::NN, graph, fileManager, inputOption, i, permutations);
        if (algorithm == Algorithm::RNN || algorithm == Algorithm::ALL)
            runAlgorithm(Algorithm::RNN, graph, fileManager, inputOption, i, permutations);
        if (algorithm == Algorithm::RAND || algorithm == Algorithm::ALL)
            runAlgorithm(Algorithm::RAND, graph, fileManager, inputOption, i, permutations);
    }

    delete graph;
    system("PAUSE");
}

void App::runAlgorithm(Algorithm algorithm, Graph* graph, FileManager& fileManager,
                       Input input, int iteration, int permutations) {
    ISolver *solver = nullptr;
    switch (algorithm) {
        case Algorithm::BF: solver = new BFSolver(); break;
        case Algorithm::NN: solver = new NNSolver(); break;
        case Algorithm::RNN: solver = new RNNSolver(); break;
        case Algorithm::RAND: solver = new RANDSolver(permutations); break;
        default: {
            std::cout<<"Niepoprawny wybor algorytmu - ustawiono Brute Force.\n";
            solver = new BFSolver();
        }
    }

    Timer timer;

    timer.start();
    solver->solve(*graph);
    timer.stop();

    solver->print();
    std::cout<<"Czas wykonania: "<<timer.result()<<" ms\n";
    // Sava data to file
    fileManager.saveData(algorithm, graph->getSize(), solver->getPermutations(), timer.result(), input, solver->getCost(), iteration);

    delete solver;
}

Input App::getInputOption() {
    std::cout<<"Sposob wczytania danych:\n\t1. Z pliku\n\t2. Losowo\nWybor: ";
    int input;
    std::cin>>input;
    if(input == 1) {
        return Input::FILE;
    } else if (input == 2) {
        return Input::RANDOM;
    }
    std::cout<<"Niepoprawny wybor - ustawiono losowe dane.\n";
    return Input::RANDOM;
}

std::string App::getInputPath() {
    std::cout<<"Sciezka relatywna do pliku wykonywalnego: ";
    std::string path;
    std::cin>>path;
    return path;
}

int App::getGraphSize() {
    std::cout<<"Rozmiar grafu: ";
    int input;
    std::cin>>input;
    if(input < 2) {
        std::cout<<"Niepoprawny rozmiar grafu - ustawiono 2.\n";
        return 2;
    }
    return input;
}

Algorithm App::getAlgorithm() {
    std::cout<<"Wybor algorytmu:\n\t1. Brute Force\n\t2. Nearest Neighbour\n\t3. Repetitive Nearest Neighbour\n\t4. Random Search\n\t5. Wszystkie z powyzszych\nWybor: ";
    int input;
    std::cin>>input;
    switch (input) {
        case 1: return Algorithm::BF;
        case 2: return Algorithm::NN;
        case 3: return Algorithm::RNN;
        case 4: return Algorithm::RAND;
        case 5: return Algorithm::ALL;
        default: {
            std::cout<<"Niepoprawny wybor - ustawiono Brute Force.\n";
            return Algorithm::BF;
        }
    }
}

int App::getIterations() {
    std::cout<<"Liczba iteracji algorytmu: ";
    int input;
    std::cin>>input;
    if(input < 1) {
        std::cout<<"Niepoprawna liczba iteracji - ustawiono 1.\n";
        return 1;
    }
    return input;
}

Answer App::getPrintAnswers() {
    std::cout<<"Przedstawienie wyniku: \n\t1. Koszt oraz sciezka\n\t2. Koszt i sciezka z pelnym grafem\nWybor: ";
    int input;
    std::cin>>input;
    switch (input) {
        case 1: return Answer::COST_PATH;
        case 2: return Answer::WITH_GRAPH;
        default: {
            std::cout<<"Niepoprawny wybor - ustawiono koszt oraz sciezke.\n";
            return Answer::COST_PATH;
        }
    }
}

int App::getPermutations() {
    std::cout<<"Liczba permutacji (wielokrotnosc N) dla algorytmu losowego: ";
    int input;
    std::cin>>input;
    if(input < 1) {
        std::cout<<"Niepoprawna liczba permutacji - ustawiono 10.\n";
        return 10;
    }
    return input;
}
