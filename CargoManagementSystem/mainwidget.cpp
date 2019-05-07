#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}


MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::readInfo()
{

}

void MainWidget::on_sure_clicked()
{
    //点击确定按钮时，
    User *temp_user = new User();
    for(int i=0;i<cargo_list_temp.size();i++)
    {
        qDebug()<<"line30";
        //当前商品列表不空
        temp_user->cargo_list.append(cargo_list_temp.at(i));
    }
    cargo_list_temp.clear();    //清空临时商品列表
    ui->display->clear();
    user_list.append(temp_user);    //将临时用户添加到用户列表
}

void MainWidget::on_pushButton_clicked()
{
    //测试按钮
    for(int j=0;j<user_list.size();j++)
    {
        qDebug()<<"user"<<j;
        for(int i=0;i<user_list.at(j)->cargo_list.size();i++)
        {
            qDebug()<<user_list.at(j)->cargo_list.at(i)->cargo_name;
            qDebug()<<user_list.at(j)->cargo_list.at(i)->amount;
        }

    }

}

void MainWidget::on_amount_1_editingFinished()
{
    //数目输入完成时
    if(ui->cargo_1->text()!=NULL&&ui->amount_1->value()!=0)
    {
        qDebug()<<"line43 tianj";
        //当数目改变时读取ui界面输入的商品及数目
        Cargo *temp_cargo = new Cargo();
        temp_cargo->scan(ui->cargo_1->text(),ui->amount_1->text().toUInt());
        cargo_list_temp.append(temp_cargo); //添加到临时列表
        //显示添加的商品
        QString temp = QString("%1 *%2").arg(ui->cargo_1->text()).arg(ui->amount_1->text());
        ui->display->append(temp);
        //清空编辑框

        ui->cargo_1->clear();
        ui->amount_1->setValue(0);
    }

}
