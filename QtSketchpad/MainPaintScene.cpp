#include "MainPaintScenee.h"


MainPaintScene::MainPaintScene(QWidget *parent) :
    QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::gray);


    this->addRect(0,0,width(),height(),QPen(Qt::green),QBrush(Qt::red));


    QGraphicsTextItem* _textItem =new QGraphicsTextItem(QString::fromUtf8("是的 我可以"));
    _textItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    this->addItem(_textItem);

    QGraphicsEllipseItem* _testEllipse =new QGraphicsEllipseItem(0, 0, 20, 40);
    _testEllipse->setFlag(QGraphicsItem::ItemIsMovable);
    this->addItem(_testEllipse);
}

MainPaintScene::~MainPaintScene()
{

}
void MainPaintScene::SetBackGroundImage(QString path)
{
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
