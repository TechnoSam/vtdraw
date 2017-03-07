// File: main_window.cpp
// Author: Samuel McFalls

#include "main_window.hpp"

#include <QWidget>
#include <QLayout>

#include "qt_interpreter.hpp"

MainWindow::MainWindow(QWidget * parent) : QWidget(parent) {

	MessageWidget * message = new MessageWidget(this);
	CanvasWidget * canvas = new CanvasWidget(this);
	REPLWidget * repl = new REPLWidget(this);

	QVBoxLayout * layout = new QVBoxLayout(this);

	layout->addWidget(message);
	layout->addWidget(canvas);
	layout->addWidget(repl);

	this->setLayout(layout);

	QtInterpreter * interp = new QtInterpreter(this);

	QObject::connect(repl, SIGNAL(lineEntered(QString)), interp, SLOT(parseAndEvaluate(QString)));
	QObject::connect(interp, SIGNAL(info(QString)), message, SLOT(info(QString)));
	QObject::connect(interp, SIGNAL(error(QString)), message, SLOT(error(QString)));

}

MainWindow::MainWindow(std::string filename, QWidget * parent) : QWidget(parent) {



}