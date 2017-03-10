// File: EnvEntry.cpp
// Author: Samuel McFalls

#include "env_entry.hpp"

EnvEntry::EnvEntry() {

	type = NONE;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = nullptr;
	pointVal = Point();
	lineVal = Line();
	arcVal = Arc();

}

EnvEntry::EnvEntry(bool value) {

	type = BOOL;

	boolVal = value;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = nullptr;
	pointVal = Point();
	lineVal = Line();
	arcVal = Arc();

}

EnvEntry::EnvEntry(double value) {

	type = NUMBER;

	boolVal = false;
	numberVal = value;
	boolFunc = nullptr;
	numberFunc = nullptr;
	pointVal = Point();
	lineVal = Line();
	arcVal = Arc();

}

EnvEntry::EnvEntry(fptrBool func) {

	type = FPTR_BOOL;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = func;
	numberFunc = nullptr;
	pointVal = Point();
	lineVal = Line();
	arcVal = Arc();

}

EnvEntry::EnvEntry(fptrNumber func) {

	type = FPTR_NUMBER;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = func;
	pointVal = Point();
	lineVal = Line();
	arcVal = Arc();

}

EnvEntry::EnvEntry(Point value) {

	type = POINT;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = nullptr;
	pointVal = value;
	lineVal = Line();
	arcVal = Arc();

}

EnvEntry::EnvEntry(Line value) {

	type = LINE;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = nullptr;
	pointVal = Point();
	lineVal = value;
	arcVal = Arc();

}

EnvEntry::EnvEntry(Arc value) {

	type = ARC;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = nullptr;
	pointVal = Point();
	lineVal = Line();
	arcVal = value;

}

EnvEntry::Type EnvEntry::getType() {

	return type;

}

bool EnvEntry::getBool() {

	if (type != BOOL) {
		throw std::logic_error("Environment Entry is not of type Bool");
	}

	return boolVal;

}

double EnvEntry::getNumber() {

	if (type != NUMBER) {
		throw std::logic_error("Environment Entry is not of type Number");
	}

	return numberVal;

}

EnvEntry::fptrBool EnvEntry::getFptrBool() {

	if (type != FPTR_BOOL) {
		throw std::logic_error("Environment Entry is not of type Bool Function Pointer");
	}

	return boolFunc;

}

EnvEntry::fptrNumber EnvEntry::getFptrNumber() {

	if (type != FPTR_NUMBER) {
		throw std::logic_error("Environment Entry is not of type Number Function Pointer");
	}

	return numberFunc;

}

Point EnvEntry::getPoint() {

	if (type != POINT) {
		throw std::logic_error("Environment Entry is not of type Point");
	}

	return pointVal;

}

Line EnvEntry::getLine() {

	if (type != LINE) {
		throw std::logic_error("Environment Entry is not of type Line");
	}

	return lineVal;

}

Arc EnvEntry::getArc() {

	if (type != ARC) {
		throw std::logic_error("Environment Entry is not of type Arc");
	}

	return arcVal;

}