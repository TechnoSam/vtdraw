// File: vtdraw.cpp
// Author: Samuel McFalls

#include <QApplication>

#include "main_window.hpp"

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.setMinimumSize(800, 600);

	mainWindow.show();

	return app.exec();

}