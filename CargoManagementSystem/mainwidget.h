#ifndef MAINWIDGET_H
#define MAINWIDGET_H

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

private slots:
    void on_sure_clicked();


    void on_pushButton_clicked();

    void on_amount_1_editingFinished();

public slots:
    void slotAffrimCharge(uint user);
private:
    Ui::MainWidget *ui;
    QList<User*> user_list;  //声明客户列表
    QList<Cargo*> cargo_list_temp;   //声明商品列表
    QList<MyMessageBox*> message_list;  //声明对话框列表
    Stockpile warehouse;    //声明仓库
    Stockpile shelf;    //声明货架

};

#endif // MAINWIDGET_H
