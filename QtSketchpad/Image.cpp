#include "Image.h"

const QString ImagePath =":/ico/12121.png";
Image::Image()
{

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Image::startDraw(QGraphicsSceneMouseEvent * event)
{
    QPixmap pixmap =QPixmap::fromImage(QImage(ImagePath));
    setPixmap(pixmap);
}
void Image::drawing(QGraphicsSceneMouseEvent * event)
{

}
void Image::endDraw(QGraphicsSceneMouseEvent *event)
{

}
bool Image::CheckIsContainsPoint(QPointF p)
{
    return contains(p);
}

void Image::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
}
