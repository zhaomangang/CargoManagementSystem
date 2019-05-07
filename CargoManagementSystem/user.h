#ifndef USER_H
#define USER_H

#include <QList>
#include "cargo.h"
class User
{
public:
    User();
    QList<Cargo *> cargo_list;    //声明当前用户的商品列表
private:


};

#endif // USER_H
