#ifndef PENPATH_H
#define PENPATH_H

#include <QGraphicsPathItem>
#include "Shape.h"
class PenPath : public Shape, public QGraphicsPathItem
{
public:
    PenPath();
    ~PenPath()
    {

    }
    QPainterPath _path;
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
};
#endif // PENPATH_H
