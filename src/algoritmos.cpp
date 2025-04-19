#include "algoritmos.h"
#include <cmath>
#include <limits>

// Funcion incluida en la tarea
double calculateDistance(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

/*
 * Fuerza Bruta:
 * Queremos tomar cada par de puntos en el plano
 * y calcular la distancia, retornamos la menor.
 *
 * Calcular distancia entre 2 puntos: O(1)
 * Calculamos distancia de n(n+1)/2 puntos: O(n^2)
 */

double distanciaMinimaBruta(const Plano &S) {

    double dist_min = std::numeric_limits<double>::max();

    for (int i = 0; i < S.size(); i++) {
        for (int j = i + 1; j < S.size(); j++) {
            double d = calculateDistance(S[i], S[j]);
            if (d < dist_min) {
                dist_min = d;
            }
        }
    }

    return dist_min;
}