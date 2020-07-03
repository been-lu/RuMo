#include "widget.h"
#include "ui_widget.h"
#include <qapplication.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qapplication.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <qlabel.h>
#include <qstring.h>
#include <qtextstream.h>
#include <qfile.h>
#include <iostream>
#include<QTextEdit>
#include<QFileDialog>
#include<QDebug>
#include<QFile>
#include<QDateTime>
#include<dialog.h>
Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton_2->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->backbutton_2->setStyleSheet("background:transparent;border-width:0;border-style:outset");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()//浏览过往树洞，弹出dialog.ui界面//旧刻
{
    Dialog *dialog=new Dialog(this);
    dialog->setModal(true);
    dialog->show();//弹出新界面

}

void Widget::on_pushButton_2_clicked()//点击后保存树洞内容至本地//作石
{       QDir d;
        d.mkpath("D:/qt/QT_TRY/build-experiment_1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/123");//创建一个文件夹，合并时只需改动（“”）内的路径，建议运行程序时就建一个，这里也行。头文件《QDir》
         QString str = ui->textEdit->toPlainText();
         qDebug()<<str;
         QDateTime time = QDateTime::currentDateTime();
         QString str_1 = time.toString("yyyyMMddhhmmss");
         QString str_2 = time.toString("yyyy-MM-dd hh:mm:ss");
     if(str==NULL)
         {
             QMessageBox::about(this,tr("提示"),tr("内容为空"));
         }
     else
         {
         QFile data("D:/qt/QT_TRY/build-experiment_1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/123/"+str_1+".txt");    //保存到指定路径
         QString s=str+"\n"+str_2;
         if(data.open(QFile::WriteOnly | QFile::Truncate))
         {
             QTextStream out(&data);
             out<<s;
             QMessageBox::about(this,tr("提示"),tr("成功写入"));
         }
         ui->textEdit->clear();
         data.close();
         //被点击时创建一个新的txt文件并将文本框内容存入（没有同日期的文件时），如果有则覆盖该文件内容

         }
}

void Widget::on_backbutton_2_clicked()//返回主界面，合并的时候写
{
    this->hide();
}


