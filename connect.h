#ifndef CONNECT_H
#define CONNECT_H
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QApplication>

class MySql
{
public:
    MySql();
    void initsql();
    void createtable();
    bool loguser(QString name,QString passward);
    bool signup(QString name,QString passward);

private:
    QSqlQuery *query;
};
#endif // CONNECT_H

