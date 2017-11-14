#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsSceneMouseEvent>
#include <QtGui>

class Shape
{
public:

    enum Code {
        Line,
        Rect,
        Image,
        PenPath,
        Text,
        None //没有绘制图元
    };

    Shape();
    virtual ~Shape(){}

    void SetAdjustState(bool val)
    {
        _isAdjustState=val;
        setAdjustFlag(val);
    }
//    int  GetShapeID()
//    {
//        return _shapeId;
//    }

//    int _shapeId;
    virtual void startDraw(QGraphicsSceneMouseEvent * event) = 0;
    virtual void drawing(QGraphicsSceneMouseEvent * event) = 0;
    virtual void endDraw(QGraphicsSceneMouseEvent * event) = 0;
    virtual bool CheckIsContainsPoint(QPointF)=0;
    virtual void setAdjustFlag(bool)=0;
    bool _isAdjustState;
    bool _finishDraw;
    QList<QPointF> _adjustPoints;

};

#endif // SHAPE_H
