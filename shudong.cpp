#include "shudong.h"
#include "ui_shudong.h"
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>

shudong::shudong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shudong)
{
    ui->setupUi(this);
}

shudong::~shudong()
{
    delete ui;
}

void shudong::on_pushButton_clicked()
{
    static QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);

    model->setQuery(QString("select * from text;"));

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("时间"));

    model->setHeaderData(1,Qt::Horizontal,QObject::tr("发送人"));

    model->setHeaderData(2,Qt::Horizontal,QObject::tr("信息"));

    ui->tableView->setModel(model);

    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,80);
}

void shudong::on_pushButton_3_clicked()
{
    this->close();
}
