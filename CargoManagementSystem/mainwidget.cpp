#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>    //sql语句
#include <QVariantList>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //设置储物库名称，仓库*1，货架*1
    this->warehouse.setStockName("warehouse");
    this->shelf.setStockName("shelf");

   // connect(this,&MainWidget::close,this,MainWidget::updateShelf);

    //测试用数据，往仓库中添加一点东西
    /*
    warehouse.addCargo("可乐",100,3,21,"没有特殊说明"); //添加可乐，数量100，单价3,重量21，说明
    qDebug()<<"line12"<<warehouse.cargo_list.at(0)->returnPrice();
    warehouse.addCargo("雪碧",200,2.5,21,"说明");
    warehouse.addCargo("好猫",100,25,15,"烟");
    shelf.addCargo("可乐",100,3,21,"没有特殊说明");
    qDebug()<<"line17"<<" "<<warehouse.cargo_list.size();
    */
}






MainWidget::~MainWidget()
{
   // updateShelf();
   // updateWorehouse();
    delete ui;

}

void MainWidget::updateShelf()
{
    //更新货架数据库
    //从数据库中加载信息
    //打印Qt支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();

    //添加Sqlite数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("../info.db");


    //打开数据库
    if( !db.open())
    {
        //数据库打开失败
        qDebug()<<"line 26 open fail";
        return;
    }
    QSqlQuery query;
    query.exec("drop table shelf"); //删除原有表
    query.exec("create table shelf(name varchar(255) primary key,amount int,price double,wight int,explain varchar(255));");//新建表

    //将当前数据添加进表

        query.prepare("insert into shelf(name, amount, price,wight,explain) values(?,?,?,?,?);");
        QVariantList nameList;
        QVariantList amountlist;
        QVariantList pricelist;
        QVariantList wightlist;
        QVariantList explainlist;
        for(int i=0;i<shelf.cargo_list.size();i++)
        {
            qDebug()<<"update"<<shelf.cargo_list.at(i)->returnName();
            nameList << shelf.cargo_list.at(i)->returnName();
            amountlist<<shelf.cargo_list.at(i)->returnAmount();
            pricelist<<shelf.cargo_list.at(i)->returnPrice();
            wightlist<<shelf.cargo_list.at(i)->returnWight();
            explainlist<<shelf.cargo_list.at(i)->returnExplain();

        }


        //给字段绑定相应的值，按顺序绑定
        query.addBindValue(nameList);
        query.addBindValue(amountlist);
        query.addBindValue(pricelist);
        query.addBindValue(wightlist);
        query.addBindValue(explainlist);
        query.execBatch();

    //更新完打印，调试用
    query.exec("select * from shelf");
    while(query.next()) //一行一行遍历
    {
        //取出当前行内容
        qDebug()<< query.value("name").toString()
                << query.value("amount").toInt()
                << query.value("price").toDouble()
                << query.value("wight").toInt()
                << query.value("explain").toString();

    }
}
void MainWidget::updateWorehouse()
{
    //更新货架数据库
    //从数据库中加载信息
    //打印Qt支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();

    //添加Sqlite数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("../info.db");


    //打开数据库
    if( !db.open())
    {
        //数据库打开失败
        qDebug()<<"line 26 open fail";
        return;
    }
    QSqlQuery query;
    query.exec("drop table warehouse"); //删除原有表
    query.exec("create table warehouse(name varchar(255) primary key,amount int,price double,wight int,explain varchar(255));");//新建表

    //将当前数据添加进表

        query.prepare("insert into warehouse(name, amount, price,wight,explain) values(?,?,?,?,?);");
        QVariantList nameList;
        QVariantList amountlist;
        QVariantList pricelist;
        QVariantList wightlist;
        QVariantList explainlist;
        for(int i=0;i<warehouse.cargo_list.size();i++)
        {
            qDebug()<<"update"<<warehouse.cargo_list.at(i)->returnName();
            nameList << warehouse.cargo_list.at(i)->returnName();
            amountlist<<warehouse.cargo_list.at(i)->returnAmount();
            pricelist<<warehouse.cargo_list.at(i)->returnPrice();
            wightlist<<warehouse.cargo_list.at(i)->returnWight();
            explainlist<<warehouse.cargo_list.at(i)->returnExplain();

        }


        //给字段绑定相应的值，按顺序绑定
        query.addBindValue(nameList);
        query.addBindValue(amountlist);
        query.addBindValue(pricelist);
        query.addBindValue(wightlist);
        query.addBindValue(explainlist);
        query.execBatch();

    //更新完打印，调试用
    query.exec("select * from warehouse");
    while(query.next()) //一行一行遍历
    {
        //取出当前行内容
        qDebug()<< query.value("name").toString()
                << query.value("amount").toInt()
                << query.value("price").toDouble()
                << query.value("wight").toInt()
                << query.value("explain").toString();

    }

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
    getCargo(); //寻找货物
}


