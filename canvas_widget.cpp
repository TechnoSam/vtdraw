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

	QGraphicsScene * scene = new QGraphicsScene(this);
	scene->addText("Hello Lyoko!");

	QGraphicsItem * test = new QGraphicsEllipseItem(QRectF(0, 0, 100, 100));
	QGraphicsEllipseItem * arc = new QGraphicsArcItem();
	arc->setRect(QRectF(200, 200, 100, 100));
	arc->setStartAngle(45 * 16);
	arc->setSpanAngle(90 * 16);

	scene->addItem(test);
	scene->addItem(arc);

	// Line ((0, 0), (-100, -100))
	scene->addLine(QLineF(QPointF(0, 0), QPointF(-100, -100)));

	// Point (250, 250)
	double radius = 2;
	scene->addEllipse(250 - radius, 250 - radius, radius * 2, radius * 2,
		QPen(), QBrush(Qt::black));

	QGraphicsView * view = new QGraphicsView(scene);
	view->show();

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(view);

	this->setLayout(layout);

}

void CanvasWidget::addGraphic(QGraphicsItem * item) {



}