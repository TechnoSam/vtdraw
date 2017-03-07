// File: message_widget.hpp
// Author: Samuel McFalls

#ifndef MESSAGE_WIDGET_H
#define MESSAGE_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class MessageWidget : public QWidget {
Q_OBJECT

public:

	// Default construct a MessageWidget displaying no text
	MessageWidget(QWidget * parent = nullptr);

public slots:

	// a public slot accepting an informational message to display, clearing any error formatting
	void info(QString message);

	// a public slot accepting an error message to display as selected text highlighted with a red background.
	void error(QString message);

private:

	QLabel * messageLabel;

	QLineEdit * message;

};

#endif