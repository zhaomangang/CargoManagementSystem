#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QDateTime>
#include <QDir>
#include <QWidget>
#include <QList>
#include "user.h"
#include "cargo.h"
#include "stockpile.h"
#include <QPushButton>
#include <QAction>
#include "mymessagebox.h"

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
    void getCargo();    //从仓库中or货架上找货物
    void updateWorehouse(); //更新仓库数据库
    void updateShelf(); //更新货架数据库

private slots:
    void on_sure_clicked();


    void on_pushButton_clicked();

    void on_amount_1_editingFinished();

    void on_ware_house_add_clicked();

    void on_warehouse_change_clicked();

    void on_shelf_add_clicked();

    void on_shelf_change_clicked();

public slots:
    void slotAffrimCharge(uint user);

private:
    Ui::MainWidget *ui;
    QList<User*> user_list;  //声明客户列表
    QList<Cargo*> cargo_list_temp;   //声明商品列表
    QList<MyMessageBox*> message_list;  //声明对话框列表
    Stockpile warehouse;    //声明仓库
    Stockpile shelf;    //声明货架


protected:

   //  void closeEvent(QCloseEvent *event);


signals:


};

#endif // MAINWIDGET_H
