#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cloud.h"
#include "ui_cloud.h"
#include "shudong.h"
#include "comment.h"
#include "receive.h"
#include "widget.h"

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>

#include "connect.h"


extern QString username;


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
    ui->pushButton_5->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton_6->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->textBrowser->setText("欢迎!");
    ui->textBrowser->append(username);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//about button
void MainWindow::on_pushButton_4_clicked()
{
   //关于，版本信息
    QApplication::setQuitOnLastWindowClosed(false);
    QMessageBox message(QMessageBox::NoIcon, "关于", "Producer: 孤独的舞姬\t\n"
                                                      "Version: 0.0.1\n");
    message.setIconPixmap(QPixmap(":/mainpic/pic/rumo_welcome.png"));
    message.exec();
}


//local//刻沙
void MainWindow::on_pushButton_2_clicked()
{
    Widget *v= new Widget(this);
    v->show();
}
//shudong听风//
void MainWindow::on_pushButton_clicked()
{
    //shudong界面
    shudong *k =new shudong(this);
    k->show();
}
//cloud//随云
void MainWindow::on_pushButton_3_clicked()
{
    //cloud界面
    cloud *q =new cloud(this);
    q->show();
}
//评论
void MainWindow::on_pushButton_5_clicked()
{
    //comment界面
    comment *l =new comment(this);
    l->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    //receive界面
    receive *g =new receive(this);
    g->show();
}
