#include "PaintView.h"

PaintView::PaintView(QWidget *parent) :
    QGraphicsView(parent)
{

}

PaintView::~PaintView()
{

}

void  PaintView::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);
    QPainter painter(this->viewport());
    painter.setBrush(Qt::gray);
    QFont font;
    font.setPixelSize(45);
    painter.setFont(font);
    painter.drawText(QRectF(width()*0.3,height()*0.2,width()*0.3,height()*0.3),"made by andy!");

}
