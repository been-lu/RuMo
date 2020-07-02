#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>
#include <qwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <qlabel.h>
#include <qstring.h>
#include <QTextstream>
#include <QFile>
#include <iostream>
#include<QTextEdit>
#include<QFileDialog>
#include<QDebug>
#include<QFile>
#include<QDateTime>
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton3->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->backbutton->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton4->setStyleSheet("background:transparent;border-width:0;border-style:outset");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_backbutton_clicked()
{
    this->hide();
}

void Dialog::on_pushButton3_clicked()
{

}
void Dialog::on_textEdit_copyAvailable(bool b)
{

}
void Dialog::on_textBrowser_anchorClicked(const QUrl &arg1)
{

}

void Dialog::on_pushButton4_clicked()
{
       QDateTime time = QDateTime::currentDateTime();
       QString str_1 = time.toString("yyyyMMdd");
       QString displayString;
       QFile file("C:/Users/Nobody/Documents/build-experiment_1-Desktop_Qt_5_14_2_MinGW_32_bit-Debug/str_1.txt");
       if(!file.open(QFile::ReadOnly|QFile::Text))
       {
          QMessageBox::warning(this,tr("ERRPOR"),tr("read file 1.txt error:%1")
                               .arg(file.errorString()));
          return;

       }
       QTextStream in(&file);
       QApplication::setOverrideCursor(Qt::WaitCursor);
       ui->textBrowser->setPlainText(in.readAll());
       QApplication::restoreOverrideCursor();
       //ui->textBrowser->clear();
       //ui->textBrowser->append(displayString);
}

