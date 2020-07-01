#include "message.h"
#include "ui_message.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>

#include "connect.h"


message::message(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/mainpic/pic/message_bac.jpg"));
}

message::~message()
{
    delete ui;
}

//返回主界面
void message::on_pushButton_clicked()
{
    this->close();
}

//阅读下一消息
void message::on_pushButton_2_clicked()
{

    //上面的显示
    QString show ;
    {
       //获取下一条消息
        show="你好！";
    }

    //清空现有框
    ui->textBrowser->clear();
    ui->textEdit->clear();

    //载入下一条留言
    ui->textBrowser->setText(show);

}


//评论
void message::on_pushButton_3_clicked()
{
    //写在下面的
    QString add;
    //获取
    add=ui->textEdit->toPlainText();

    //添加
    ui->textBrowser->append("###");
    ui->textBrowser->append(add);
    ui->textBrowser->append("###");
    {
        //还要发给数据库


    }

}
