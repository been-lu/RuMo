#include "mainwindow.h"
#include "sign.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QApplication>

//public
int messages_num;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //进入登陆界面
//    sign s;
//    s.show();

    //进入主界面
    MainWindow w;
    w.show();
    return a.exec();
}

