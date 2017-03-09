// File: repl_widget.cpp
// Author: Samuel McFalls

#include "repl_widget.hpp"

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QLayout>
#include <QKeyEvent>

#include <QDebug>

REPLWidget::REPLWidget(QWidget * parent) : QWidget(parent) {

	prompt = new QLabel(this);
	prompt->setText("vtscript>");

	input = new QLineEdit(this);

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(prompt);
	layout->addWidget(input);

	this->setLayout(layout);

}

void REPLWidget::keyPressEvent(QKeyEvent * evt) {

	if (evt->key() == Qt::Key::Key_Return) {
		lineEntered(input->text());
		input->clear();
	}

	else if (evt->key() == Qt::Key::Key_Up) {
		qDebug() << "Up Arrow Pressed";
	}

	else if (evt->key() == Qt::Key::Key_Down) {
		qDebug() << "Down Arrow Pressed";
	}

}