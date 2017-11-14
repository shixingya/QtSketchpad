#include "PenPath.h"

PenPath::PenPath()
{
   // setFlag(QGraphicsItem::ItemIsMovable, true);
  //  setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void PenPath::startDraw(QGraphicsSceneMouseEvent * event)
{
    _path.moveTo(event->scenePos());
}

void PenPath::drawing(QGraphicsSceneMouseEvent * event)
{
    _path.lineTo(event->scenePos());
     setPath(_path);
}
bool PenPath::CheckIsContainsPoint(QPointF pointf)
{
   return  path().contains(pointf);
}
void PenPath::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
}
void PenPath::endDraw(QGraphicsSceneMouseEvent *event)
{

}
