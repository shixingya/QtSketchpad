/********************************************************************************
** Form generated from reading UI file 'Rect.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECT_H
#define UI_RECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rect
{
public:

    void setupUi(QWidget *Rect)
    {
        if (Rect->objectName().isEmpty())
            Rect->setObjectName(QStringLiteral("Rect"));
        Rect->resize(400, 300);

        retranslateUi(Rect);

        QMetaObject::connectSlotsByName(Rect);
    } // setupUi

    void retranslateUi(QWidget *Rect)
    {
        Rect->setWindowTitle(QApplication::translate("Rect", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Rect: public Ui_Rect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECT_H
