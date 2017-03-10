// File: test_EnvEntry.cpp
// Author: Samuel McFalls

#include "catch.hpp"

#include "env_entry.hpp"

#include <vector>
#include <string>

// Returns true if odd number of args, false otherwise
bool boolFunc(std::vector<Atom> args) {

	return (args.size() % 2 == 1);

}

// Returns the number of args
double numberFunc(std::vector<Atom> args) {

	return args.size();

}

TEST_CASE("Tests the EnvEntry constructors", "[enventry]") {

	EnvEntry eNone = EnvEntry();
	EnvEntry eBool = EnvEntry(true);
	EnvEntry eNumber = EnvEntry(2.5);
	EnvEntry::fptrBool boolFuncPtr = boolFunc;
	EnvEntry eBoolFunc = EnvEntry(boolFuncPtr);
	EnvEntry::fptrNumber numFuncPtr = numberFunc;
	EnvEntry eNumFunc = EnvEntry(numFuncPtr);
	EnvEntry ePoint = EnvEntry(makePoint(1, 2));
	EnvEntry eLine = EnvEntry(makeLine(makePoint(0, 0), makePoint(5, 5)));
	EnvEntry eArc = EnvEntry(makeArc(makePoint(0, 0), makePoint(5, 5), 1));

	REQUIRE(eNone.getType() == EnvEntry::Type::NONE);
	REQUIRE(eBool.getType() == EnvEntry::Type::BOOL);
	REQUIRE(eNumber.getType() == EnvEntry::Type::NUMBER);
	REQUIRE(eBoolFunc.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(eNumFunc.getType() == EnvEntry::Type::FPTR_NUMBER);
	REQUIRE(ePoint.getType() == EnvEntry::Type::POINT);
	REQUIRE(eLine.getType() == EnvEntry::Type::LINE);
	REQUIRE(eArc.getType() == EnvEntry::Type::ARC);

	std::vector<Atom> args1;
	args1.push_back(Atom(1.0));
	args1.push_back(Atom(2.0));
	args1.push_back(Atom(3.0));

	REQUIRE(eBool.getBool());
	REQUIRE(eNumber.getNumber() == 2.5);
	REQUIRE(eBoolFunc.getFptrBool()(args1));
	REQUIRE(eNumFunc.getFptrNumber()(args1) == 3.0);
	REQUIRE(ePoint.getPoint() == makePoint(0, 0));
	REQUIRE(eLine.getLine().first == makePoint(0, 0));
	REQUIRE(eLine.getLine().second == makePoint(5, 5));
	REQUIRE(eArc.getArc().center == makePoint(0, 0));
	REQUIRE(eArc.getArc().start == makePoint(5, 5));
	REQUIRE(eArc.getArc().span == 1);

}

TEST_CASE("Tests exception throwing for invalid access on EnvEntries", "[enventry]") {

	EnvEntry eNone = EnvEntry();
	EnvEntry eBool = EnvEntry(true);
	EnvEntry eNumber = EnvEntry(2.5);
	EnvEntry::fptrBool boolFuncPtr = boolFunc;
	EnvEntry eBoolFunc = EnvEntry(boolFuncPtr);
	EnvEntry::fptrNumber numFuncPtr = numberFunc;
	EnvEntry eNumFunc = EnvEntry(numFuncPtr);
	EnvEntry ePoint = EnvEntry(makePoint(1, 2));
	EnvEntry eLine = EnvEntry(makeLine(makePoint(0, 0), makePoint(5, 5)));
	EnvEntry eArc = EnvEntry(makeArc(makePoint(0, 0), makePoint(5, 5), 1));

	REQUIRE_THROWS_AS(eNone.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(eBool.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(eNumber.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(eBoolFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(eNumFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(ePoint.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(eLine.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(eArc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getLine(), std::logic_error);

}