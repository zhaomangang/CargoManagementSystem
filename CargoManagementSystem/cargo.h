#ifndef CARGO_H
#define CARGO_H
#include <QString>

//商品类，包含商品名称及数量
class Cargo
{
public:
    Cargo();
    void scan(QString name,uint amo);    //赋值
    QString returnName();   //返回商品名称
    uint returnAmount();    //返回商品数目
    QString cargo_name; //商品名称
    uint amount;    //需要的数目
private:


};

#endif // CARGO_H
