#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "message.h"
#include "ui_message.h"

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>

int messages;
void recieve_message()
{
   messages=1;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//跳转至message界面
void MainWindow::on_pushButton_clicked()
{
   //询问服务器有无新消息
    recieve_message();

   if(messages == 0)
       QMessageBox::information(NULL, "message!", " no new message!",
                             QMessageBox::Yes, QMessageBox::Yes);
   else
    {
        //this->hide();
        message *m = new message(this);
        m->show();

    }
}

void MainWindow::on_pushButton_4_clicked()
{
   //关于，版本信息
    QMessageBox::about(NULL, "About", "Producer: 孤独的舞姬\t\n"
                                      "Version: 0.0.1\n");
}
