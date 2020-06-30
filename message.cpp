#include "message.h"
#include "ui_message.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>

#include "connect.h"

//新消息数量
extern int messages_num ;

//假设也就这几个消息
QString  words[10];

//获取消息信息
void get_messages()
{
    //test
    words[1]="hello";
    words[0]="bye";

};


message::message(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
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
   //在第一次触发时
    static int flag=1;
    if(flag==1)
    {
        get_messages();
        flag=0;
    }

    if(messages_num < 0)
    {
        QMessageBox::about(NULL, "message!", " no more message!");
        this->close();
    }
    else
    {
        //清空现有框
        ui->textBrowser_2->clear();
        ui->textBrowser_3->clear();

        //载入下一条留言
        ui->textBrowser_2->append("我说：");
        QString temp;
        temp.sprintf("messages_num=%d",messages_num);
        ui->textBrowser_2->append(temp);
        ui->textBrowser_2->append(words[messages_num]);
        ui->textBrowser_3->append("t他人留言");
    }

    messages_num--;
}


