// File: qgraphics_arc_item.hpp
// Author: Samuel McFalls

#ifndef QGRAPHICS_ARC_ITEM_H
#define QGRAPHICS_ARC_ITEM_H

#include <QGraphicsEllipseItem>

class QGraphicsArcItem : public QGraphicsEllipseItem {

	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

};

#endif