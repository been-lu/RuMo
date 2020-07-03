#include "connect.h"

MySql::MySql()
{

}


//登录
bool MySql::loguser(QString name, QString password)
{
    QString str=QString("select * from user where name='%1' and password='%2'").arg(name).arg(password);
    query=new QSqlQuery;
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record==0)
        return false;
    return true;
}

//注册
bool MySql::signup(QString name,QString password)
{
    QString str=QString("select * from user where name='%1").arg(name);
    query=new QSqlQuery;
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record!=0)
        return false;
    str=QString("insert into user value('%1','%2')").arg(name).arg(password);
    bool ret=query->exec(str);
    return ret;
}
