/********************************************************************************
** Form generated from reading UI file 'mymessagebox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMESSAGEBOX_H
#define UI_MYMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_MyMessageBox
{
public:
    QTextEdit *display;
    QPushButton *yes;

    void setupUi(QDialog *MyMessageBox)
    {
        if (MyMessageBox->objectName().isEmpty())
            MyMessageBox->setObjectName(QString::fromUtf8("MyMessageBox"));
        MyMessageBox->resize(400, 300);
        display = new QTextEdit(MyMessageBox);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(10, 10, 381, 231));
        display->setReadOnly(true);
        yes = new QPushButton(MyMessageBox);
        yes->setObjectName(QString::fromUtf8("yes"));
        yes->setGeometry(QRect(150, 250, 93, 28));

        retranslateUi(MyMessageBox);

        QMetaObject::connectSlotsByName(MyMessageBox);
    } // setupUi

    void retranslateUi(QDialog *MyMessageBox)
    {
        MyMessageBox->setWindowTitle(QApplication::translate("MyMessageBox", "Dialog", nullptr));
        yes->setText(QApplication::translate("MyMessageBox", "\346\224\266\345\217\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMessageBox: public Ui_MyMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMESSAGEBOX_H
