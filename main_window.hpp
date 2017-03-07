// File: main_window.hpp
// Author: Samuel McFalls

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <string>

#include <QWidget>

#include "message_widget.hpp"
#include "repl_widget.hpp"
#include "canvas_widget.hpp"

class MainWindow : public QWidget {
Q_OBJECT

public:

	// Default construct a MainWindow
	MainWindow(QWidget * parent = nullptr);

	// Default construct a MainWidow, using filename as the script file to attempt to preload
	MainWindow(std::string filename, QWidget * parent = nullptr);

};

#endif