void MainWidget::slotAffrimCharge(uint user)
{
    //确认收取时
    qDebug()<<"line107"<<user;
    //寻找所需货物
    bool ware = false;  //仓库中是否找到
    bool shar = false;  //货架
    uint amount_temp = 0;   //仓库货物不足需从货架取的数目
    for(int i=0;i<user_list.at(user)->cargo_list.size();i++)
    {
        for(int j=0;j<warehouse.cargo_list.size();j++)
        {
            if(user_list.at(user)->cargo_list.at(i)->returnName()==warehouse.cargo_list.at(j)->returnName())
            {
                //仓库中找到
                ware = true;
                qDebug()<<"cangku zhao dao ";

                if(user_list.at(user)->cargo_list.at(i)->returnAmount() <= warehouse.cargo_list.at(j)->returnAmount())
                {
                    //仓库中够
                    qDebug()<<"cangku gou";
                    warehouse.cargo_list.at(j)->reduceAmount(user_list.at(user)->cargo_list.at(i)->returnAmount());




                }else{
                    //仓库中不够，需要从货架找
                    warehouse.cargo_list.at(j)->reduceAmount(warehouse.cargo_list.at(j)->returnAmount());
                    amount_temp = user_list.last()->cargo_list.at(i)->returnAmount() - warehouse.cargo_list.at(j)->returnAmount();

                    for(int j=0;j<shelf.cargo_list.size();j++)
                    {
                        if(user_list.at(user)->cargo_list.at(i)->returnName()==shelf.cargo_list.at(j)->returnName())
                        {
                            //货架中找到
                            shar = true;
                            qDebug()<<"cangku bu gou huojia zhao dao ";
                            qDebug()<<amount_temp;

                            if(amount_temp <= shelf.cargo_list.at(j)->returnAmount())
                            {
                                //货架中够
                                qDebug()<<"cangku bu gou,huojia gou";
                                shelf.cargo_list.at(j)->reduceAmount(amount_temp);




                            }else{
                                //货架中不够
                                qDebug()<<"cangku bu gou,huojia bu gou";



                            }
                        }else{
                            if(j==shelf.cargo_list.size()-1&&shar == false)
                            {
                                //货架中未找到
                                qDebug()<<"cangku bu gou huojia wei zhao";


                            }

                        }



                    }
                }
            }else{
                if(j == warehouse.cargo_list.size()-1&&ware == false)
                {
                    qDebug()<<j<<" "<<warehouse.cargo_list.size()-1;
                    //仓库中未找到，需要从货架找
                    for(int j=0;j<shelf.cargo_list.size();j++)
                    {
                        if(user_list.at(user)->cargo_list.at(i)->returnName()==shelf.cargo_list.at(j)->returnName())
                        {
                            //货架中找到
                            shar = true;


                            if(amount_temp <= shelf.cargo_list.at(j)->returnAmount())
                            {
                                //货架中够
                                qDebug()<<"cangku bu weizhao dao huo jia zhong gou";
                                shelf.cargo_list.at(j)->reduceAmount(user_list.at(user)->cargo_list.at(i)->returnAmount());




                            }else{
                                //货架中不够
                                qDebug()<<"cangku bu weizhao dao huo jia zhong bu ";

                            }
                        }else{
                            if(j==shelf.cargo_list.size()-1&&shar == false)
                            {
                                //货架中未找到
                                qDebug()<<"cangku wu huojia wei zhao";
                                //货架与仓库中未找到货物



                            }
                        }



                    }

                }
            }


        }

    }

    updateShelf();
    updateWorehouse();

}

