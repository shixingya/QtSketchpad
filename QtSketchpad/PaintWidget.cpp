#include "PaintWidget.h"

PaintWidget::PaintWidget(QObject *parent)
        : QGraphicsScene(parent)
{
  currShapeCode=Shape::Line;
  currItem=NULL;
  perm=false;
}

void PaintWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        switch(currShapeCode)
        {
        case Shape::Line:
                {
                        Line *line = new Line;
                        currItem = line;
                        addItem(line);
                        break;
                }
        case Shape::Rect:
                {
                        Rect *rect = new Rect;
                        currItem = rect;
                        addItem(rect);
                        break;
                }
        }
        if(currItem) {
                currItem->startDraw(event);
                perm = false;
        }
        QGraphicsScene::mousePressEvent(event);
}

void PaintWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
        if(currItem && !perm) {
            {
                currItem->drawing(event);
            }
        }
        QGraphicsScene::mouseMoveEvent(event);

}

void PaintWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
        perm = true;
        QGraphicsScene::mouseReleaseEvent(event);
}
