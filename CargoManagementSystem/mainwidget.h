#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QList>
#include "user.h"
#include "cargo.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void readInfo();    //读取需要的商品及数目

private slots:
    void on_sure_clicked();


    void on_pushButton_clicked();

    void on_amount_1_editingFinished();

private:
    Ui::MainWidget *ui;
    QList<User*> user_list;  //声明客户列表
    QList<Cargo*> cargo_list_temp;   //声明商品列表
};

#endif // MAINWIDGET_H
