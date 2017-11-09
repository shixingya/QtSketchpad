#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsSceneMouseEvent>
#include <QtGui>

class Shape
{
public:

        enum Code {
                Line,
                Rect
        };

        Shape();

        virtual void startDraw(QGraphicsSceneMouseEvent * event) = 0;
        virtual void drawing(QGraphicsSceneMouseEvent * event) = 0;
};

#endif // SHAPE_H
