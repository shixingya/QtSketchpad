#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include "Shape.h"

class Line : public Shape, public QGraphicsLineItem
{
public:
    Line();
    ~Line()
    {

    }

    QPointF startPos;
    QPointF EndPos;
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
};

#endif // LINE_H
