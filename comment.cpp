#include "comment.h"
#include "ui_comment.h"
#include "connect.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMessageBox>

extern QString username;

comment::comment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::comment)
{
    ui->setupUi(this);
}

comment::~comment()
{
    delete ui;
}

void comment::on_pushButton_clicked()
{
    this->close();
}

void comment::on_pushButton_2_clicked()
{
    QString receive =ui->lineEdit->text();
    QString txt =ui->lineEdit_2->text();
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
    QString str =QString("insert into comment value('%1','%2','%3','%4')").arg(localTime).arg(receive).arg(username).arg(txt);
    QSqlQuery query;
    query.exec(str);
    QApplication::setQuitOnLastWindowClosed(false);
    QMessageBox message(QMessageBox::NoIcon, "提示", "发布成功!");
    message.exec();
}
