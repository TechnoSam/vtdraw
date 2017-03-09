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

	history.push_front("");
	historyPos = history.begin();

}

void REPLWidget::keyPressEvent(QKeyEvent * evt) {

	if (evt->key() == Qt::Key::Key_Return) {

		if (input->text().isEmpty()) {
			return;
		}

		// Get an iterator to the second element in the list
		// This is always safe because begin != end
		std::list<QString>::iterator first = history.begin();
		first++;
		// Insert before first
		history.insert(first, input->text());
		// Reset the history position
		historyPos = history.begin();

		lineEntered(input->text());
		input->clear();

	}

	else if (evt->key() == Qt::Key::Key_Up) {
		historyUp();
	}

	else if (evt->key() == Qt::Key::Key_Down) {
		historyDown();
	}

}

void REPLWidget::historyUp() {
	// Get an iterator to the last element in the list
	// end points past the last element
	std::list<QString>::iterator last = history.end();
	last--;
	if (historyPos != last) {
		historyPos++;
	}
	input->setText(*historyPos);
}

void REPLWidget::historyDown() {
	if (historyPos != history.begin()) {
		historyPos--;
	}
	input->setText(*historyPos);
}