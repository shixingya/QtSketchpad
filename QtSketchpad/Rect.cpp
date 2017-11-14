#include "Rect.h"
Rect::Rect()
{

    setZValue(0);
    setAcceptDrops(true);
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
    _cScale=false;
    _cursor=new QCursor;
    _direction=0;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
}

void Rect::startDraw(QGraphicsSceneMouseEvent * event)
{

    _startPaintPos=event->scenePos();
    _finishDraw=false;


}

bool Rect::CheckIsContainsPoint(QPointF pointf)
{
    return  shape().contains(mapFromScene(pointf));
}
void Rect::drawing(QGraphicsSceneMouseEvent * event)
{
    if(_finishDraw)
        return;
    QPointF pos =event->scenePos();
    QPointF dis =pos-_startPaintPos;
    if(pos.rx() > _startPaintPos.rx() && pos.ry() >_startPaintPos.ry())
        setRect(_startPaintPos.rx(),_startPaintPos.ry(),dis.rx(),dis.ry());

    else if(pos.rx() > _startPaintPos.rx() && pos.ry() <_startPaintPos.ry())
        setRect(_startPaintPos.rx(),pos.ry(),dis.rx(),-dis.ry());

    else if(pos.rx() < _startPaintPos.rx() && pos.ry() >_startPaintPos.ry())
        setRect(pos.rx(),_startPaintPos.ry(),-dis.rx(),dis.ry());

    else if(pos.rx() < _startPaintPos.rx() && pos.ry() <_startPaintPos.ry())
        setRect(pos.rx(),pos.ry(),-dis.rx(),-dis.ry());

}
void Rect::endDraw(QGraphicsSceneMouseEvent *event)
{
    _finishDraw=true;
    //绘制结束进入编辑状态

}

void Rect::setAdjustFlag(bool val)
{
    setFlag(QGraphicsItem::ItemIsMovable, val);
    setFlag(QGraphicsItem::ItemIsSelectable, val);
}
void Rect::ResetRect(QRectF rect)
{
    setRect(rect);
    update(boundingRect());
}

QRectF Rect::boundingRect()const{
    return QRectF(rect().x()-2,rect().y()-2,rect().width()+4,rect().height()+4);
}

