// File: repl_widget.hpp
// Author: Samuel McFalls

#ifndef REPL_WIDGET_H
#define REPL_WIDGET_H

#include <QObject>
#include <QLineEdit>

class REPLWidget : public QWidget {
Q_OBJECT

public:

	// Default construct a REPLWidget
	REPLWidget(QWidget * parent = nullptr);

signals:

	// A signal that sends the current edited text as a QString when the return key is pressed.
	void lineEntered(QString);

};

#endif