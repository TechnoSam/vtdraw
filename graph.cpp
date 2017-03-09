// File: graph.cpp
// Author: Samuel McFalls

#include "graph.hpp"
#include <tuple>

Point makePoint(double x, double y) {

	return std::make_tuple(x, y);

}

Line makeLine(Point first, Point second) {

	Line ret;
	ret.first = first;
	ret.second = second;

	return ret;

}

Arc makeArc(Point center, Point start, double span) {

	Arc ret;
	ret.center = center;
	ret.start = start;
	ret.span = span;

	return ret;

}

double pointX(Point point) {

	return std::get<0>(point);

}

double pointY(Point point) {

	return std::get<1>(point);

}