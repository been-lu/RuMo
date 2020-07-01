#include "mainwindow.h"
#include "ui_mainwindow.h"



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

    //载入背景图片
    ui->label->setPixmap(QPixmap(":/mainpic/pic/main_bac_pic.jpg"));

    ui->textBrowser->setText("欢迎!");
    ui->textBrowser->append(username);   

    //使无边界且透明
    {
    ui->textBrowser->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton_2->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton_3->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton_4->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton_5->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton_6->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


//about button
void MainWindow::on_pushButton_4_clicked()
{
   //关于，版本信息

    QMessageBox message(QMessageBox::NoIcon, "关于", "Producer: 孤独的舞姬\t\n"
                                                      "Version: 0.0.1\n");
    message.setIconPixmap(QPixmap(":/mainpic/pic/rumo_welcome.png"));
    message.exec();
}

//local//刻沙



//cloud//说云



//听风//



//赠人



//悦己