QPainterPath Rect::shape()const{
    QPainterPath path;
    path.addRect(rect());
    return path;
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // painter->drawRect(rect());
    QStyleOptionGraphicsItem op;
    op.initFrom(widget);

    // 判断选中时，设置状态为 State_None
    if (option->state & QStyle::State_Selected)
        op.state = QStyle::State_None; ;

    // 调用默认方法，进行原始绘制
    QGraphicsRectItem::paint(painter, &op, widget);

    // 选中时绘制
    if (option->state & QStyle::State_Selected) {
        qreal itemPenWidth = pen().widthF();
        const qreal pad = itemPenWidth / 2;
        const qreal penWidth = 0;

        // 边框区域颜色
        QColor color = QColor(Qt::yellow);

        // 绘制实线
        painter->setPen(QPen(color, penWidth, Qt::SolidLine));
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(boundingRect().adjusted(pad, pad, -pad, -pad));

        // 绘制虚线
        painter->setPen(QPen(color, 0, Qt::DashLine));
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(boundingRect().adjusted(pad, pad, -pad, -pad));

        //绘制7个点
        QPointF distance =QPointF(rect().right(),rect().bottom()) -QPointF(rect().left(),rect().top());

        _adjustPoints.clear();
        _adjustPoints.push_back(QPointF(rect().left(),rect().top()));
        _adjustPoints.push_back(QPoint(rect().left()+0.5*distance.rx(),rect().top()));
        _adjustPoints.push_back(QPoint(rect().right(),rect().top()));
        _adjustPoints.push_back(QPoint(rect().left(),rect().top()+0.5*distance.ry()));
        _adjustPoints.push_back(QPoint(rect().right(),rect().top()+0.5*distance.ry()));
        _adjustPoints.push_back(QPoint(rect().left(),rect().bottom()));
        _adjustPoints.push_back(QPoint(rect().left()+0.5*distance.rx(),rect().bottom()));
        _adjustPoints.push_back(QPoint(rect().right(),rect().bottom()));
        QPen penP=painter->pen();
        penP.setWidth(4);
        penP.setColor(Qt::red);


        painter->setPen(penP);
        foreach (QPointF pointMember, _adjustPoints) {
            painter->drawPoint(pointMember);
        }
    }
}
void Rect::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {

    default:
        QGraphicsRectItem::keyPressEvent(event);
    }
}
void Rect::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(_isAdjustState==false)
        return;
    QPointF pos1=event->scenePos();
    QPointF lt=this->scenePos()+QPointF(rect().x(),rect().y());
    QPointF lb=this->scenePos()+QPointF(rect().x(),rect().y()+rect().height());
    QPointF rt=this->scenePos()+QPointF(rect().x()+rect().width(),rect().y());
    QPointF rb=this->scenePos()+QPointF(rect().x()+rect().width(),rect().y()+rect().height());
    if((pos1.x()<=lt.x()+2&&pos1.y()<=lt.y()+2)
            ||(pos1.x()>=rb.x()-2&&pos1.y()>=rb.y()-2)){
        _cursor->setShape(Qt::SizeFDiagCursor);
        if(pos1.x()<=lt.x()+2)_direction=8;
        else _direction=4;
    }else if((pos1.x()<=lb.x()+2&&pos1.y()>=lb.y()-2)
             ||(pos1.x()>=rt.x()-2&&pos1.y()<=rt.y()+2)){
        _cursor->setShape(Qt::SizeBDiagCursor);
        if(pos1.x()<=lb.x()+2)_direction=6;
        else _direction=2;
    }else if((pos1.x()<=lt.x()+2||pos1.x()>=rt.x()-2)
             &&(pos1.y()<=lb.y()&&pos1.y()>=lt.y())){
        _cursor->setShape(Qt::SizeHorCursor);
        if(pos1.x()<=lt.x()+2)_direction=7;
        else _direction=3;
    }else if((pos1.y()<=lt.y()+2||pos1.y()>=lb.y()-2)
             &&(pos1.x()>=lt.x()&&pos1.x()<=rt.x())){
        _cursor->setShape(Qt::SizeVerCursor);
        if(pos1.y()<=lt.y()+2)_direction=1;
        else _direction=5;
    }else{
        _cScale=false;
        _cursor->setShape(Qt::ArrowCursor);
    }
    this->setCursor(*_cursor);
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void Rect::hoverMoveEvent(QGraphicsSceneHoverEvent *event){
    if(_isAdjustState==false)
        return;
    QPointF pos1=event->scenePos();
    QPointF lt=this->scenePos()+QPointF(rect().x(),rect().y());
    QPointF lb=this->scenePos()+QPointF(rect().x(),rect().y()+rect().height());
    QPointF rt=this->scenePos()+QPointF(rect().x()+rect().width(),rect().y());
    QPointF rb=this->scenePos()+QPointF(rect().x()+rect().width(),rect().y()+rect().height());
    if((pos1.x()<=lt.x()+2&&pos1.y()<=lt.y()+2)
            ||(pos1.x()>=rb.x()-2&&pos1.y()>=rb.y()-2)){
        _cursor->setShape(Qt::SizeFDiagCursor);
        if(pos1.x()<=lt.x()+2)_direction=8;
        else _direction=4;
    }else if((pos1.x()<=lb.x()+2&&pos1.y()>=lb.y()-2)
             ||(pos1.x()>=rt.x()-2&&pos1.y()<=rt.y()+2)){
        _cursor->setShape(Qt::SizeBDiagCursor);
        if(pos1.x()<=lb.x()+2)_direction=6;
        else _direction=2;
    }else if((pos1.x()<=lt.x()+2||pos1.x()>=rt.x()-2)
             &&(pos1.y()<=lb.y()&&pos1.y()>=lt.y())){
        _cursor->setShape(Qt::SizeHorCursor);
        if(pos1.x()<=lt.x()+2)_direction=7;
        else _direction=3;
    }else if((pos1.y()<=lt.y()+2||pos1.y()>=lb.y()-2)
             &&(pos1.x()>=lt.x()&&pos1.x()<=rt.x())){
        _cursor->setShape(Qt::SizeVerCursor);
        if(pos1.y()<=lt.y()+2)_direction=1;
        else _direction=5;
    }else{
        _cScale=false;
        _cursor->setShape(Qt::ArrowCursor);
    }
    this->setCursor(*_cursor);
    update();
    QGraphicsItem::hoverMoveEvent(event);
}

