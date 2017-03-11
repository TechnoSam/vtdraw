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
	typedef enum e_Env {NONE, BOOL, NUMBER, POINT, LINE, ARC, FPTR_BOOL, FPTR_NUMBER, FPTR_POINT, FPTR_LINE, FPTR_ARC} Type;

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a bool output
	typedef bool(*fptrBool)(std::vector<Atom>);

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a double output
	typedef double(*fptrNumber)(std::vector<Atom>);

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a point output
	typedef Point(*fptrPoint)(std::vector<Atom>);

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a line output
	typedef Line(*fptrLine)(std::vector<Atom>);

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces an arc output
	typedef Arc(*fptrArc)(std::vector<Atom>);

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

	// Contructs an entry with a fptrPoint
	// Set the type to FPTR_POINT
	// @param func The function store
	EnvEntry(fptrPoint func);

	// Contructs an entry with a fptrLine
	// Set the type to FPTR_LINE
	// @param func The function store
	EnvEntry(fptrLine func);

	// Contructs an entry with a fptrArc
	// Set the type to FPTR_ARC
	// @param func The function store
	EnvEntry(fptrArc func);

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

	// Gets the FPTR_POINT value of an EnvEntry
	// @return The FPTR_POINT value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type FPTR_POINT
	fptrPoint getFptrPoint();

	// Gets the FPTR_LINE value of an EnvEntry
	// @return The FPTR_LINE value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type FPTR_LINE
	fptrLine getFptrLine();

	// Gets the FPTR_ARC value of an EnvEntry
	// @return The FPTR_ARC value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type FPTR_ARC
	fptrArc getFptrArc();

private:

	Type type;

	bool boolVal;

	double numberVal;

	Point pointVal;

	Line lineVal;

	Arc arcVal;

	fptrBool boolFunc;

	fptrNumber numberFunc;

	fptrPoint pointFunc;

	fptrLine lineFunc;

	fptrArc arcFunc;

};

#endif