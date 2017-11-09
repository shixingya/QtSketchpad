#ifndef MAINPAINTSCENEE_H
#define MAINPAINTSCENEE_H

#include <QtWidgets>

class MainPaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MainPaintScene(QWidget *parent = 0);
    ~MainPaintScene();

    void InsertPicture(QString path);
    void SetBackGroundImage(QString path);
private:

};

#endif // MAINPAINTSCENEE_H
