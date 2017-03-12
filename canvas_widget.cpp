// File: canvas_widget.cpp
// Author: Samuel McFalls

#include "canvas_widget.hpp"
#include "qgraphics_arc_item.hpp"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QLayout>

CanvasWidget::CanvasWidget(QWidget * parent) {

	scene = new QGraphicsScene(this);

	view = new QGraphicsView(scene);
	view->show();

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(view);

	this->setLayout(layout);

}

void CanvasWidget::addGraphic(QGraphicsItem * item) {

	scene->addItem(item);

}