#ifndef MYMESSAGEBOX_H
#define MYMESSAGEBOX_H

#include <QDialog>

namespace Ui {
class MyMessageBox;
}

class MyMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit MyMessageBox(QWidget *parent = nullptr);
    ~MyMessageBox();
    void setInfo(QString info,uint user_monent);

private slots:
    void on_yes_clicked();

private:
    Ui::MyMessageBox *ui;
    uint user;  //当前用户

signals:
    void sigCharge(uint user);   //点击确认收取发送信号
};

#endif // MYMESSAGEBOX_H
