#include "catch.hpp"

#include <string>
#include <tuple>

#include "atom.hpp"

TEST_CASE("Tests the Atom constructors", "[atom]") {

	Atom aNone = Atom();
	Atom aBool = Atom(true);
	Atom aNumber = Atom(2.5);
	Atom aSymbol = Atom(std::string("Test"));
	Atom aPoint = Atom(makePoint(1, 2));
	Atom aLine = Atom(makeLine(makePoint(0, 0), makePoint(5, 5)));
	Atom aArc = Atom(makeArc(makePoint(0, 0), makePoint(5, 5), 1));

	REQUIRE(aNone.getType() == Atom::Type::NONE);
	REQUIRE(aBool.getType() == Atom::Type::BOOL);
	REQUIRE(aNumber.getType() == Atom::Type::NUMBER);
	REQUIRE(aSymbol.getType() == Atom::Type::SYMBOL);
	REQUIRE(aPoint.getType() == Atom::Type::POINT);
	REQUIRE(aLine.getType() == Atom::Type::LINE);
	REQUIRE(aArc.getType() == Atom::Type::ARC);

	REQUIRE(aBool.getBool());
	REQUIRE(aNumber.getNumber() == 2.5);
	REQUIRE(aSymbol.getSymbol() == "Test");
	REQUIRE(pointX(aPoint.getPoint()) == 1);
	REQUIRE(pointY(aPoint.getPoint()) == 2);
	REQUIRE(aPoint.getPoint() == makePoint(1, 2));
	REQUIRE(aLine.getLine().first == makePoint(0, 0));
	REQUIRE(aLine.getLine().second == makePoint(5, 5));
	REQUIRE(aArc.getArc().center == makePoint(0, 0));
	REQUIRE(aArc.getArc().start == makePoint(5, 5));
	REQUIRE(aArc.getArc().span == 1);

}

