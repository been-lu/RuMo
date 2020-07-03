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
    bool loguser(QString name,QString password);
    bool signup(QString name,QString password);

private:
    QSqlQuery *query;
};
#endif // CONNECT_H

