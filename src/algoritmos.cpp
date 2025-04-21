#include "algoritmos.h"
#include <utility>
#include <cmath>
#include <random>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iostream>

// Funcion incluida en la tarea
double calculateDistance(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

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

    // No queremos entradas repetidas
    std::set<Point> entradas;

    while (s.size() < n) {
        int x = dist(gen);
        int y = dist(gen);
        Point p(x,y);

        // Insercion correcta
        if (entradas.insert(p).second) {
            s.push_back(p);
        }
    }


}

void printPlano(const Plano &S) {
    for (auto & i : S) {
        std::cout << '(' << i.first << ',' << i.second << ')' << std::endl;
    }
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
            dist_min = std::min(d, dist_min);
        }
    }

    return dist_min;
}

// Funcion para preparar la busqueda, primero ordenamos el plano por sus ejes
double distanciaMinimaDC(const Plano &S) {
    Plano px = S;
    Plano py = S;

    // Sorteamos px por coord x
    std::sort(px.begin(), px.end(), [](const Point& a, const Point& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    // Sorteamos py por coord y
    std::sort(py.begin(), py.end(), [](const Point& a, const Point& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    return distanciaMinimaDCRecursiva(px,py);
}

double distanciaMinimaDCRecursiva(const Plano &px, const Plano &py) {
    int n = px.size();

    // Caso base: Si el plano es muy chico, usamos fuerza bruta
    if (n <= 3) {
        return distanciaMinimaBruta(px);
    }

    // Dividimos el plano en 2
    int mediana = n / 2;
    Point punto_medio = px[mediana - 1];
    double x_linea_media = punto_medio.first;

    // Declaramos las mitades
    Plano px_l(px.begin(), px.begin() + mediana);
    Plano px_r(px.begin() + mediana, px.end());

    // Lo mismo pero ordenados en y
    Plano py_l, py_r;
    for (const auto &p : py) {
        // Puntos a la izquierda o en la linea se van a py_l
        if (p.first <= x_linea_media) {
            py_l.push_back(p);
        } else {
            py_r.push_back(p);
        }
    }

    // Conquistamos
    double delta_l = distanciaMinimaDCRecursiva(px_l, py_l);
    double delta_r = distanciaMinimaDCRecursiva(px_r, py_r);
    double delta = std::min(delta_l, delta_r);

    // Combinamos
    // Buscamos en el strip (puntos dentro del delta de x_linea_media)
    Plano strip_y;

    for (const auto&p : py) {
        if (std::abs(p.first - x_linea_media) < delta) {
            strip_y.push_back(p);
        }
    }

    double min_strip_dist = delta;
    for (int i = 0; i < strip_y.size(); i++) {
        for (int j = i + 1; j < strip_y.size() && (strip_y[j].second - strip_y[i].second < min_strip_dist); j++) {
            double d = calculateDistance(strip_y[i], strip_y[j]);
            min_strip_dist = std::min(min_strip_dist, d);
        }
    }

    return min_strip_dist;
}