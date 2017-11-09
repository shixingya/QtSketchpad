/********************************************************************************
** Form generated from reading UI file 'Shape.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPE_H
#define UI_SHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shape
{
public:

    void setupUi(QWidget *Shape)
    {
        if (Shape->objectName().isEmpty())
            Shape->setObjectName(QStringLiteral("Shape"));
        Shape->resize(400, 300);

        retranslateUi(Shape);

        QMetaObject::connectSlotsByName(Shape);
    } // setupUi

    void retranslateUi(QWidget *Shape)
    {
        Shape->setWindowTitle(QApplication::translate("Shape", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Shape: public Ui_Shape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPE_H
