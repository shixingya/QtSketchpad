#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include "Shape.h"

class Line : public Shape, public QGraphicsLineItem
{
public:
        Line();

        void startDraw(QGraphicsSceneMouseEvent * event);
        void drawing(QGraphicsSceneMouseEvent * event);
};

#endif // LINE_H