void MainWidget::getCargo()
{
    QString infor;
   // uint user_moment;   //当前处理的客户
    uint price = 0,wight = 0;
    uint amount_temp = 0;   //仓库货物不足需从货架取的数目
    bool look = false;  //是否存在足够货物
    bool ware = false;  //仓库中是否找到
    bool shar = false;  //货架
    //寻找所需货物
    for(int i=0;i<user_list.last()->cargo_list.size();i++)
    {
        for(int j=0;j<warehouse.cargo_list.size();j++)
        {
            if(user_list.last()->cargo_list.at(i)->returnName()==warehouse.cargo_list.at(j)->returnName())
            {
                //仓库中找到
                ware = true;
                qDebug()<<"cangku zhao dao ";
                QString temp = QString("%1\t%2\t%3\t%4\t%5").arg(user_list.last()->cargo_list.at(i)->returnName())
                        .arg(user_list.last()->cargo_list.at(i)->returnAmount())
                        .arg(warehouse.cargo_list.at(j)->returnPrice())
                        .arg(warehouse.cargo_list.at(j)->returnWight())
                        .arg(warehouse.cargo_list.at(j)->returnExplain());
                infor.append(temp);
                infor.append("\n");
                if(user_list.last()->cargo_list.at(i)->returnAmount() <= warehouse.cargo_list.at(j)->returnAmount())
                {
                    //仓库中够
                    qDebug()<<"cangku gou";
                    price += warehouse.cargo_list.at(j)->returnPrice()*user_list.last()->cargo_list.at(i)->returnAmount();
                    wight += warehouse.cargo_list.at(j)->returnWight()*user_list.last()->cargo_list.at(i)->returnAmount();
                    look = true;



                }else{
                    //仓库中不够，需要从货架找
                    amount_temp = user_list.last()->cargo_list.at(i)->returnAmount() - warehouse.cargo_list.at(j)->returnAmount();
                    price += warehouse.cargo_list.at(j)->returnPrice()*warehouse.cargo_list.at(j)->returnAmount();
                    wight += warehouse.cargo_list.at(j)->returnWight()*warehouse.cargo_list.at(j)->returnAmount();
                    for(int j=0;j<shelf.cargo_list.size();j++)
                    {
                        if(user_list.last()->cargo_list.at(i)->returnName()==shelf.cargo_list.at(j)->returnName())
                        {
                            //货架中找到
                            shar = true;
                            qDebug()<<"cangku bu gou huojia zhao dao ";
                            qDebug()<<amount_temp;

                            if(amount_temp <= shelf.cargo_list.at(j)->returnAmount())
                            {
                                //货架中够
                                qDebug()<<"cangku bu gou,huojia gou";
                                price += shelf.cargo_list.at(j)->returnPrice()*amount_temp;
                                wight += shelf.cargo_list.at(j)->returnWight()*amount_temp;
                                look = true;



                            }else{
                                //货架中不够
                                qDebug()<<"cangku bu gou,huojia bu gou";
                                QString temp = QString("仓库+货架中[%1]不足 目前剩余:%2 \n需要：%3")
                                        .arg(shelf.cargo_list.at(j)->returnName())
                                        .arg(user_list.last()->cargo_list.at(i)->returnAmount()-amount_temp+shelf.cargo_list.at(j)->returnAmount())
                                        .arg(user_list.last()->cargo_list.at(i)->returnAmount());
                                QMessageBox::warning(this,QStringLiteral("库存不足"),temp);//对话框提示
                                look = false;


                            }
                        }else{
                            if(j==shelf.cargo_list.size()-1&&shar == false)
                            {
                                //货架中未找到
                                qDebug()<<"cangku bu gou huojia wei zhao";
                                QString temp = QString("[%1]仓库不足货架无 目前剩余:%2 \n需要：%3")
                                        .arg(shelf.cargo_list.at(j)->returnName())
                                        .arg(user_list.last()->cargo_list.at(i)->returnAmount()-amount_temp)
                                        .arg(user_list.last()->cargo_list.at(i)->returnAmount());
                                QMessageBox::warning(this,QStringLiteral("库存不足"),temp);//对话框提示
                                look = false;

                            }

                        }



                    }
                }
            }else{
                if(j == warehouse.cargo_list.size()-1&&ware == false)
                {
                    qDebug()<<j<<" "<<warehouse.cargo_list.size()-1;
                    //仓库中未找到，需要从货架找
                    for(int j=0;j<shelf.cargo_list.size();j++)
                    {
                        if(user_list.last()->cargo_list.at(i)->returnName()==shelf.cargo_list.at(j)->returnName())
                        {
                            //货架中找到
                            shar = true;
                            qDebug()<<"cangku bu weizhao dao huo jia zhao dao";
                            QString temp = QString("%1\t%2\t%3\t%4\t%5").arg(user_list.last()->cargo_list.at(i)->returnName())
                                    .arg(user_list.last()->cargo_list.at(i)->returnAmount())
                                    .arg(shelf.cargo_list.at(j)->returnPrice())
                                    .arg(shelf.cargo_list.at(j)->returnWight())
                                    .arg(shelf.cargo_list.at(j)->returnExplain());
                            infor.append(temp);
                            infor.append("\n");

                            if(amount_temp <= shelf.cargo_list.at(j)->returnAmount())
                            {
                                //货架中够
                                qDebug()<<"cangku bu weizhao dao huo jia zhong gou";
                                price += shelf.cargo_list.at(j)->returnPrice()*user_list.last()->cargo_list.at(i)->returnAmount();
                                wight += shelf.cargo_list.at(j)->returnWight()*user_list.last()->cargo_list.at(i)->returnAmount();
                                look = true;




                            }else{
                                //货架中不够
                                qDebug()<<"cangku bu weizhao dao huo jia zhong bu ";
                                QString temp = QString("仓库中无货,货架货物不足。\n%1 目前剩余:%2 \n需要：%3")
                                        .arg(shelf.cargo_list.at(j)->returnName())
                                        .arg(shelf.cargo_list.at(j)->returnAmount())
                                        .arg(user_list.last()->cargo_list.at(i)->returnAmount());
                                QMessageBox::warning(this,QStringLiteral("库存不足"),temp);//对话框提示
                                look = false;

                            }
                        }else{
                            if(j==shelf.cargo_list.size()-1&&shar == false)
                            {
                                //货架中未找到
                                qDebug()<<"cangku wu huojia wei zhao";
                                //货架与仓库中未找到货物
                                QString temp = QString("%1 仓库中无货,货架中无货").arg(user_list.last()->cargo_list.at(i)->returnName());
                                QMessageBox::warning(this,QStringLiteral("库存不足"),temp);//对话框提示
                                look = false;



                            }
                        }



                    }

                }
            }


        }

    }
    if(look==true)
    {
        //找到了所有货物后
        QString temp = QString("总价：%1 总重量：%2").arg(price).arg(wight);
        infor.append(temp);
        infor.append("\n是否收取？");
        //弹出对话框并添加进消息列表
        MyMessageBox *reminder_temp = new MyMessageBox();
        reminder_temp->setInfo(infor,user_list.size()-1);
        message_list.append(reminder_temp);
        connect(reminder_temp,&MyMessageBox::sigCharge,this,&MainWidget::slotAffrimCharge);
        //添加日志

        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
        ui->display_logo->append(current_date);
        for(int i=0;i<user_list.last()->cargo_list.size();i++)
        {
            QString te = QString("%1 *%2").arg(user_list.last()->cargo_list.at(i)->returnName())
                    .arg(user_list.last()->cargo_list.at(i)->returnAmount());
            //tem.append(te);
            ui->display_logo->append(te);
        }
        ui->display_logo->append(temp);


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
        temp_cargo->scan(ui->cargo_1->text(),ui->amount_1->text().toUInt(),0,0,"");
        cargo_list_temp.append(temp_cargo); //添加到临时列表
        //显示添加的商品
        QString temp = QString("%1 *%2").arg(ui->cargo_1->text()).arg(ui->amount_1->text());
        ui->display->append(temp);
        //清空编辑框

        ui->cargo_1->clear();
        ui->amount_1->setValue(0);
    }

}

