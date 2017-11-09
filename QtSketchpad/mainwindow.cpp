#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QtGui>
#include "PaintWidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1200,650);
    ui->graphicsView->resize(1000,200);
    _mainPaintScene =new MainPaintScene(ui->graphicsView);

    ui->graphicsView->setScene(_mainPaintScene);
    ui->graphicsView->centerOn(0,0);
    setBackGroundImage("D:/2008.png");
    //    QToolBar *bar = this->addToolBar("Tools");
    //    QActionGroup *group = new QActionGroup(bar);

    //    QAction *drawLineAction = new QAction("Line", bar);
    //    //drawLineAction->setIcon(QIcon(":/line.png"));
    //    drawLineAction->setToolTip(tr("Draw a line."));
    //    drawLineAction->setStatusTip(tr("Draw a line."));
    //    drawLineAction->setCheckable(true);
    //    drawLineAction->setChecked(true);
    //    group->addAction(drawLineAction);
    //    bar->addAction(drawLineAction);

    //    QAction *drawRectAction = new QAction("Rectangle", bar);
    //    //drawRectAction->setIcon(QIcon(":/rect.png"));
    //    drawRectAction->setToolTip(tr("Draw a rectangle."));
    //    drawRectAction->setStatusTip(tr("Draw a rectangle."));
    //    drawRectAction->setCheckable(true);
    //    group->addAction(drawRectAction);
    //    bar->addAction(drawRectAction);


    //    QLabel *statusMsg = new QLabel;
    //    statusBar()->addWidget(statusMsg);

    //    PaintWidget *paintWidget = new PaintWidget(this->parent());
    //    QGraphicsView *view = new QGraphicsView(paintWidget, this);
    //    view->setSceneRect(0,0,800,480);

    //    setCentralWidget(view);

    //    connect(drawLineAction, SIGNAL(triggered()),
    //            this, SLOT(drawLineActionTriggered()));
    //    connect(drawRectAction, SIGNAL(triggered()),
    //            this, SLOT(drawRectActionTriggered()));
    //    connect(this, SIGNAL(changeCurrentShape(Shape::Code)),
    //            paintWidget, SLOT(setCurrentShape(Shape::Code)));
    //    connect(saveScreen, SIGNAL(triggered()),
    //            paintWidget, SLOT(onSaveScreen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//铅笔画
void MainWindow::on_pushButton_clicked()
{

}

//插入图片
void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                    ".",tr("Image Files (*.png *.jpg *.bmp)"));
    _mainPaintScene->InsertPicture(fileName);
}

//组合图片
void MainWindow::on_pushButton_3_clicked()
{

}


//插入文字
void MainWindow::on_pushButton_6_clicked()
{

}

//保存绘制
void MainWindow::on_pushButton_4_clicked()
{
    _mainPaintScene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    QString path = "D:/5566.png";
    QImage image(QSize(_mainPaintScene->width(),_mainPaintScene->height()),QImage::Format_RGB32);
    QPainter painter(&image);
    ui->graphicsView-> render(&painter);
    bool OK=  image.save(path);
    if (!OK)
    {
        QMessageBox::about(NULL,"","save failed!");
    }
    else
        QMessageBox::about(NULL,"","save success!");

}


//更换底图
void MainWindow::on_pushButton_5_clicked()
{
    _mainPaintScene->clear();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                                    ".",tr("Image Files (*.png *.jpg *.bmp)"));

    _mainPaintScene->SetBackGroundImage(fileName);
}

//场景放大
void MainWindow::on_pushButton_7_clicked()
{
    //_mainPaintScene->set
}

//场景缩小
void MainWindow::on_pushButton_8_clicked()
{

}

//图片30度顺时针旋转
void MainWindow::on_pushButton_9_clicked()
{

}


void MainWindow::setBackGroundImage(QString path)
{

}
