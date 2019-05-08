#include "mymessagebox.h"
#include "ui_mymessagebox.h"

MyMessageBox::MyMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyMessageBox)
{
    ui->setupUi(this);

}

MyMessageBox::~MyMessageBox()
{
    delete ui;
}

void MyMessageBox::setInfo(QString info, uint user_monent)
{
    ui->display->append(QStringLiteral("名称\t数目\t价格\t重量\t备注"));
    ui->display->append(info);
    this->user = user_monent;
    this->show();
}

void MyMessageBox::on_yes_clicked()
{
    //点击收取时发送信号给主窗口关闭当前提示框
    emit sigCharge(this->user);
    this->hide();
}
