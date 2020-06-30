#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "message.h"
#include "ui_message.h"

#include "set.h"
#include "ui_set.h"

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>

#include "connect.h"

//新消息数量
extern int messages_num ;
extern QString username;

//获取新消息数量（未读消息）
void recieve_message()
{
   messages_num=2;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //第一次进入时欢迎
    static int flag=1;
    if(flag==1)
    {
        flag=0;
        QMessageBox message(QMessageBox::NoIcon, "hello", "welcome!");
        message.setIconPixmap(QPixmap(":/mainpic/pic/rumo_welcome.png"));
        message.exec();
    }

    ui->label->setPixmap(QPixmap(":/mainpic/pic/main_bac_pic.jpg"));

    ui->textBrowser->setText("hello!");
    ui->textBrowser->append(username);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//message button
void MainWindow::on_pushButton_clicked()
{
   //询问服务器有无新消息
    recieve_message();

   if(messages_num == 0)
       QMessageBox::information(NULL, "message!", " no new message!",
                             QMessageBox::Yes, QMessageBox::Yes);
   else
    {
        //展开message界面
        message *m = new message(this);
        m->show();
    }
}

//about button
void MainWindow::on_pushButton_4_clicked()
{
   //关于，版本信息
    QMessageBox::about(NULL, "About", "Producer: 孤独的舞姬\t\n"
                                      "Version: 0.0.1\n");
}

//set button
void MainWindow::on_pushButton_5_clicked()
{
    //展开设置界面
    Set *s =new Set(this);
    s->show();
}
