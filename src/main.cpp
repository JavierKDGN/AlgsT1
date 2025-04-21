#include <iostream>
#include <vector>


#include "algoritmos.h"

/*
 * Objetivo:
 * Dado S un conjunto con n puntos en el plano, encontrar
 * la distancia minima entre 2 puntos
 */

// Point = Par x,y (typedef pair<double,double>)
// Plano = 'S' conjunto de puntos (typedef vector<point>)

int main() {

    Plano plano;
    popularPlanoAleatorio(plano, 64);
    printPlano(plano);

    std::cout << "\n Distancia minima:" << "\n";

    double dist_bruta = distanciaMinimaBruta(plano);
    double dist_dc = distanciaMinimaDC(plano);

    std::cout << "Bruta: " << dist_bruta << "\n";
    std::cout << "DC: " << dist_dc << "\n";

    return 0;
}