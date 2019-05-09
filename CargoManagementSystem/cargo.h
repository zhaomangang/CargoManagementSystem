#ifndef CARGO_H
#define CARGO_H
#include <QString>

//商品类，包含商品名称及数量
class Cargo
{
public:
    Cargo();
    void scan(QString name,uint amo ,double pri,uint wig,QString exp);    //赋值
    QString returnName();   //返回商品名称
    uint returnAmount();    //返回商品数目
    double returnPrice();
    uint returnWight();
    QString returnExplain();
    void reduceAmount(uint amo);    //减少数量

    QString cargo_name; //商品名称
    uint amount;    //需要的数目
    double price; //单价
    uint wight; //重量
    QString explain;    //说明

private:


};

#endif // CARGO_H