void MainWidget::on_pushButton_clicked()
{
    //查看所有库存
    ui->display->clear();
    ui->display->append(QStringLiteral("仓库货物总览:"));
    ui->display->append(QStringLiteral("名称\t数目\t价格\t重量\t备注"));
    for(int i=0;i<this->warehouse.cargo_list.size();i++)
    {
        QString temp = QString("%1\t%2\t%3\t%4\t%5")
                .arg(warehouse.cargo_list.at(i)->returnName())
                .arg(warehouse.cargo_list.at(i)->returnAmount())
                .arg(warehouse.cargo_list.at(i)->returnPrice())
                .arg(warehouse.cargo_list.at(i)->returnWight())
                .arg(warehouse.cargo_list.at(i)->returnExplain());
        ui->display->append(temp);
    }

    ui->display->append(QStringLiteral("货架货物总览:"));
    ui->display->append(QStringLiteral("名称\t数目\t价格\t重量\t备注"));
    for(int i=0;i<this->shelf.cargo_list.size();i++)
    {
        QString temp = QString("%1\t%2\t%3\t%4\t%5")
                .arg(shelf.cargo_list.at(i)->returnName())
                .arg(shelf.cargo_list.at(i)->returnAmount())
                .arg(shelf.cargo_list.at(i)->returnPrice())
                .arg(shelf.cargo_list.at(i)->returnWight())
                .arg(shelf.cargo_list.at(i)->returnExplain());
        ui->display->append(temp);
    }
}
void MainWidget::on_ware_house_add_clicked()
{
    //仓库中添加货物

    warehouse.addCargo(ui->name_c->text(),ui->amount_c->text().toInt(),ui->price_c->text().toDouble(),
                       ui->wight_c->text().toInt(),ui->explain_c->text());
    updateWorehouse();
    ui->name_c->clear();
    ui->amount_c->clear();
    ui->price_c->clear();
    ui->wight_c->clear();
    ui->explain_c->clear();
}



