#include "receive.h"
#include "ui_receive.h"
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>

receive::receive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::receive)
{
    ui->setupUi(this);
}

receive::~receive()
{
    delete ui;
}

void receive::on_pushButton_2_clicked()
{
    this->close();
}

void receive::on_pushButton_clicked()
{
    static QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);

    model->setQuery(QString("select * from comment;"));

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("时间"));

    model->setHeaderData(1,Qt::Horizontal,QObject::tr("收信人"));

    model->setHeaderData(2,Qt::Horizontal,QObject::tr("发信人"));

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("评论"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,80);
    ui->tableView->setColumnWidth(2,80);
}
