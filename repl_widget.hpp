// File: repl_widget.hpp
// Author: Samuel McFalls

#ifndef REPL_WIDGET_H
#define REPL_WIDGET_H

#include <QObject>
#include <QLineEdit>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <list>
#include <string>

class REPLWidget : public QWidget {
Q_OBJECT

public:

	// Default construct a REPLWidget
	REPLWidget(QWidget * parent = nullptr);

	// keyPressEvent handler
	// If the enter key is pressed, the input text should be signaled and then cleared.
	// @param evt The event to handle
	void keyPressEvent(QKeyEvent * evt);

signals:

	// A signal that sends the current edited text as a QString when the return key is pressed.
	void lineEntered(QString);

private:

	QLabel * prompt;
	QLineEdit * input;
	std::list<QString> history;
	std::list<QString>::iterator historyPos;

	void historyUp();
	void historyDown();

};

#endif