void MainWidget::on_warehouse_change_clicked()
{
    //修改仓库中货物
    for(int i=0;i<warehouse.cargo_list.size();i++)
    {
        //寻找要修改的货物
        if(warehouse.cargo_list.at(i)->returnName()==ui->name_c->text())
        {
            //找到
            if(ui->amount_c->text()!="")
            {
                warehouse.cargo_list.at(i)->amount = ui->amount_c->text().toInt();

            }
            if(ui->price_c->text()!="")
            {
                warehouse.cargo_list.at(i)->price = ui->price_c->text().toDouble();
            }
            if(ui->wight_c->text()!="")
            {
                warehouse.cargo_list.at(i)->wight = ui->wight_c->text().toInt();

            }
            if(ui->explain_c->text()!="")
            {
                warehouse.cargo_list.at(i)->explain = ui->explain_c->text();
            }
        }
    }
    updateWorehouse();
    ui->name_c->clear();
    ui->amount_c->clear();
    ui->price_c->clear();
    ui->wight_c->clear();
    ui->explain_c->clear();
}

void MainWidget::on_shelf_add_clicked()
{
    //货架添加货物

    shelf.addCargo(ui->name_h->text(),ui->amount_h->text().toInt(),ui->price_h->text().toDouble(),
                       ui->wight_h->text().toInt(),ui->explain_h->text());
    updateWorehouse();
    ui->name_h->clear();
    ui->amount_h->clear();
    ui->price_h->clear();
    ui->wight_h->clear();
    ui->explain_h->clear();
}


void MainWidget::on_shelf_change_clicked()
{
    //货架修改货物

    for(int i=0;i<shelf.cargo_list.size();i++)
    {
        //寻找要修改的货物
        if(shelf.cargo_list.at(i)->returnName()==ui->name_h->text())
        {
            //找到
            if(ui->amount_c->text()!="")
            {
                shelf.cargo_list.at(i)->amount = ui->amount_h->text().toInt();

            }
            if(ui->price_c->text()!="")
            {
                shelf.cargo_list.at(i)->price = ui->price_h->text().toDouble();
            }
            if(ui->wight_c->text()!="")
            {
                shelf.cargo_list.at(i)->wight = ui->wight_h->text().toInt();

            }
            if(ui->explain_c->text()!="")
            {
                shelf.cargo_list.at(i)->explain = ui->explain_h->text();
            }
        }
    }
    updateShelf();
    ui->name_h->clear();
    ui->amount_h->clear();
    ui->price_h->clear();
    ui->wight_h->clear();
    ui->explain_h->clear();
}

