// File: vtscript.cpp
// Description: Defines the entry point for the vtscript program.

#include <iostream>
#include <sstream>
#include <fstream>
#include "interpreter.hpp"

bool runLine(std::string program, Interpreter& interp);
bool run(std::istream& program, Interpreter& interp);

int main(int argc, char* argv[]) {

	Interpreter interp;

	std::string usage = "Usage: vtscript [-e <string>] [<filename>]";
	if (argc > 3) {
		std::cerr << usage << std::endl;
		return EXIT_FAILURE;
	}
	// This isn't the best way to do commandline parsing, but it doesn't really matter
	if (argc == 3) { // Short inline program
		std::string flag = argv[1];
		if (flag != "-e") {
			std::cerr << usage << std::endl;
			return EXIT_FAILURE;
		}
		if (!runLine(argv[2], interp)) {
			return EXIT_FAILURE;
		}
	}
	else if (argc == 2) { // Run from file
		std::ifstream ifs(argv[1]);
		if (!ifs.good()) {
			std::cerr << "Error: Could not find or open file: " << argv[1] << std::endl;
			return EXIT_FAILURE;
		}
		if (!run(ifs, interp)) {
			return EXIT_FAILURE;
		}
	}
	else { // REPL
		std::cout << "vtscript> ";
		std::string line;
		while (std::getline(std::cin, line)) {
			runLine(line, interp);
			std::cout << std::endl << "vtscript> ";
		}
	}

	return EXIT_SUCCESS;

}

bool run(std::istream& program, Interpreter& interp) {

	bool ok = interp.parse(program);
	if (!ok) {
		std::cerr << "Error: Failed to parse invalid expression" << std::endl;
		return false;
	}
	
	interp.saveState();
	Expression result;
	try {
		result = interp.eval();
	}
	catch (InterpreterSemanticError e) {
		interp.restoreState();
		std::cerr << "Error during evaluation: " << e.what() << std::endl;
		return false;
	}

	if (result.getAtom().getType() == Atom::Type::BOOL) {
		std::string boolString = result.getAtom().getBool() ? "True" : "False";
		std::cout << "(" << boolString << ")" << std::endl;
	}
	else if (result.getAtom().getType() == Atom::Type::NUMBER) {
		std::cout << "(" << result.getAtom().getNumber() << ")" << std::endl;
	}
	else if (result.getAtom().getType() == Atom::Type::POINT) {
		std::cout << "(" << pointX(result.getAtom().getPoint()) << ", " << pointY(result.getAtom().getPoint()) << ")" << std::endl;
	}
	else if (result.getAtom().getType() == Atom::Type::LINE) {
		std::cout << "((" << pointX(result.getAtom().getLine().first) << ", " << pointY(result.getAtom().getLine().first) <<
			"), (" << pointX(result.getAtom().getLine().second) << ", " << pointY(result.getAtom().getLine().second) << "))" << std::endl;
	}
	else if (result.getAtom().getType() == Atom::Type::ARC) {
		std::cout << "((" << pointX(result.getAtom().getArc().center) << ", " << pointY(result.getAtom().getArc().center) <<
			"), (" << pointX(result.getAtom().getArc().start) << ", " << pointY(result.getAtom().getArc().start) <<
			") " << result.getAtom().getArc().span << ")" << std::endl;
	}
	else {
		std::cout << "(None)" << std::endl;
	}

	return true;

}

bool runLine(std::string program, Interpreter& interp) {

	std::istringstream iss(program);
	return run(iss, interp);

}