// File: graph.hpp
// Author: Samuel McFalls

#ifndef GRAPH_H
#define GRAPH_H

#include <tuple>

// Define a Point as a tuple of two doubles
typedef std::tuple<double, double> Point;

// Define a Line as a struct with two points
typedef struct {
	Point first;
	Point second;
} Line;

// Define an Arc as a struct with two points and a number
typedef struct {
	Point center;
	Point start;
	double span;
} Arc;

// Creates a point
// @param x The x value of the point to create
// @param y The y value of the point to create
// @return The created point
Point makePoint(double x, double y);

// Creates a line
// @param first The first point in the line to create
// @param second The second point in the line to create
// @return The created line
Line makeLine(Point first, Point second);

// Creates an arc
// @param center The center of the circle in the arc to create
// @param start The starting point of the arc to create
// @param span The span in radians of the arc
// @return The created arc
Arc makeArc(Point center, Point start, double span);

// Gets the x-value of a point
// Needed because of tuple representation
// @param point The point to get the x-value from
// @return The x value of point
double pointX(Point point);

// Gets the y-value of a point
// Needed because of tuple representation
// @param point The point to get the y-value from
// @return The y value of point
double pointY(Point point);

#endif