#include "Line.h"

Line::Line()
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Line::startDraw(QGraphicsSceneMouseEvent * event)
{
    startPos=event->scenePos();
}

void Line::drawing(QGraphicsSceneMouseEvent * event)
{
    EndPos=event->scenePos();
    QLineF newLine(startPos,EndPos);
    setLine(newLine);

}
void Line::endDraw(QGraphicsSceneMouseEvent *event)
{

}
bool Line::CheckIsContainsPoint(QPointF p)
{
    return shape().contains(p);
}
void Line::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
}
