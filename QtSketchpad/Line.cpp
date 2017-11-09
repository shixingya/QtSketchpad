#include "Line.h"

Line::Line()
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Line::startDraw(QGraphicsSceneMouseEvent * event)
{
        setLine(QLineF(event->scenePos(), event->scenePos()));
}

void Line::drawing(QGraphicsSceneMouseEvent * event)
{
        QLineF newLine(line().p1(), event->scenePos());
        setLine(newLine);

}
