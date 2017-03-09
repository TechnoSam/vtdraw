// File: graph.cpp
// Author: Samuel McFalls

#include "graph.hpp"
#include <tuple>

Point makePoint(double, double) {

	return std::make_tuple(0., 0.);

}

Line makeLine(Point, Point) {

	Line ret;

	return ret;

}

Arc makeArc(Point, Point, double) {

	Arc ret;

	return ret;

}

double pointX(Point) {

	return 0;

}

double pointY(Point) {

	return 0;

}