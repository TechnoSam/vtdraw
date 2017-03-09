// File: Atom.cpp
// Author: Samuel McFalls

#include "atom.hpp"

Atom::Atom() {

	type = Atom::Type::NONE;

}

Atom::Atom(bool value) {

	type = Atom::Type::BOOL;

	boolVal = value;

	numberVal = 0.0;

	symbolVal = "";

	pointVal = Point();

	lineVal = Line();

	arcVal = Arc();

}

Atom::Atom(double value) {

	type = Atom::Type::NUMBER;

	boolVal = false;

	numberVal = value;

	symbolVal = "";

	pointVal = Point();

	lineVal = Line();

	arcVal = Arc();

}

Atom::Atom(const std::string& value) {

	type = Atom::Type::SYMBOL;

	boolVal = false;

	numberVal = 0.0;

	symbolVal = value;

	pointVal = Point();

	lineVal = Line();

	arcVal = Arc();

}

Atom::Atom(Point value) {

	type = Atom::Type::POINT;

	boolVal = false;

	numberVal = 0.0;

	symbolVal = "";

	pointVal = value;

	lineVal = Line();

	arcVal = Arc();
}

Atom::Atom(Line value) {

	type = Atom::Type::LINE;

	boolVal = false;

	numberVal = 0.0;

	symbolVal = "";

	pointVal = Point();

	lineVal = value;

	arcVal = Arc();

}

Atom::Atom(Arc value) {

	type = Atom::Type::ARC;

	boolVal = false;

	numberVal = 0.0;

	symbolVal = "";

	pointVal = Point();

	lineVal = Line();

	arcVal = value;

}

Atom::Type Atom::getType() {

	return type;

}

bool Atom::getBool() {

	if (type != Atom::Type::BOOL) {
		throw std::logic_error("Atom is not of type Bool");
	}

	return boolVal;

}

double Atom::getNumber() {

	if (type != Atom::Type::NUMBER) {
		throw std::logic_error("Atom is not of type Number");
	}

	return numberVal;

}

std::string Atom::getSymbol() {

	if (type != Atom::Type::SYMBOL) {
		throw std::logic_error("Atom is not of type Symbol");
	}

	return symbolVal;

}

Point Atom::getPoint() {

	if (type != Atom::Type::POINT) {
		throw std::logic_error("Atom is not of type Point");
	}

	return pointVal;

}

Line Atom::getLine() {

	if (type != Atom::Type::LINE) {
		throw std::logic_error("Atom is not of type Line");
	}

	return lineVal;
}

Arc Atom::getArc() {
	
	if (type != Atom::Type::ARC) {
		throw std::logic_error("Atom is not of type Arc");
	}

	return arcVal;

}

bool Atom::operator==(const Atom& rhs) const noexcept {

	bool isEqual = false;

	if (this->type == rhs.type) {
		switch (this->type) {
		case Atom::Type::NONE:
			isEqual = true;
			break;
		case Atom::Type::BOOL:
			isEqual = (this->boolVal == rhs.boolVal);
			break;
		case Atom::Type::NUMBER:
			isEqual = (this->numberVal == rhs.numberVal);
			break;
		case Atom::Type::SYMBOL:
			isEqual = (this->symbolVal == rhs.symbolVal);
			break;
		case Atom::Type::POINT:
			isEqual = (this->pointVal == rhs.pointVal);
			break;
		case Atom::Type::LINE:
			isEqual = (this->lineVal.first == rhs.lineVal.first &&
				this->lineVal.second == rhs.lineVal.second);
			break;
		case Atom::Type::ARC:
			isEqual = (this->arcVal.center == rhs.arcVal.center &&
				this->arcVal.start == rhs.arcVal.start &&
				this->arcVal.span == rhs.arcVal.span);
			break;
		}
	}

	return isEqual;

}

bool Atom::operator!=(const Atom& rhs) const noexcept {

	return !operator==(rhs);

}