// File: message_widget.cpp
// Author: Samuel McFalls

#include "message_widget.hpp"

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QLayout>
#include <QPalette>

MessageWidget::MessageWidget(QWidget * parent): QWidget(parent) {

	messageLabel = new QLabel(this);
	messageLabel->setText("Message:");

	message = new QLineEdit(this);
	message->setReadOnly(true);

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(messageLabel);
	layout->addWidget(message);

	this->setLayout(layout);

}

void MessageWidget::info(QString message) {

	this->message->setText(message);
	QPalette palette;
	palette.setColor(QPalette::Highlight, QColor(51, 153, 255));
	this->message->setPalette(palette);
	this->message->deselect();

}

void MessageWidget::error(QString message) {

	this->message->setText(message);
	QPalette palette;
	palette.setColor(QPalette::Highlight, QColor(Qt::red));
	this->message->setPalette(palette);
	this->message->selectAll();

}