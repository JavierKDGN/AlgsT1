#pragma once
#include <utility>
#include <vector>

typedef std::pair<double,double> Point;
typedef std::vector<Point> Plano;

double calculateDistance(const Point &p1, const Point &p2);

double distanciaMinimaBruta(const Plano &S);

