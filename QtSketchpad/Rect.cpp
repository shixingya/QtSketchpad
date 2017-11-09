#include "Rect.h"
Rect::Rect()
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Rect::startDraw(QGraphicsSceneMouseEvent * event)
{
    setRect(QRectF(event->scenePos(), QSizeF(0, 0)));

}

void Rect::drawing(QGraphicsSceneMouseEvent * event)
{



    QRectF r(rect().topLeft(),
             QSizeF(event->scenePos().x() - rect().topLeft().x(), event->scenePos().y() - rect().topLeft().y()));

    QPointF pos =this->transformOriginPoint();
    qreal rec =this->rotation();
    setTransformOriginPoint(event->pos());
    setRotation(-30);
    setRect(r);
    setTransformOriginPoint(pos);
    setRotation(rec);


}
