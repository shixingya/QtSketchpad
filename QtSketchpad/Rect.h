#ifndef RECT_H
#define RECT_H
#include <QStyleOptionGraphicsItem>
#include <QGraphicsRectItem>
#include "Shape.h"

class Rect : public Shape, public QGraphicsRectItem
{
public:
    Rect();
    ~Rect()
    {

    }
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);

private:
    bool _cScale;
    QCursor *_cursor;
    int _direction;
    QPointF _start;
    QPointF _startPaintPos;
    QPointF _end;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape()const;
    QRectF boundingRect() const;
    void ResetRect(QRectF rect);
protected:


    void keyPressEvent(QKeyEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

};

#endif // RECT_H
