#include "cargo.h"

Cargo::Cargo()
{

}
void Cargo::scan(QString name, uint amo, double pri, uint wig, QString exp)
{
    //将传入的商品名及所需数量赋给当前对象
    this->cargo_name = name;
    this->amount = amo;
    this->price = pri;
    this->wight = wig;
    this->explain = exp;

}
void Cargo::reduceAmount(uint amo)
{
    //减少货物数量
    this->amount -= amo;
}

QString Cargo::returnName()
{
    //返回当前商品名称
    return this->cargo_name;
}
uint Cargo::returnAmount()
{
    //返回当前商品所需数量
    return this->amount;
}

double Cargo::returnPrice()
{
    return this->price;
}
uint Cargo::returnWight()
{
    return this->wight;
}
QString Cargo::returnExplain()
{
    return this->explain;
}
