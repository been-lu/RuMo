#include "cloud.h"
#include "ui_cloud.h"
#include "connect.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMessageBox>

extern QString username;

cloud::cloud(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cloud)
{
    ui->setupUi(this);
    connect();
}

cloud::~cloud()
{
    delete ui;
}

void cloud::connect()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("88888888");
    db.setDatabaseName("user");
    if(db.open())
    {
        qDebug()<<"Database connected successfully!";
        return;
    }
    else
    {
        qDebug()<<"Database connected failed!";
        return;
    }
}

void cloud::on_pushButton_clicked()
{
    QString txt =ui->lineEdit->text();
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
    QString str =QString("insert into text(date,client,text) value('%1','%2','%3')").arg(localTime).arg(username).arg(txt);
    QSqlQuery query;
    query.exec(str);
    ui->lineEdit->clear();
    QApplication::setQuitOnLastWindowClosed(false);
    QMessageBox message(QMessageBox::NoIcon, "提示", "发布成功!");
    message.exec();
}

void cloud::on_pushButton_2_clicked()
{
    this->close();
}
