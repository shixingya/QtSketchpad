#include "MainPaintScenee.h"


MainPaintScene::MainPaintScene(QWidget *parent) :
    QGraphicsScene(parent)
{
    clearFocus();
    this->setBackgroundBrush(Qt::gray);
    _currShapeCode= Shape::None;
    _currItem=nullptr;
    /* QGraphicsTextItem* _textItem =new QGraphicsTextItem(QString::fromUtf8("是的 我可以"));
    _textItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    this->addItem(_textItem);

    QGraphicsEllipseItem* _testEllipse =new QGraphicsEllipseItem(0, 0, 20, 40);
    _testEllipse->setFlag(QGraphicsItem::ItemIsMovable);
    this->addItem(_testEllipse);*/

    QRect mainRect(0,0,width(),height());
    setSceneRect(mainRect);//设置场景范围
    addRect(mainRect,QPen(Qt::black));//把场景范围直观显示出来，只为了方便理解
}

MainPaintScene::~MainPaintScene()
{

}
void MainPaintScene::InsertPicture(QString path)
{
    QPixmap pixmap =QPixmap::fromImage(QImage(path));
    QGraphicsPixmapItem* pictureItem= this->addPixmap(pixmap);
    pictureItem->setFlag(QGraphicsItem::ItemIsMovable);
}
void MainPaintScene::SetBackGroundImage(QString path)
{
    qDeleteAll(_shapeList);
    _shapeList.clear();
    this->clear();

    this->addRect(0,0,width(),height(),QPen(Qt::green),QBrush(Qt::red));

    QPixmap pixmap =QPixmap::fromImage(QImage(path));
    QGraphicsPixmapItem* _backGroundItem= this->addPixmap(pixmap);

    if(pixmap.width()>pixmap.height())
    {
        //匹配宽度
        _backGroundItem->setScale( width()/pixmap.width());
    }
    else//匹配高度
    {
        _backGroundItem->setScale( height()/pixmap.height());
    }
    _backGroundItem->setPos(0,0);

    //_backGroundItem->setRotation(-45);//绕圆心逆时针旋转

}
void MainPaintScene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsItem *focusItem=this-> focusItem();

    switch (event->key())
    {
    case Qt::Key_Delete:
        if(_currItem !=nullptr)
        {
            for(QList<Shape*>::iterator itr=_shapeList.begin();
                itr!=_shapeList.end();itr++)
            {
                if((*itr)==_currItem)
                {
                    if(_currItem);
                    delete _currItem;
                    _currItem=nullptr;
                    _shapeList.erase(itr);
                    removeItem(focusItem);
                    break;
                }
            }
        }
        break;
    default:
        QGraphicsScene::keyPressEvent(event);
    }

}
void MainPaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //检查是否有选中的图元
    foreach (Shape *shape, _shapeList) {
        if(shape->CheckIsContainsPoint(event->scenePos()))
        {
            _currItem= shape;
            _currItem->SetAdjustState(true);
            QGraphicsScene::mousePressEvent(event);
            return;
        }
    }

    switch(_currShapeCode)
    {
    case Shape::Line:
    {
        Line *line = new Line;
        _currItem = line;
        addItem(line);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Rect:
    {
        Rect *rect = new Rect;
        _currItem = rect;
        addItem(rect);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Image:
    {
        Image *img = new Image;
        _currItem = img;
        addItem(img);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Text:
    {
        Text *text = new Text;
        _currItem = text;
        addItem(text);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::PenPath:
    {
        PenPath *penPath = new PenPath;
        _currItem = penPath;
        addItem(penPath);
        _shapeList.push_back(_currItem);
        break;
    }
    }
    if(_currItem) {
        _currItem->startDraw(event);

    }
    QGraphicsScene::mousePressEvent(event);
}
void MainPaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(_currItem ) {
        _currItem->drawing(event);
    }
    QGraphicsScene::mouseMoveEvent(event);

}

void MainPaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{  if(_currItem ) {

        _currItem->endDraw(event);

    }
    QGraphicsScene::mouseReleaseEvent(event);
}
