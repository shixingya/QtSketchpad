#ifndef PAINTVIEW_H
#define PAINTVIEW_H

#include <QtWidgets>


class PaintView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit PaintView(QWidget *parent = 0);
    ~PaintView();

private:
    void paintEvent(QPaintEvent *event);
};

#endif // PAINTVIEW_H
