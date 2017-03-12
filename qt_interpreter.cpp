// File: qt_interpreter.cpp
// Author: Samuel McFalls

#include "qt_interpreter.hpp"

#include <QObject>
#include <QGraphicsItem>

#include <string>
#include <sstream>

QtInterpreter::QtInterpreter(QObject * parent): QObject(parent) {



}

void QtInterpreter::parseAndEvaluate(QString entry) {

	std::string command = entry.toStdString();
	std::istringstream iss(command);

	bool ok = interp.parse(iss);
	if (!ok) {
		error(QString("Error: Failed to parse invalid expression"));
		return;
	}

	interp.saveState();
	Expression result;
	try {
		result = interp.eval();
	}
	catch (InterpreterSemanticError e) {
		interp.restoreState();
		QString errMsg;
		errMsg.append("Error during evaluation: ");
		errMsg.append(e.what());
		error(QString(errMsg));
		return;
	}

	if (result.getAtom().getType() == Atom::Type::BOOL) {
		QString infoMsg;
		infoMsg.append("(");
		infoMsg.append(result.getAtom().getBool() ? "True" : "False");
		infoMsg.append(")");
		info(infoMsg);
	}
	else if (result.getAtom().getType() == Atom::Type::NUMBER) {
		QString infoMsg;
		infoMsg.append("(");
		infoMsg.append(QString::number(result.getAtom().getNumber()));
		infoMsg.append(")");
		info(infoMsg);
	}
	else if (result.getAtom().getType() == Atom::Type::POINT) {
		QString infoMsg;
		infoMsg.append("(");
		infoMsg.append(QString::number(pointX(result.getAtom().getPoint())));
		infoMsg.append(", ");
		infoMsg.append(QString::number(pointY(result.getAtom().getPoint())));
		infoMsg.append(")");
		info(infoMsg);
	}
	else if (result.getAtom().getType() == Atom::Type::LINE) {
		QString infoMsg;
		infoMsg.append(("(("));
		infoMsg.append(QString::number(pointX(result.getAtom().getLine().first)));
		infoMsg.append(", ");
		infoMsg.append(QString::number(pointY(result.getAtom().getLine().first)));
		infoMsg.append("), (");
		infoMsg.append(QString::number(pointX(result.getAtom().getLine().second)));
		infoMsg.append(", ");
		infoMsg.append(QString::number(pointY(result.getAtom().getLine().second)));
		infoMsg.append("))");
		info(infoMsg);
	}
	else if (result.getAtom().getType() == Atom::Type::ARC) {
		QString infoMsg;
		infoMsg.append(("(("));
		infoMsg.append(QString::number(pointX(result.getAtom().getArc().center)));
		infoMsg.append(", ");
		infoMsg.append(QString::number(pointY(result.getAtom().getArc().center)));
		infoMsg.append("), (");
		infoMsg.append(QString::number(pointX(result.getAtom().getArc().start)));
		infoMsg.append(", ");
		infoMsg.append(QString::number(pointY(result.getAtom().getArc().start)));
		infoMsg.append(") ");
		infoMsg.append(QString::number(result.getAtom().getArc().span));
		infoMsg.append(")");
		info(infoMsg);
	}
	else {
		info("(None)");
	}

}
