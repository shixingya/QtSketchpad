#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QtWidgets"
#include <QMainWindow>
#include "Shape.h"
#include "MainPaintScenee.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainPaintScene * _mainPaintScene ;
    //设置背景图
    void setBackGroundImage(QString path);
signals:
    void changeCurrentShape(Shape::Code);
    void saveScreen();
public slots:
    void  drawLineActionTriggered()
    {
        emit changeCurrentShape(Shape::Line);
    }

    void  drawRectActionTriggered()
    {
        emit changeCurrentShape(Shape::Rect);
    }
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
};

#endif // MAINWINDOW_H
