// File: main_window.cpp
// Author: Samuel McFalls

#include "main_window.hpp"

#include <QWidget>
#include <QLayout>

MainWindow::MainWindow(QWidget * parent) : QWidget(parent) {

	MessageWidget * message = new MessageWidget(this);
	REPLWidget * repl = new REPLWidget(this);

	QVBoxLayout * layout = new QVBoxLayout(this);

	layout->addWidget(message);
	layout->addWidget(repl);

	this->setLayout(layout);

}

MainWindow::MainWindow(std::string filename, QWidget * parent) : QWidget(parent) {



}