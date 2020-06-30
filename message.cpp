#include "message.h"
#include "ui_message.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>

#include "connect.h"

//新消息数量
extern int messages_num ;

//上面的显示，下面的添加
QString show , add;

//获取消息信息
void get_messages()
{
    //test
    show="你好";
};


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


        //载入下一条留言
        ui->textBrowser_2->append("我说：");
        QString temp;
       // temp.sprintf("messages_num=%d",messages_num);
       // ui->textBrowser_2->append(temp);

    }

    messages_num--;
}


