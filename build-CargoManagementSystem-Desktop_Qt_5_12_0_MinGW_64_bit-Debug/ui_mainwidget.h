/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QFrame *frame;
    QGridLayout *gridLayout;
    QLineEdit *cargo_1;
    QSpinBox *amount_1;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *sure;
    QTextEdit *display;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(620, 520);
        frame = new QFrame(MainWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(160, 260, 248, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cargo_1 = new QLineEdit(frame);
        cargo_1->setObjectName(QString::fromUtf8("cargo_1"));

        gridLayout->addWidget(cargo_1, 1, 0, 1, 1);

        amount_1 = new QSpinBox(frame);
        amount_1->setObjectName(QString::fromUtf8("amount_1"));
        amount_1->setMaximum(1000);
        amount_1->setDisplayIntegerBase(10);

        gridLayout->addWidget(amount_1, 1, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(MainWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 430, 93, 28));
        sure = new QPushButton(MainWidget);
        sure->setObjectName(QString::fromUtf8("sure"));
        sure->setGeometry(QRect(170, 450, 101, 28));
        display = new QTextEdit(MainWidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(140, 20, 291, 221));
        display->setReadOnly(true);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        label_2->setText(QApplication::translate("MainWidget", "\346\225\260\347\233\256", nullptr));
        label->setText(QApplication::translate("MainWidget", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        pushButton->setText(QApplication::translate("MainWidget", "PushButton", nullptr));
        sure->setText(QApplication::translate("MainWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
