// File: canvas_widget.cpp
// Author: Samuel McFalls

#include "canvas_widget.hpp"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QLayout>

CanvasWidget::CanvasWidget(QWidget * parent) {

	QGraphicsScene * scene = new QGraphicsScene(this);
	scene->addText("Hello Lyoko!");

	QGraphicsView * view = new QGraphicsView(scene);
	view->show();

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(view);

	this->setLayout(layout);

}

void CanvasWidget::addGraphic(QGraphicsItem * item) {



}