//货物存储类，货架or仓库

#include "stockpile.h"

Stockpile::Stockpile()
{

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
