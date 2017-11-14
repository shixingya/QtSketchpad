#ifndef PAINTVIEW_H
#define PAINTVIEW_H

#include <QtWidgets>


class PaintView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit PaintView(QWidget *parent = 0);
    ~PaintView();

    void ZoomOut();
    void ZoomIn();
    void SetTranslateSpeed(qreal speed);
private:
    Qt::MouseButton _translateButton;  // 平移按钮
    qreal  _zoomDelta;  // 缩放的增量
    qreal _scaleValue;  // 缩放值
    QPoint  _lastMousePos;  // 鼠标最后按下的位置
    qreal _translateSpeed;  // 平移速度
    bool _bMouseTranslate;

    void zoom(float scaleFactor);
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void translate(QPointF delta);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // PAINTVIEW_H
