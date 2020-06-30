#include "sign.h"
#include "ui_sign.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connect.h"
#include "QMessageBox"

QString username,password;

//setEchoMode(QLineEdit::PasswordEchoOnEdit);
//echoLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

sign::sign(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
}

sign::~sign()
{
    delete ui;
}

void sign::on_pushButton_clicked()
{
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();

    //
    if(username=="")
    {
        QMessageBox::about(NULL,"message","用户名不能为空");
        return;
    }
    if(username=="root")
    {
        QMessageBox::about(NULL,"message","用户名已存在！");
        return;
    }
    else
    {
        if(ui->lineEdit_2->text().isEmpty())
        {
            QMessageBox::about(NULL,"message","密码不能为空！");
            return;
        }
        else
        {
            QMessageBox::about(NULL,"message","注册成功，请重新登录");
            ui->lineEdit_2->clear();
        }
    }
}

void sign::on_pushButton_2_clicked()
{
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();

    //
    if(username!="root")
     {
        QMessageBox::about(NULL,"message","该用户不存在！");
        return;
    }
    if(username=="root"&&password!="root")
    {
        QMessageBox::about(NULL,"message","密码错误");
        return;
    }
    if(username=="root"&&password=="root")
    {
       QMessageBox::about(NULL,"message","啊啊啊！\n奇怪的东西进来了！");
       this->close();
       MainWindow *w=new MainWindow (this);
       w->show();
    }

}
