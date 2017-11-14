#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>
#include "Shape.h"
class Text :  public Shape, public QGraphicsTextItem
{
public:
    Text();
    ~Text()
    {

    }
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    void focusOutEvent(QFocusEvent *event) ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
}
;
#endif // TEXT_H
