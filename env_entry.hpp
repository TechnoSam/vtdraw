// File: EnvEntry.hpp
// Author: Samuel McFalls

#ifndef ENVENTRY_H
#define ENVENTRY_H

#include <vector>

#include "atom.hpp"
#include "graph.hpp"

class EnvEntry {

public:

	// Typdef for the possible types of Environment Entry
	typedef enum e_Env {NONE, BOOL, NUMBER, POINT, LINE, ARC, FPTR_BOOL, FPTR_NUMBER} Type;

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a bool output
	typedef bool(*fptrBool)(std::vector<Atom>);

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a double output
	typedef double(*fptrNumber)(std::vector<Atom>);

	// Default constructor
	// Type NONE with no value
	EnvEntry();

	// Contructs an entry with a bool
	// Set the type to BOOL
	// @param value The value store
	EnvEntry(bool value);

	// Contructs an entry with a double
	// Set the type to NUMBER
	// @param value The value store
	EnvEntry(double value);

	// Contructs an entry with a point
	// Set the type to POINT
	// @param value The value store
	EnvEntry(Point value);

	// Contructs an entry with a line
	// Set the type to LINE
	// @param value The value store
	EnvEntry(Line value);

	// Contructs an entry with a arc
	// Set the type to ARC
	// @param value The value store
	EnvEntry(Arc value);

	// Contructs an entry with a fptrBool
	// Set the type to FPTR_BOOL
	// @param func The function store
	EnvEntry(fptrBool func);

	// Contructs an entry with a fptrNumber
	// Set the type to FPTR_NUMBER
	// @param func The function store
	EnvEntry(fptrNumber func);

	// Gets the type of an EnvEntry
	// @return The type of the EnvEntry
	Type getType();

	// Gets the BOOL value of an EnvEntry
	// @return The BOOL value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type BOOL
	bool getBool();

	// Gets the NUMBER value of an EnvEntry
	// @return The NUMBER value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type NUMBER
	double getNumber();

	// Gets the POINT value of an EnvEntry
	// @return The POINT value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type POINT
	Point getPoint();

	// Gets the LINE value of an EnvEntry
	// @return The LINE value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type LINE
	Line getLine();

	// Gets the ARC value of an EnvEntry
	// @return The ARC value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type ARC
	Arc getArc();

	// Gets the FPTR_BOOL value of an EnvEntry
	// @return The FPTR_BOOL value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type FPTR_BOOL
	fptrBool getFptrBool();

	// Gets the FPTR_NUMBER value of an EnvEntry
	// @return The FPTR_NUMBER value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type FPTR_NUMBER
	fptrNumber getFptrNumber();

private:

	Type type;

	bool boolVal;

	double numberVal;

	Point pointVal;

	Line lineVal;

	Arc arcVal;

	fptrBool boolFunc;

	fptrNumber numberFunc;

};

#endif