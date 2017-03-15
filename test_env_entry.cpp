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

Point pointFunc(std::vector<Atom> args) {

	return makePoint(0, 0);

}

Line lineFunc(std::vector<Atom> args) {

	return makeLine(makePoint(0, 0), makePoint(5, 5));

}

Arc arcFunc(std::vector<Atom> args) {

	return makeArc(makePoint(0, 0), makePoint(5, 5), 1);

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
	EnvEntry::fptrPoint pointFuncPtr = pointFunc;
	EnvEntry ePointFunc = EnvEntry(pointFuncPtr);
	EnvEntry::fptrLine lineFuncPtr = lineFunc;
	EnvEntry eLineFunc = EnvEntry(lineFuncPtr);
	EnvEntry::fptrArc arcFuncPtr = arcFunc;
	EnvEntry eArcFunc = EnvEntry(arcFuncPtr);

	REQUIRE(eNone.getType() == EnvEntry::Type::NONE);
	REQUIRE(eBool.getType() == EnvEntry::Type::BOOL);
	REQUIRE(eNumber.getType() == EnvEntry::Type::NUMBER);
	REQUIRE(eBoolFunc.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(eNumFunc.getType() == EnvEntry::Type::FPTR_NUMBER);
	REQUIRE(ePoint.getType() == EnvEntry::Type::POINT);
	REQUIRE(eLine.getType() == EnvEntry::Type::LINE);
	REQUIRE(eArc.getType() == EnvEntry::Type::ARC);
	REQUIRE(ePointFunc.getType() == EnvEntry::Type::FPTR_POINT);
	REQUIRE(eLineFunc.getType() == EnvEntry::Type::FPTR_LINE);
	REQUIRE(eArcFunc.getType() == EnvEntry::Type::FPTR_ARC);

	std::vector<Atom> args1;
	args1.push_back(Atom(1.0));
	args1.push_back(Atom(2.0));
	args1.push_back(Atom(3.0));

	REQUIRE(eBool.getBool());
	REQUIRE(eNumber.getNumber() == 2.5);
	REQUIRE(eBoolFunc.getFptrBool()(args1));
	REQUIRE(eNumFunc.getFptrNumber()(args1) == 3.0);
	REQUIRE(ePoint.getPoint() == makePoint(1, 2));
	REQUIRE(eLine.getLine().first == makePoint(0, 0));
	REQUIRE(eLine.getLine().second == makePoint(5, 5));
	REQUIRE(eArc.getArc().center == makePoint(0, 0));
	REQUIRE(eArc.getArc().start == makePoint(5, 5));
	REQUIRE(eArc.getArc().span == 1);
	REQUIRE(ePointFunc.getFptrPoint()(args1) == makePoint(0, 0));
	REQUIRE(eLineFunc.getFptrLine()(args1).first == makePoint(0, 0));
	REQUIRE(eLineFunc.getFptrLine()(args1).second == makePoint(5, 5));
	REQUIRE(eArcFunc.getFptrArc()(args1).center == makePoint(0, 0));
	REQUIRE(eArcFunc.getFptrArc()(args1).start == makePoint(5, 5));
	REQUIRE(eArcFunc.getFptrArc()(args1).span == 1);

}

TEST_CASE("Tests exception throwing for invalid access on None EnvEntries", "[enventry]") {

	EnvEntry eNone = EnvEntry();

	REQUIRE_THROWS_AS(eNone.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on Bool EnvEntries", "[enventry]") {

	EnvEntry eBool = EnvEntry(true);

	REQUIRE_THROWS_AS(eBool.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on Number EnvEntries", "[enventry]") {

	EnvEntry eNumber = EnvEntry(2.5);

	REQUIRE_THROWS_AS(eNumber.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on BoolFunc EnvEntries", "[enventry]") {

	EnvEntry::fptrBool boolFuncPtr = boolFunc;
	EnvEntry eBoolFunc = EnvEntry(boolFuncPtr);

	REQUIRE_THROWS_AS(eBoolFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on NumFunc EnvEntries", "[enventry]") {

	EnvEntry::fptrNumber numFuncPtr = numberFunc;
	EnvEntry eNumFunc = EnvEntry(numFuncPtr);

	REQUIRE_THROWS_AS(eNumFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on Point EnvEntries", "[enventry]") {

	EnvEntry ePoint = EnvEntry(makePoint(1, 2));

	REQUIRE_THROWS_AS(ePoint.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(ePoint.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on Line EnvEntries", "[enventry]") {

	EnvEntry eLine = EnvEntry(makeLine(makePoint(0, 0), makePoint(5, 5)));

	REQUIRE_THROWS_AS(eLine.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(eLine.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on Arc EnvEntries", "[enventry]") {

	EnvEntry eArc = EnvEntry(makeArc(makePoint(0, 0), makePoint(5, 5), 1));

	REQUIRE_THROWS_AS(eArc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(eArc.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on PointFunc EnvEntries", "[enventry]") {

	EnvEntry::fptrPoint pointFuncPtr = pointFunc;
	EnvEntry ePointFunc = EnvEntry(pointFuncPtr);

	REQUIRE_THROWS_AS(ePointFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getFptrLine(), std::logic_error);
	REQUIRE_THROWS_AS(ePointFunc.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on LineFunc EnvEntries", "[enventry]") {

	EnvEntry::fptrLine lineFuncPtr = lineFunc;
	EnvEntry eLineFunc = EnvEntry(lineFuncPtr);

	REQUIRE_THROWS_AS(eLineFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eLineFunc.getFptrArc(), std::logic_error);

}

TEST_CASE("Tests exception throwing for invalid access on ArcFunc EnvEntries", "[enventry]") {

	EnvEntry::fptrArc arcFuncPtr = arcFunc;
	EnvEntry eArcFunc = EnvEntry(arcFuncPtr);

	REQUIRE_THROWS_AS(eArcFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getFptrNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getArc(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getFptrPoint(), std::logic_error);
	REQUIRE_THROWS_AS(eArcFunc.getFptrLine(), std::logic_error);

}
