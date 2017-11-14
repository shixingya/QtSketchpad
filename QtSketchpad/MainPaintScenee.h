#ifndef MAINPAINTSCENEE_H
#define MAINPAINTSCENEE_H

#include <QtWidgets>
#include "Shape.h"
#include "Line.h"
#include "Rect.h"
#include "Image.h"
#include "PenPath.h"
#include "Text.h"
class MainPaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MainPaintScene(QWidget *parent = 0);
    ~MainPaintScene();

    void InsertPicture(QString path);
    void SetBackGroundImage(QString path);
private:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    Shape *_currItem;

    Shape::Code _currShapeCode;

    QList<Shape*> _shapeList;
public slots:
    void setCurrentShape(Shape::Code s)
    {
        if(s != _currShapeCode) {
            _currShapeCode = s;
        }
    }
};

#endif // MAINPAINTSCENEE_H
