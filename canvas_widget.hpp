// File: canvas_widget.hpp
// Author: Samuel McFalls

#ifndef CANVAS_WIDGET_H
#define CANVAS_WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class CanvasWidget : public QWidget {
Q_OBJECT
	
public:

	// Default construct a CanvasWidget
	CanvasWidget(QWidget * parent = nullptr);

public slots:

	// A public slot that accepts a signal in the form of a QGraphicItem pointer containing an 
	// object derived from QGraphicsItem to draw
	void addGraphic(QGraphicsItem * item);

private:

	QGraphicsScene * scene;
	QGraphicsView * view;

};

#endif