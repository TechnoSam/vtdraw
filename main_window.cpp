// File: main_window.cpp
// Author: Samuel McFalls

#include "main_window.hpp"

#include <QWidget>
#include <QLayout>

MainWindow::MainWindow(QWidget * parent) : QWidget(parent) {

	REPLWidget * repl = new REPLWidget(this);

	QVBoxLayout * layout = new QVBoxLayout(this);

	layout->addWidget(repl);

	this->setLayout(layout);

}

MainWindow::MainWindow(std::string filename, QWidget * parent) : QWidget(parent) {



}