#ifndef STOCKPILE_H
#define STOCKPILE_H

#include "cargo.h"
#include <QList>
class Stockpile
{
public:
    Stockpile();
    void addCargo(QString name,uint amo ,double pri,uint wig,QString exp);   //往仓库中添加货物
    QString searceCargo(QString name,uint amo);    //判断仓库中有无此货物
    QList<Cargo *>cargo_list;   //仓库or货架中的货物列表
private:


};

#endif // STOCKPILE_H
