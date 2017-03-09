// File: graph.hpp
// Author: Samuel McFalls

#ifndef GRAPH_H
#define GRAPH_H

#include <tuple>

typedef std::tuple<double, double> Point;

typedef struct {
	Point first;
	Point second;
} Line;

typedef struct {
	Point center;
	Point start;
	double span;
} Arc;

Point makePoint(double, double);

Line makeLine(Point, Point);

Arc makeArc(Point, Point, double);

double pointX(Point);

double pointY(Point);

#endif