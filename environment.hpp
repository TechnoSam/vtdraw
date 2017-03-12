// File: environment.hpp
// Author: Samuel McFalls

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>
#include <math.h>

#include "proc.hpp"
#include "interpreter_semantic_error.hpp"
#include "env_entry.hpp"

class Environment {

public:

	// Default constructor
	// Pre-loads the environment with the required symbols and procedures
	Environment();

	// Defines a symbol in the environment
	// @param symbol The key associated with the value to store
	// @param entry The value to store
	// @throw InterpreterSemanticError if the symbol is already defined
	void define(std::string symbol, EnvEntry entry);

	// Gets the value associated with a symbol
	// @param symbol The key associated with the desired value
	// @return The value associated with the given key
	// @throw InterpreterSemanticError if the symbol is not found
	EnvEntry fetch(std::string symbol);

	// Checks if a symbol is defined
	// @param symbol The key to check
	// return True if the key is defined, false otherwise
	bool exists(std::string symbol);

	// Clears the vector of graphical items to be drawn
	void clearToDraw();
	
	// Adds an item to the vector of items to be drawn
	// @param item The item to add
	// @throw logic_error if item is not graphical type
	void addDraw(Atom item);

	// Gets the vector of graphical items to be drawn
	// @return The vector of items to be drawn
	std::vector<Atom> toBeDrawn();

private:

	std::unordered_map<std::string, EnvEntry> env;
	std::vector<Atom> toDraw;

};

#endif