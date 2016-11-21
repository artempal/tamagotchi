/********************************************************************************
** Form generated from reading UI file 'dialogstart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTART_H
#define UI_DIALOGSTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogStart
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *DialogStart)
    {
        if (DialogStart->objectName().isEmpty())
            DialogStart->setObjectName(QStringLiteral("DialogStart"));
        DialogStart->resize(400, 300);
        pushButton = new QPushButton(DialogStart);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 120, 111, 51));

        retranslateUi(DialogStart);

        QMetaObject::connectSlotsByName(DialogStart);
    } // setupUi

    void retranslateUi(QDialog *DialogStart)
    {
        DialogStart->setWindowTitle(QApplication::translate("DialogStart", "Dialog", 0));
        pushButton->setText(QApplication::translate("DialogStart", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogStart: public Ui_DialogStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTART_H
