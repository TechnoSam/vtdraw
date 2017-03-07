// File: message_widget.cpp
// Author: Samuel McFalls

#include "message_widget.hpp"

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QLayout>

MessageWidget::MessageWidget(QWidget * parent): QWidget(parent) {

	QLabel * messageLabel = new QLabel(this);
	messageLabel->setText("Message:");

	QLineEdit * message = new QLineEdit(this);
	message->setReadOnly(true);

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(messageLabel);
	layout->addWidget(message);

	this->setLayout(layout);

}

void MessageWidget::info(QString message) {



}

void MessageWidget::error(QString message) {



}