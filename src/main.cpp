#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <random>

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
void popularPlano(Plano &s, const int n) {
    s.clear();
    int side = static_cast<int>(std::ceil(std::sqrt(n)));
    int count = 0;
    for (int i = 1; i < side + 1 && count < n; ++i) {
        for (int j = 1; j < side + 1 && count < n; ++j) {
            s.emplace_back(i, j);
            ++count;
        }
    }
}

void popularPlanoAleatorio(Plano &s, const int n) {
    s.clear();
    // RNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1,100);

    for (int i = 0; i < n; i++) {
        double x = dist(gen);
        double y = dist(gen);
        s.emplace_back(x, y);
    }
}

void printPlano(const Plano &S) {
    for (auto & i : S) {
        std::cout << '(' << i.first << ',' << i.second << ')' << std::endl;
    }
}

int main() {

    Plano plano;
    popularPlanoAleatorio(plano, 256);
    printPlano(plano);

    std::cout << "\n Distancia minima:" << "\n";

    double dist_bruta = distanciaMinimaBruta(plano);
    double dist_dc = distanciaMinimaDC(plano);

    std::cout << "Bruta: " << dist_bruta << "\n";
    std::cout << "DC: " << dist_dc << "\n";

    return 0;
}