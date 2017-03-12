// File: interpreter.hpp
// Author: Samuel McFalls

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <fstream>
#include "expression.hpp"
#include "environment.hpp"
#include "tokenize.hpp"
#include "interpreter_semantic_error.hpp"

class Interpreter {

public:

	// Default construct an Interpreter with the default environment and an empty AST
	Interpreter();

	// Given a vtscript program as a std::istream, attempt to parse into an internal AST
	// return true on success, false on failure
	bool parse(std::istream & expression) noexcept;

	// Evaluate the current AST and return the resulting Expression
	// throws InterpreterSemanticError if a semantic error is encountered
	// the exception message string should document the nature of the semantic error 
	Expression eval();

	// Saves the state of the environment so it can be restored later
	void saveState();

	// Restores the state of the environment to the last saved point
	void restoreState();

	// Gets the vector of items to be drawn from the last eval()
	// Guaranteed to only contain graphical types
	// @return The vector of items to be drawn
	std::vector<Atom> toBeDrawn();

private:

	Tokenizer tkn;
	Expression AST;
	Environment env;
	Environment save;

	Expression postEval(Expression exp);

};

#endif