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
    QFrame *frame_2;
    QLabel *label_3;
    QWidget *widget;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *name_c;
    QLineEdit *amount_c;
    QLineEdit *price_c;
    QLineEdit *wight_c;
    QLineEdit *explain_c;
    QPushButton *ware_house_add;
    QPushButton *warehouse_change;
    QFrame *frame_4;
    QLabel *label_15;
    QWidget *widget_3;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *name_h;
    QLineEdit *amount_h;
    QLineEdit *price_h;
    QLineEdit *wight_h;
    QLineEdit *explain_h;
    QPushButton *shelf_add;
    QPushButton *shelf_change;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(901, 559);
        frame = new QFrame(MainWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(100, 260, 248, 151));
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
        pushButton->setGeometry(QRect(620, 330, 101, 28));
        sure = new QPushButton(MainWidget);
        sure->setObjectName(QString::fromUtf8("sure"));
        sure->setGeometry(QRect(170, 440, 101, 28));
        display = new QTextEdit(MainWidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(10, 20, 451, 231));
        display->setReadOnly(true);
        frame_2 = new QFrame(MainWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(490, 20, 401, 131));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(12, 12, 60, 16));
        widget = new QWidget(frame_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 391, 101));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 20, 60, 16));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 20, 31, 16));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(170, 20, 60, 16));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(220, 20, 60, 16));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(270, 20, 60, 16));
        name_c = new QLineEdit(widget);
        name_c->setObjectName(QString::fromUtf8("name_c"));
        name_c->setGeometry(QRect(0, 40, 113, 21));
        amount_c = new QLineEdit(widget);
        amount_c->setObjectName(QString::fromUtf8("amount_c"));
        amount_c->setGeometry(QRect(120, 40, 31, 21));
        price_c = new QLineEdit(widget);
        price_c->setObjectName(QString::fromUtf8("price_c"));
        price_c->setGeometry(QRect(170, 40, 31, 21));
        wight_c = new QLineEdit(widget);
        wight_c->setObjectName(QString::fromUtf8("wight_c"));
        wight_c->setGeometry(QRect(220, 40, 31, 21));
        explain_c = new QLineEdit(widget);
        explain_c->setObjectName(QString::fromUtf8("explain_c"));
        explain_c->setGeometry(QRect(270, 40, 113, 21));
        ware_house_add = new QPushButton(widget);
        ware_house_add->setObjectName(QString::fromUtf8("ware_house_add"));
        ware_house_add->setGeometry(QRect(50, 70, 93, 28));
        warehouse_change = new QPushButton(widget);
        warehouse_change->setObjectName(QString::fromUtf8("warehouse_change"));
        warehouse_change->setGeometry(QRect(190, 70, 93, 28));
        frame_4 = new QFrame(MainWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(490, 160, 401, 131));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(12, 12, 60, 16));
        widget_3 = new QWidget(frame_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 30, 391, 101));
        label_16 = new QLabel(widget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 20, 60, 16));
        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(120, 20, 31, 16));
        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(170, 20, 60, 16));
        label_19 = new QLabel(widget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(220, 20, 60, 16));
        label_20 = new QLabel(widget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(270, 20, 60, 16));
        name_h = new QLineEdit(widget_3);
        name_h->setObjectName(QString::fromUtf8("name_h"));
        name_h->setGeometry(QRect(0, 40, 113, 21));
        amount_h = new QLineEdit(widget_3);
        amount_h->setObjectName(QString::fromUtf8("amount_h"));
        amount_h->setGeometry(QRect(120, 40, 31, 21));
        price_h = new QLineEdit(widget_3);
        price_h->setObjectName(QString::fromUtf8("price_h"));
        price_h->setGeometry(QRect(170, 40, 31, 21));
        wight_h = new QLineEdit(widget_3);
        wight_h->setObjectName(QString::fromUtf8("wight_h"));
        wight_h->setGeometry(QRect(220, 40, 31, 21));
        explain_h = new QLineEdit(widget_3);
        explain_h->setObjectName(QString::fromUtf8("explain_h"));
        explain_h->setGeometry(QRect(270, 40, 113, 21));
        shelf_add = new QPushButton(widget_3);
        shelf_add->setObjectName(QString::fromUtf8("shelf_add"));
        shelf_add->setGeometry(QRect(50, 70, 93, 28));
        shelf_change = new QPushButton(widget_3);
        shelf_change->setObjectName(QString::fromUtf8("shelf_change"));
        shelf_change->setGeometry(QRect(200, 70, 93, 28));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        label_2->setText(QApplication::translate("MainWidget", "\346\225\260\347\233\256", nullptr));
        label->setText(QApplication::translate("MainWidget", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        pushButton->setText(QApplication::translate("MainWidget", "\346\237\245\347\234\213\345\272\223\345\255\230\350\264\247\347\211\251", nullptr));
        sure->setText(QApplication::translate("MainWidget", "\347\241\256\345\256\232", nullptr));
        label_3->setText(QApplication::translate("MainWidget", "\344\273\223\345\272\223\347\256\241\347\220\206", nullptr));
        label_5->setText(QApplication::translate("MainWidget", "\350\264\247\347\211\251\345\220\215\347\247\260", nullptr));
        label_6->setText(QApplication::translate("MainWidget", "\346\225\260\351\207\217", nullptr));
        label_7->setText(QApplication::translate("MainWidget", "\345\215\225\344\273\267", nullptr));
        label_8->setText(QApplication::translate("MainWidget", "\351\207\215\351\207\217", nullptr));
        label_9->setText(QApplication::translate("MainWidget", "\350\257\264\346\230\216", nullptr));
        ware_house_add->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240\350\264\247\347\211\251", nullptr));
        warehouse_change->setText(QApplication::translate("MainWidget", "\344\277\256\346\224\271\350\264\247\347\211\251", nullptr));
        label_15->setText(QApplication::translate("MainWidget", "\350\264\247\346\236\266\347\256\241\347\220\206", nullptr));
        label_16->setText(QApplication::translate("MainWidget", "\350\264\247\347\211\251\345\220\215\347\247\260", nullptr));
        label_17->setText(QApplication::translate("MainWidget", "\346\225\260\351\207\217", nullptr));
        label_18->setText(QApplication::translate("MainWidget", "\345\215\225\344\273\267", nullptr));
        label_19->setText(QApplication::translate("MainWidget", "\351\207\215\351\207\217", nullptr));
        label_20->setText(QApplication::translate("MainWidget", "\350\257\264\346\230\216", nullptr));
        shelf_add->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240\350\264\247\347\211\251", nullptr));
        shelf_change->setText(QApplication::translate("MainWidget", "\344\277\256\346\224\271\350\264\247\347\211\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
