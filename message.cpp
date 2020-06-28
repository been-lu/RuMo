#include "message.h"
#include "ui_message.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<stdio.h>

int message_num;

//假设也就这几个消息
QString  words[10];

//获取消息信息
void get_messages(){
    //test

    message_num=0;
    words[0]="hello";
    words[1]="bye";
    //

};


//读取消息并回复
void read_message()
{

}

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
    MainWindow *w =new MainWindow(this);
    w->show();
}

//阅读下一消息
void message::on_pushButton_2_clicked()
{
    message_num--;
    if(message_num<=0)
        QMessageBox::about(NULL, "message!", " no more message!");
    else
    {
        ;
    }
}
