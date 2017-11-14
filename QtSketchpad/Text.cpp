#include "Text.h"

Text::Text()
{
    QFont f;
    f.setPointSize(50);
    f.setBold(true);
    f.setFamily("Helvetica");
    setFont(f);
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setZValue(1000.0);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void Text::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
    QGraphicsTextItem::focusOutEvent(event);
}
void Text::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    if (textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}
void Text::startDraw(QGraphicsSceneMouseEvent * event)
{
    // setPlainText("hello world");
    setDefaultTextColor(Qt::red);
    setPos(event->scenePos());
}

void Text::drawing(QGraphicsSceneMouseEvent * event)
{

}
void Text::endDraw(QGraphicsSceneMouseEvent *event)
{

}
bool Text::CheckIsContainsPoint(QPointF p)
{
    return shape().contains(p);
}
void Text::setAdjustFlag(bool val)
{
    setFlag(QGraphicsItem::ItemIsMovable, val);
    setFlag(QGraphicsItem::ItemIsSelectable, val);
}
void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsTextItem::paint(painter,option,widget);
}
