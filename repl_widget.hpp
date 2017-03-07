// File: repl_widget.hpp
// Author: Samuel McFalls

#ifndef REPL_WIDGET_H
#define REPL_WIDGET_H

#include <QObject>
#include <QLineEdit>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>

class REPLWidget : public QWidget {
Q_OBJECT

public:

	// Default construct a REPLWidget
	REPLWidget(QWidget * parent = nullptr);

	void keyPressEvent(QKeyEvent * evt);

signals:

	// A signal that sends the current edited text as a QString when the return key is pressed.
	void lineEntered(QString);

private:

	QLabel * prompt;
	QLineEdit * input;

};

#endif