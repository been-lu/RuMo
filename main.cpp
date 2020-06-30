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
    sign s;
    s.show();
    return a.exec();
}

