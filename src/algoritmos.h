#pragma once
#include <utility>
#include <vector>

typedef std::pair<double,double> Point;
typedef std::vector<Point> Plano;

double calculateDistance(const Point &p1, const Point &p2);

void popularPlano(Plano &s, const int n);

void popularPlanoAleatorio(Plano &s, const int n);

void printPlano(const Plano &S);

double distanciaMinimaBruta(const Plano &S);

double distanciaMinimaDC(const Plano &S);

double distanciaMinimaDCRecursiva(const Plano &px, const Plano &py);
