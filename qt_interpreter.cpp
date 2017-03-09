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
	else { // Number. Nothing else should be able to happen so other cases are untestable
		QString infoMsg;
		infoMsg.append("(");
		infoMsg.append(QString::number(result.getAtom().getNumber()));
		infoMsg.append(")");
		info(infoMsg);
	}

}
