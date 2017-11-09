#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H
#include <QtWidgets>
#include <QtGui>
#include <QDebug>
#include <QGraphicsScene>
#include "Shape.h"
#include "Line.h"
#include "Rect.h"

class PaintWidget : public QGraphicsScene
{
    Q_OBJECT

public:
    PaintWidget(QObject *parent = 0);

public slots:
    void setCurrentShape(Shape::Code s)
    {
        if(s != currShapeCode) {
            currShapeCode = s;
        }
    }

    void onSaveScreen()
    {
        QString path = "D:/5566.png";
        QImage image(QSize(1024,height()),QImage::Format_RGB32);
        QPainter painter(&image);
        this->setBackgroundBrush(Qt::red);
        this-> render(&painter);
        bool OK=  image.save(path);
        if (!OK)
        {
            QMessageBox::about(NULL,"","save failed!");
        }
        else
            QMessageBox::about(NULL,"","save success!");

    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Shape::Code currShapeCode;
    Shape *currItem;
    bool perm;
};

#endif // PAINTWIDGET_H
