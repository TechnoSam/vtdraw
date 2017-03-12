// File: qgraphics_arc_item.cpp
// Author: Samuel McFalls

#include "qgraphics_arc_item.hpp"

#include <QGraphicsEllipseItem>
#include <QPainter>

void QGraphicsArcItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {

	painter->drawArc(rect(), startAngle(), spanAngle());

}