TEST_CASE("Tests the equality operator for Atoms", "[atom]") {

	Atom aNone1 = Atom();
	Atom aBool1 = Atom(true);
	Atom aNumber1 = Atom(2.5);
	Atom aSymbol1 = Atom(std::string("Test"));
	Atom aPoint1 = Atom(makePoint(1, 2));
	Atom aLine1 = Atom(makeLine(makePoint(0, 0), makePoint(5, 5)));
	Atom aArc1 = Atom(makeArc(makePoint(0, 0), makePoint(5, 5), 1));

	Atom aNone2 = Atom();
	Atom aBool2 = Atom(true);
	Atom aNumber2 = Atom(2.5);
	Atom aSymbol2 = Atom(std::string("Test"));
	Atom aPoint2 = Atom(makePoint(1, 2));
	Atom aLine2 = Atom(makeLine(makePoint(0, 0), makePoint(5, 5)));
	Atom aArc2 = Atom(makeArc(makePoint(0, 0), makePoint(5, 5), 1));

	Atom aNone3 = Atom();
	Atom aBool3 = Atom(false);
	Atom aNumber3 = Atom(5.3);
	Atom aSymbol3 = Atom(std::string("Not Test"));
	Atom aPoint3 = Atom(makePoint(2, 1));
	Atom aLine3 = Atom(makeLine(makePoint(1, 1), makePoint(5, 5)));
	Atom aArc3 = Atom(makeArc(makePoint(0, 0), makePoint(5, 5), 2));

	REQUIRE(aNone1 == aNone2);
	REQUIRE(aNone1 == aNone3);

	REQUIRE(aBool1 == aBool2);
	REQUIRE(aBool1 != aBool3);

	REQUIRE(aNumber1 == aNumber2);
	REQUIRE(aNumber1 != aNumber3);

	REQUIRE(aSymbol1 == aSymbol2);
	REQUIRE(aSymbol1 != aSymbol3);

	REQUIRE(aPoint1 == aPoint2);
	REQUIRE(aPoint1 != aPoint3);

	REQUIRE(aLine1 == aLine2);
	REQUIRE(aLine1 != aLine3);

	REQUIRE(aArc1 == aArc2);
	REQUIRE(aArc1 != aArc3);

	REQUIRE(aNone1 != aBool1);
	REQUIRE(aNone1 != aNumber1);
	REQUIRE(aNone1 != aSymbol1);
	REQUIRE(aNone1 != aPoint1);
	REQUIRE(aNone1 != aLine1);
	REQUIRE(aNone1 != aArc1);

	REQUIRE(aBool1 != aNone1);
	REQUIRE(aBool1 != aNumber1);
	REQUIRE(aBool1 != aSymbol1);
	REQUIRE(aBool1 != aPoint1);
	REQUIRE(aBool1 != aLine1);
	REQUIRE(aBool1 != aArc1);

	REQUIRE(aNumber1 != aNone1);
	REQUIRE(aNumber1 != aBool1);
	REQUIRE(aNumber1 != aSymbol1);
	REQUIRE(aNumber1 != aPoint1);
	REQUIRE(aNumber1 != aLine1);
	REQUIRE(aNumber1 != aArc1);

	REQUIRE(aSymbol1 != aNone1);
	REQUIRE(aSymbol1 != aBool1);
	REQUIRE(aSymbol1 != aNumber1);
	REQUIRE(aSymbol1 != aPoint1);
	REQUIRE(aSymbol1 != aLine1);
	REQUIRE(aSymbol1 != aArc1);

	REQUIRE(aPoint1 != aNone1);
	REQUIRE(aPoint1 != aBool1);
	REQUIRE(aPoint1 != aNumber1);
	REQUIRE(aPoint1 != aSymbol1);
	REQUIRE(aPoint1 != aLine1);
	REQUIRE(aPoint1 != aArc1);

	REQUIRE(aLine1 != aNone1);
	REQUIRE(aLine1 != aBool1);
	REQUIRE(aLine1 != aNumber1);
	REQUIRE(aLine1 != aSymbol1);
	REQUIRE(aLine1 != aPoint1);
	REQUIRE(aLine1 != aArc1);

	REQUIRE(aArc1 != aNone1);
	REQUIRE(aArc1 != aBool1);
	REQUIRE(aArc1 != aNumber1);
	REQUIRE(aArc1 != aSymbol1);
	REQUIRE(aArc1 != aPoint1);
	REQUIRE(aArc1 != aLine1);

}

TEST_CASE("Tests exception throwing for invalid access on Atoms", "[atom]") {

	Atom aNone = Atom();
	Atom aBool = Atom(true);
	Atom aNumber = Atom(2.5);
	Atom aSymbol = Atom(std::string("Test"));
	Atom aPoint = Atom(makePoint(1, 2));
	Atom aLine = Atom(makeLine(makePoint(0, 0), makePoint(5, 5)));
	Atom aArc = Atom(makeArc(makePoint(0, 0), makePoint(5, 5), 1));

	REQUIRE_THROWS_AS(aNone.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aNone.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aNone.getSymbol(), std::logic_error);
	REQUIRE_THROWS_AS(aNone.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(aNone.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(aNone.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(aBool.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aBool.getSymbol(), std::logic_error);
	REQUIRE_THROWS_AS(aBool.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(aBool.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(aBool.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(aNumber.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aNumber.getSymbol(), std::logic_error);
	REQUIRE_THROWS_AS(aNumber.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(aNumber.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(aNumber.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(aSymbol.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aSymbol.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aSymbol.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(aSymbol.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(aSymbol.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(aPoint.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aPoint.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aPoint.getSymbol(), std::logic_error);
	REQUIRE_THROWS_AS(aPoint.getLine(), std::logic_error);
	REQUIRE_THROWS_AS(aPoint.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(aLine.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aLine.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aLine.getSymbol(), std::logic_error);
	REQUIRE_THROWS_AS(aLine.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(aLine.getArc(), std::logic_error);

	REQUIRE_THROWS_AS(aArc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aArc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aArc.getSymbol(), std::logic_error);
	REQUIRE_THROWS_AS(aArc.getPoint(), std::logic_error);
	REQUIRE_THROWS_AS(aArc.getLine(), std::logic_error);

}
