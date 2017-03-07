// File: repl_widget.cpp
// Author: Samuel McFalls

#include "repl_widget.hpp"

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QLayout>

REPLWidget::REPLWidget(QWidget * parent) : QWidget(parent) {

	QLabel * prompt = new QLabel(this);
	prompt->setText("vtscript>");

	QLineEdit * input = new QLineEdit(this);

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(prompt);
	layout->addWidget(input);

	this->setLayout(layout);

}