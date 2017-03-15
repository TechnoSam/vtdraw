// File: qt_interpreter.cpp
// Author: Samuel McFalls

#include "qt_interpreter.hpp"
#include "qgraphics_arc_item.hpp"

#include <QObject>
#include <QGraphicsItem>
#include <QBrush>
#include <QLineF>
#include <QtMath>

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
		createGraphics(interp.toBeDrawn());
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
		info(boolString(result));
	}
	else if (result.getAtom().getType() == Atom::Type::NUMBER) {
		info(numberString(result));
	}
	else if (result.getAtom().getType() == Atom::Type::POINT) {
		info(pointString(result));
	}
	else if (result.getAtom().getType() == Atom::Type::LINE) {
		info(lineString(result));
	}
	else if (result.getAtom().getType() == Atom::Type::ARC) {
		info(arcString(result));
	}
	else {
		info("(None)");
	}

}

void QtInterpreter::createGraphics(std::vector<Atom> items) {

	for (auto it = items.begin(); it != items.end(); ++it) {

		switch ((*it).getType()) {
		case Atom::Type::POINT: {
			double x = pointX((*it).getPoint());
			double y = pointY((*it).getPoint());
			QGraphicsEllipseItem * point = new QGraphicsEllipseItem();
			point->setRect(QRectF(x - 2, y - 2, 4, 4));
			point->setBrush(QBrush(Qt::black));
			drawGraphic(point);
			break;
		}
		case Atom::Type::LINE: {
			double x1 = pointX((*it).getLine().first);
			double y1 = pointY((*it).getLine().first);
			double x2 = pointX((*it).getLine().second);
			double y2 = pointY((*it).getLine().second);
			QGraphicsLineItem * line = new QGraphicsLineItem();
			line->setLine(QLineF(QPointF(x1, y1), QPointF(x2, y2)));
			drawGraphic(line);
			break;
		}
		case Atom::Type::ARC: {
			double cx = pointX((*it).getArc().center);
			double cy = pointY((*it).getArc().center);
			double sx = pointX((*it).getArc().start);
			double sy = pointY((*it).getArc().start);
			double spanAngle = qRadiansToDegrees((*it).getArc().span) * 16;
			QLineF line(QLineF(QPointF(cx, cy), QPointF(sx, sy)));
			double width = line.length() * 2;
			double height = width;
			double startAngle = line.angle() * 16;
			QGraphicsArcItem * arc = new QGraphicsArcItem();
			arc->setRect(QRectF(cx - width / 2, cy - height / 2, width, height));
			arc->setStartAngle(startAngle);
			arc->setSpanAngle(spanAngle);
			drawGraphic(arc);
			break;
		}
		}

	}

}

QString QtInterpreter::boolString(Expression exp) {
	QString infoMsg;
	infoMsg.append("(");
	infoMsg.append(exp.getAtom().getBool() ? "True" : "False");
	infoMsg.append(")");
	return infoMsg;
}

QString QtInterpreter::numberString(Expression exp) {
	QString infoMsg;
	infoMsg.append("(");
	infoMsg.append(QString::number(exp.getAtom().getNumber()));
	infoMsg.append(")");
	return infoMsg;
}

QString QtInterpreter::pointString(Expression exp) {
	QString infoMsg;
	infoMsg.append("(");
	infoMsg.append(QString::number(pointX(exp.getAtom().getPoint())));
	infoMsg.append(", ");
	infoMsg.append(QString::number(pointY(exp.getAtom().getPoint())));
	infoMsg.append(")");
	return infoMsg;
}

QString QtInterpreter::lineString(Expression exp) {
	QString infoMsg;
	infoMsg.append(("(("));
	infoMsg.append(QString::number(pointX(exp.getAtom().getLine().first)));
	infoMsg.append(", ");
	infoMsg.append(QString::number(pointY(exp.getAtom().getLine().first)));
	infoMsg.append("), (");
	infoMsg.append(QString::number(pointX(exp.getAtom().getLine().second)));
	infoMsg.append(", ");
	infoMsg.append(QString::number(pointY(exp.getAtom().getLine().second)));
	infoMsg.append("))");
	return infoMsg;
}

QString QtInterpreter::arcString(Expression exp) {
	QString infoMsg;
	infoMsg.append(("(("));
	infoMsg.append(QString::number(pointX(exp.getAtom().getArc().center)));
	infoMsg.append(", ");
	infoMsg.append(QString::number(pointY(exp.getAtom().getArc().center)));
	infoMsg.append("), (");
	infoMsg.append(QString::number(pointX(exp.getAtom().getArc().start)));
	infoMsg.append(", ");
	infoMsg.append(QString::number(pointY(exp.getAtom().getArc().start)));
	infoMsg.append(") ");
	infoMsg.append(QString::number(exp.getAtom().getArc().span));
	infoMsg.append(")");
	return infoMsg;
}
