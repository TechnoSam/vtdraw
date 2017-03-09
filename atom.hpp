// File: Atom.hpp
// Author: Samuel McFalls

#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <tuple>
#include <stdexcept>

#include "graph.hpp"

class Atom {

public:

	// Constructs an Atom of type NONE
	Atom();

	// Constructs an Atom of type BOOL
	// @param value The value to set
	Atom(bool value);

	// Constructs an Atom of type NUMBER
	// @param value The value to set
	Atom(double value);

	// Constructs an Atom of type SYMBOL
	// @param value The value to set
	Atom(const std::string& value);

	// Constructs an Atom of type POINT
	// @param value The value to set
	Atom(Point value);

	// Constructs an Atom of type LINE
	// @param value The value to set
	Atom(Line value);
	
	// Constructs an Atom of type ARC
	// @param value The value to set
	Atom(Arc value);

	// The possible types of Atom
	typedef enum e_AtomType {NONE, BOOL, NUMBER, SYMBOL, POINT, LINE, ARC} Type;
	
	// Gets the type of an Atom
	// @return The type of the Atom
	Type getType();

	// Gets the BOOL value of an Atom
	// @return The BOOL value of the Atom
	// @throw logic_error if Atom is not of type BOOL
	bool getBool();

	// Gets the NUMBER value of an Atom
	// @return The NUMBER value of the Atom
	// @throw logic_error if Atom is not of type NUMBER
	double getNumber();
	
	// Gets the SYMBOL value of an Atom
	// @return The SYMBOL value of the Atom
	// @throw logic_error if Atom is not of type SYMBOL
	std::string getSymbol();

	// Gets the POINT value of an Atom
	// @return The POINT value of the Atom
	// @throw logic_error if Atom is not of type POINT
	Point getPoint();

	// Gets the LINE value of an Atom
	// @return The LINE value of the Atom
	// @throw logic_error if Atom is not of type LINE
	Line getLine();

	// Gets the ARC value of an Atom
	// @return The ARC value of the Atom
	// @throw logic_error if Atom is not of type ARC
	Arc getArc();

	// Overloaded equality operator
	// @return True if the atoms have equal type and value
	bool operator==(const Atom& rhs) const noexcept;

	// Overloaded inequality operator
	// @return True if the atoms have different types or values
	bool operator!=(const Atom& rhs) const noexcept;

private:

	Type type;

	bool boolVal;

	double numberVal;

	std::string symbolVal;

	Point pointVal;

	Line lineVal;

	Arc arcVal;

};

#endif