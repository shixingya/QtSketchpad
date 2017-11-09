/********************************************************************************
** Form generated from reading UI file 'PaintWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTWIDGET_H
#define UI_PAINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaintWidget
{
public:

    void setupUi(QWidget *PaintWidget)
    {
        if (PaintWidget->objectName().isEmpty())
            PaintWidget->setObjectName(QStringLiteral("PaintWidget"));
        PaintWidget->resize(400, 300);

        retranslateUi(PaintWidget);

        QMetaObject::connectSlotsByName(PaintWidget);
    } // setupUi

    void retranslateUi(QWidget *PaintWidget)
    {
        PaintWidget->setWindowTitle(QApplication::translate("PaintWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PaintWidget: public Ui_PaintWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTWIDGET_H
