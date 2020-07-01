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

    ui->textBrowser->setText("欢迎!");
    ui->textBrowser->append(username);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//view button
void MainWindow::on_pushButton_clicked()
{

        //展开message界面
        message *m = new message(this);
        m->show();
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
