//货物存储类，货架or仓库

#include "stockpile.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>    //sql语句
#include <QVariantList>

Stockpile::Stockpile()
{


}

void Stockpile::setStockName(QString name)
{
    stock_name = name;
    loadInfo(); //从数据库中加载信息
}

void Stockpile::loadInfo()
{
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

    /*
    //建表,用于开发时设计数据库，后期不需要执行
    if(this->stock_name=="warehouse")
    {
        qDebug()<<"warehouse";
        //如果当前储物库是仓库
        query.exec("create table warehouse(name varchar(255) primary key,amount int,price double,wight int,explain varchar(255));");
    }else if(this->stock_name=="shelf"){
        //如果是货架
        query.exec("create table shelf(name varchar(255) primary key,amount int,price double,wight int,explain varchar(255));");
    }



    //插入测试数据
    if(this->stock_name=="warehouse")
    {
        //如果当前储物库是仓库
        query.exec("insert into warehouse(name, amount, price,wight,explain) values('可乐',100,3,95,'饮料');");  //插入
        query.exec("insert into warehouse(name, amount, price,wight,explain) values('雪碧',100,2.5,80,'饮料');");  //插入
        query.exec("insert into warehouse(name, amount, price,wight,explain) values('好猫',100,25,20,'香烟');");  //插入
    }else if(this->stock_name=="shelf"){
        //如果是货架
        query.exec("insert into shelf(name, amount, price,wight,explain) values('可乐',100,3,95,'饮料');");  //插入
        query.exec("insert into shelf(name, amount, price,wight,explain) values('雪碧',100,2.5,80,'饮料');");  //插入
        query.exec("insert into shelf(name, amount, price,wight,explain) values('好猫',100,25,20,'香烟');");  //插入
    }
    */


    //遍历数据库
    if(this->stock_name=="warehouse")
    {
        //如果当前储物库是仓库
        query.exec("select * from warehouse");
    }else if(this->stock_name=="shelf"){
        //如果是货架
        query.exec("select * from shelf");
    }


    while(query.next()) //一行一行遍历
    {
        //取出当前行内容
        qDebug()<< query.value("name").toString()
                << query.value("amount").toInt()
                << query.value("price").toDouble()
                << query.value("wight").toInt()
                << query.value("explain").toString();
        Cargo *temp_cargo = new Cargo;
        temp_cargo->scan(query.value("name").toString(),query.value("amount").toInt(),query.value("price").toDouble()
                         ,query.value("wight").toInt(),query.value("explain").toString());

        cargo_list.append(temp_cargo);

    }
}

void Stockpile::addCargo(QString name, uint amo, double pri, uint wig, QString exp)
{
    //传入要添加的货物名及信息
    Cargo *temp_cargo = new Cargo();
    temp_cargo->scan(name,amo,pri,wig,exp);
    this->cargo_list.append(temp_cargo);
}

QString Stockpile::searceCargo(QString name, uint amo)
{
    //判断仓库中有无此货物无返回no有返回货物信息（价格、重量、说明、等）

}