void Rect::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if(_isAdjustState==false)
        return;
    _cursor->setShape(Qt::ArrowCursor);
    _cScale=false;
    this->setCursor(*_cursor);
    update();
    QGraphicsItem::hoverLeaveEvent(event);
}

//void Rect::mousePressEvent(QGraphicsSceneMouseEvent *event){
//    if(event->button()==Qt::LeftButton){
//        _start=event->scenePos();
//        _cScale=true;
//    }
//    update();
//    QGraphicsItem::mousePressEvent(event);
//}

//void Rect::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
//    int t=0;
//    t++;
//    t--;
//    if(_cScale){
//        QPointF dis;
//        _end=event->scenePos();
//        dis=_end-_start;
//        _start=_end;
//        switch(_direction){
//        case 1:
//        {
//            QRectF tem=QRectF(rect().x(),rect().y()+dis.y()/2,rect().width(),rect().height()-dis.y());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(0,dis.y()/2);
//            break;
//        }
//        case 2:
//        {
//            QRectF tem=QRectF(rect().x()+dis.x()/2,rect().y()+dis.y()/2,
//                              rect().width()+dis.x(),rect().height()-dis.y());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(-dis.x()/2,-dis.y()/2);
//            break;
//        }
//        case 3:
//        {
//            QRectF tem=QRectF(rect().x()+dis.x()/2,rect().y(),rect().width()+dis.x(),rect().height());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(-dis.x()/2,0);
//            break;
//        }
//        case 4:
//        {
//            QRectF tem=QRectF(rect().x()+dis.x()/2,rect().y()+dis.y()/2,
//                              rect().width()+dis.x(),rect().height()+dis.y());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(-dis.x()/2,-dis.y()/2);
//            break;
//        }
//        case 5:
//        {
//            QRectF tem=QRectF(rect().x(),rect().y()+dis.y()/2,rect().width(),rect().height()+dis.y());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(0,-dis.y()/2);
//            break;
//        }
//        case 6:
//        {
//            QRectF tem=QRectF(rect().x()+dis.x()/2,rect().y()+dis.y()/2,
//                              rect().width()-dis.x(),rect().height()+dis.y());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(-dis.x()/2,-dis.y()/2);
//            break;
//        }
//        case 7:
//        {
//            QRectF tem=QRectF(rect().x()+dis.x()/2,rect().y(),rect().width()-dis.x(),rect().height());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(dis.x()/2,0);
//            break;
//        }
//        case 8:
//        {
//            QRectF tem=QRectF(rect().x()+dis.x()/2,rect().y()+dis.y()/2,
//                              rect().width()-dis.x(),rect().height()-dis.y());
//            ResetRect(tem);
//            update(boundingRect());
//            moveBy(dis.x()/2,dis.y()/2);
//            break;
//        }
//        }
//    }
//    update();
//    QGraphicsItem::mouseMoveEvent(event);
//}

//void Rect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
//    _cScale=false;
//    update();
//    QGraphicsItem::mouseReleaseEvent(event);
//}
