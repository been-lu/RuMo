#include "set.h"
#include "ui_set.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

Set::Set(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Set)
{
    ui->setupUi(this);
}

Set::~Set()
{
    delete ui;
}

void Set::on_pushButton_clicked()
{
    //关闭本界面
    this->close();
}
