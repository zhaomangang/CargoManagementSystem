#ifndef STOCKPILE_H
#define STOCKPILE_H

#include "cargo.h"
#include <QList>
class Stockpile
{
public:
    Stockpile();
    void setStockName(QString name);    //设置储物库名称 仓库or货架
    void addCargo(QString name,uint amo ,double pri,uint wig,QString exp);   //往仓库中添加货物
    void loadInfo();    //从数据库中加载信息
    QString searceCargo(QString name,uint amo);    //判断仓库中有无此货物
    QList<Cargo *>cargo_list;   //仓库or货架中的货物列表
private:
    QString stock_name; //仓库or货架


};

#endif // STOCKPILE_H
