#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include "algoritmos.h"

/*
 * Objetivo:
 * Dado S un conjunto con n puntos en el plano, encontrar
 * la distancia minima entre 2 puntos
 */

// Point = Par x,y (typedef pair<double,double>)
// Plano = 'S' conjunto de puntos (typedef vector<point>)

// LLena el Plano con (x_i,y_i) i = 1,...,n
// ayuda de LLM
void popularPlano(Plano &s, int n) {
    int side = static_cast<int>(std::ceil(std::sqrt(n)));
    int count = 0;
    for (int i = 1; i < side + 1 && count < n; ++i) {
        for (int j = 1; j < side + 1 && count < n; ++j) {
            s.emplace_back(i, j);
            ++count;
        }
    }
}

void printPlano(const Plano &S) {
    for (auto & i : S) {
        std::cout << '(' << i.first << ',' << i.second << ')' << std::endl;
    }
}

int main() {

    int size_plano = 16;
    Plano plano;
    plano.reserve(size_plano);
    popularPlano(plano, size_plano);
    printPlano(plano);

    std::cout << distanciaMinimaBruta(plano) << std::endl;
    return 0;
}