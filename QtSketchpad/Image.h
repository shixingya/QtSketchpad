#ifndef IMAGE_H
#define IMAGE_H

#include <QGraphicsPixmapItem>
#include "Shape.h"
class Image : public Shape, public QGraphicsPixmapItem
{
public:
    Image();
    ~Image()
    {

    }
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
};


#endif // IMAGE_H
