#include "PaintView.h"
#define VIEW_CENTER viewport()->rect().center()
#define VIEW_WIDTH  viewport()->rect().width()
#define VIEW_HEIGHT viewport()->rect().height()
PaintView::PaintView(QWidget *parent) :
    QGraphicsView(parent)
{
    _zoomDelta=0.1;  // 缩放的增量
    _scaleValue=1.0;
    _bMouseTranslate=false;
    _translateSpeed=1.0;
}

PaintView::~PaintView()
{

}
void PaintView::ZoomIn()
{
    zoom(1 + _zoomDelta);
}

// 缩小
void PaintView::ZoomOut()
{
    zoom(1 - _zoomDelta);
}
void PaintView::zoom(float scaleFactor)
{
    // 防止过小或过大
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
    _scaleValue *= scaleFactor;
}

void PaintView::wheelEvent(QWheelEvent *event)
{
    // 滚轮的滚动量
    QPoint scrollAmount = event->angleDelta();
    // 正值表示滚轮远离使用者（放大），负值表示朝向使用者（缩小）
    scrollAmount.y() > 0 ? ZoomIn() :ZoomOut();
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
// 平移
void PaintView::mouseMoveEvent(QMouseEvent *event)
{
    if (_bMouseTranslate){
        QPointF mouseDelta = mapToScene(event->pos()) - mapToScene(_lastMousePos);
        translate(mouseDelta);
    }

    _lastMousePos = event->pos();

    QGraphicsView::mouseMoveEvent(event);
}

void PaintView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == _translateButton) {
        // 当光标底下没有 item 时，才能移动
        QPointF point = mapToScene(event->pos());
        if (scene()->itemAt(point, transform()) == NULL)  {
            _bMouseTranslate = true;
            _lastMousePos = event->pos();
        }
    }

    QGraphicsView::mousePressEvent(event);
}

void PaintView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == _translateButton)
        _bMouseTranslate = false;

    QGraphicsView::mouseReleaseEvent(event);
}
void PaintView::translate(QPointF delta)
{
    // 根据当前 zoom 缩放平移数
    delta *= _scaleValue;
    delta *= _translateSpeed;

    // view 根据鼠标下的点作为锚点来定位 scene
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    QPoint newCenter(VIEW_WIDTH / 2 - delta.x(),  VIEW_HEIGHT / 2 - delta.y());
    centerOn(mapToScene(newCenter));

    // scene 在 view 的中心点作为锚点
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}

void PaintView::keyPressEvent(QKeyEvent *event)
{
    QGraphicsItem *focusItem=this->scene()->focusItem();
    switch (event->key()) {

    case Qt::Key_Up:
        if(focusItem==nullptr)
            translate(QPointF(0, -2));  // 上移
        else
        {
          focusItem->setPos(focusItem->pos().rx(),focusItem->pos().ry()-1);
        }

        break;
    case Qt::Key_Down:
        if(focusItem==nullptr)
            translate(QPointF(0, 2));  // 下移
        else
        {
          focusItem->setPos(focusItem->pos().rx(),focusItem->pos().ry()+1);
        }

        break;
    case Qt::Key_Left:
        translate(QPointF(-2, 0));  // 左移
        break;
    case Qt::Key_Right:
        translate(QPointF(2, 0));  // 右移
        break;
    case Qt::Key_Plus:  // 放大
        if(focusItem==nullptr)
            ZoomIn();
        else
        {
            qreal scaleSize=focusItem->scale()+0.2;
            if(scaleSize>20) scaleSize=20;
            QPointF centerPos=  focusItem->boundingRect().center() ;
            focusItem->setTransformOriginPoint(centerPos);
            focusItem->setScale(scaleSize);
        }
        break;
    case Qt::Key_Minus:  // 缩小
        if(focusItem==nullptr)
            ZoomOut();
        else
        {
            qreal scaleSize=focusItem->scale()-0.2;
            if(scaleSize<0.05) scaleSize=0.05;
            QPointF centerPos=  focusItem->boundingRect().center() ;
            focusItem->setTransformOriginPoint(centerPos);
            focusItem->setScale(scaleSize);
        }
        break;
    case Qt::Key_Space:  // 逆时针旋转
        if(focusItem==nullptr)
            rotate(-5);  // 下移
        else
        {
            //图元自转
            QPointF centerPos=  focusItem->boundingRect().center() ;
            focusItem->setTransformOriginPoint(centerPos);
            focusItem->setRotation(focusItem->rotation()-5);
        }
        break;
    case Qt::Key_Enter:  // 顺时针旋转
    case Qt::Key_Return:
        if(focusItem==nullptr)
            rotate(5);  // 上移
        else
        {
            //图元自转
            QPointF centerPos=  focusItem->boundingRect().center() ;
            focusItem->setTransformOriginPoint(centerPos);
            focusItem->setRotation(focusItem->rotation()+5);
        }
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}
void PaintView::SetTranslateSpeed(qreal speed)
{
    // 建议速度范围
    Q_ASSERT_X(speed >= 0.0 && speed <= 2.0,
               "InteractiveView::setTranslateSpeed", "Speed should be in range [0.0, 2.0].");
    _translateSpeed = speed;
}
