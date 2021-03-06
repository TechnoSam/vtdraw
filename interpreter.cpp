// File: interpreter.cpp
// Author: Samuel McFalls

#include "interpreter.hpp"

Interpreter::Interpreter() {

	// Nothing to do

}

bool Interpreter::parse(std::istream & expression) noexcept {

	std::vector<std::string> tokens;
	try {
		tokens = tkn.tokenize(expression);
	}
	catch (...) {
		return false;
	}

	try {
		AST = tkn.buildAST(tokens);
	}
	catch (...) {
		return false;
	}
	
	return true;

}

Expression Interpreter::eval() {

	env.clearToDraw();
	return postEval(AST);

}

Expression Interpreter::postEval(Expression exp) {

	// Check if we're a special form
	if (exp.getAtom().getType() == Atom::Type::SYMBOL) {
		if (exp.getAtom().getSymbol() == "begin") {
			return begin(exp);
		}
		if (exp.getAtom().getSymbol() == "define") {
			return define(exp);
		}
		if (exp.getAtom().getSymbol() == "if") {
			return ifSF(exp);
		}
		if (exp.getAtom().getSymbol() == "draw") {
			return draw(exp);
		}
	}
	// If we're not a special form, evaluate all the children of the current expression
	// The children are potential arguments to procedures
	std::vector<Expression> children = exp.getChildren();
	std::vector<Atom> args;
	for (auto it = children.begin(); it != children.end(); ++it) {
		Expression child = *it;
		args.push_back(postEval(child).getAtom());
	}

	bool isProc = false;
	EnvEntry proc;
	if (exp.getAtom().getType() == Atom::Type::SYMBOL) {
		if (env.exists(exp.getAtom().getSymbol())) {
			proc = env.fetch(exp.getAtom().getSymbol());
			isProc = isProcType(proc);
		}
	}

	if (isProc) {
		return runProc(proc, args);
	}
	else {

		if (!children.empty()) {
			throw InterpreterSemanticError("No such procedure");
		}
		return retValue(exp);

	}

}

void Interpreter::saveState() {

	save = env;

}

void Interpreter::restoreState() {

	env = save;

}

std::vector<Atom> Interpreter::toBeDrawn() {

	return env.toBeDrawn();

}

Expression Interpreter::begin(Expression exp) {
	std::vector<Expression> children = exp.getChildren();
	if (children.empty()) {
		throw InterpreterSemanticError("No children");
	}
	Expression result;
	for (auto it = children.begin(); it != children.end(); ++it) {
		Expression child = *it;
		result = postEval(child);
	}
	return result;
}

Expression Interpreter::define(Expression exp) {
	std::vector<Expression> children = exp.getChildren();
	if (children.size() != 2) {
		throw InterpreterSemanticError("Improper number of args");
	}
	if (children.at(0).getAtom().getType() != Atom::Type::SYMBOL) {
		throw InterpreterSemanticError("First argument is not a symbol");
	}
	std::string symbol = children.at(0).getAtom().getSymbol();
	if (symbol == "begin" || symbol == "define" || symbol == "if" || symbol == "draw") {
		throw InterpreterSemanticError("Attempt to redefine special form");
	}
	if (env.exists(symbol)) {
		throw InterpreterSemanticError("Attempt to redefine existing symbol");
	}
	Expression value = postEval(children.at(1));
	if (value.getAtom().getType() == Atom::Type::BOOL) {
		env.define(symbol, EnvEntry(value.getAtom().getBool()));
	}
	else if (value.getAtom().getType() == Atom::Type::NUMBER) {
		env.define(symbol, EnvEntry(value.getAtom().getNumber()));
	}
	else if (value.getAtom().getType() == Atom::Type::POINT) {
		env.define(symbol, EnvEntry(value.getAtom().getPoint()));
	}
	else if (value.getAtom().getType() == Atom::Type::LINE) {
		env.define(symbol, EnvEntry(value.getAtom().getLine()));
	}
	else {
		env.define(symbol, EnvEntry(value.getAtom().getArc()));
	}
	return value;
}

Expression Interpreter::ifSF(Expression exp) {
	std::vector<Expression> children = exp.getChildren();
	if (children.size() != 3) {
		throw InterpreterSemanticError("Improper number of args");
	}
	Expression condExp = postEval(children.at(0));
	if (condExp.getAtom().getType() != Atom::Type::BOOL) {
		throw InterpreterSemanticError("Condition is not a boolean");
	}
	if (condExp.getAtom().getBool()) {
		return postEval(children.at(1));
	}
	else {
		return postEval(children.at(2));
	}
}

Expression Interpreter::draw(Expression exp) {
	std::vector<Expression> children = exp.getChildren();
	if (children.empty()) {
		throw InterpreterSemanticError("No children");
	}
	for (auto it = children.begin(); it != children.end(); ++it) {
		Expression item = postEval(*it);
		if (item.getAtom().getType() != Atom::Type::POINT &&
			item.getAtom().getType() != Atom::Type::LINE &&
			item.getAtom().getType() != Atom::Type::ARC) {
			throw InterpreterSemanticError("Attempt to draw non graphical type");
		}
		env.addDraw(item.getAtom());
	}
	return Expression();
}

bool Interpreter::isProcType(EnvEntry proc) {

	bool ret = false;
	if (proc.getType() == EnvEntry::Type::FPTR_BOOL ||
		proc.getType() == EnvEntry::Type::FPTR_NUMBER ||
		proc.getType() == EnvEntry::Type::FPTR_POINT ||
		proc.getType() == EnvEntry::Type::FPTR_LINE ||
		proc.getType() == EnvEntry::Type::FPTR_ARC) {
		ret = true;
	}
	return ret;

}

Expression Interpreter::runProc(EnvEntry proc, std::vector<Atom> args) {

	if (proc.getType() == EnvEntry::Type::FPTR_BOOL) {
		return Expression(proc.getFptrBool()(args));
	}
	if (proc.getType() == EnvEntry::Type::FPTR_NUMBER) {
		return Expression(proc.getFptrNumber()(args));
	}
	if (proc.getType() == EnvEntry::Type::FPTR_POINT) {
		return Expression(proc.getFptrPoint()(args));
	}
	if (proc.getType() == EnvEntry::Type::FPTR_LINE) {
		return Expression(proc.getFptrLine()(args));
	}
	return Expression(proc.getFptrArc()(args));

}

Expression Interpreter::retValue(Expression exp) {

	if (exp.getAtom().getType() == Atom::Type::SYMBOL) {
		EnvEntry value = env.fetch(exp.getAtom().getSymbol());
		if (value.getType() == EnvEntry::Type::BOOL) {
			return Expression(value.getBool());
		}
		if (value.getType() == EnvEntry::Type::NUMBER) {
			return Expression(value.getNumber());
		}
		if (value.getType() == EnvEntry::Type::POINT) {
			return Expression(value.getPoint());
		}
		if (value.getType() == EnvEntry::Type::LINE) {
			return Expression(value.getLine());
		}
		return Expression(value.getArc());
	}
	return exp;

}