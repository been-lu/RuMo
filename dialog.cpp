#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>

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
int shuzi=1;
void Dialog::on_pushButton3_clicked()//倒序输出
{
    shuzi+=1;
    int flag=0;
    QDir dir("D:/qt/QT_TRY/build-experiment_1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/123");
       if(!dir.exists())
       {
            QMessageBox::warning(this,"失败",NULL);
       }
       dir.setFilter(QDir::Files | QDir::NoSymLinks);
       QFileInfoList list = dir.entryInfoList();
       int file_count = list.count();
       if(file_count <= 0)
       {
           return;
       }
       QFileInfo fileInfo;
       for (int z = 0; z < list.size(); z++)
       {
           flag++;
           fileInfo = list.at(z);
           ve.append(qPrintable(QString("%1").arg(fileInfo.fileName())));
        }


            li=ve.end()-shuzi;
            if(shuzi>=flag+1)
                 {
                    QMessageBox::about(this,tr("提示"),tr("这之前的你没有留下足迹"));
                    shuzi=0;
                 }
           else
                { QString s=*li;
                 QFile file("D://qt//QT_TRY//build-experiment_1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug//123//"+s);
                       if(!file.open(QFile::ReadOnly|QFile::Text))
                       {
                          QMessageBox::warning(this,tr("ERRPOR"),tr("read file this.txt error:%1")
                                               .arg(file.errorString()));
                          return;

                        }
                       QTextStream in(&file);
                       QApplication::setOverrideCursor(Qt::WaitCursor);
                       ui->textBrowser->setPlainText(in.readAll());
                       QApplication::restoreOverrideCursor();
                 }

}


void Dialog::on_pushButton4_clicked()//读取指定文件夹的文件目录到容器，并取最近时间的一个输入
{
    QDir dir("D:/qt/QT_TRY/build-experiment_1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/123");
       if(!dir.exists())
       {
            QMessageBox::warning(this,"失败",NULL);
       }
       dir.setFilter(QDir::Files | QDir::NoSymLinks);
       QFileInfoList list = dir.entryInfoList();
       int file_count = list.count();
       if(file_count <= 0)
       {
           return;
       }

                 QFileInfo fileInfo;
                 for (int z = 0; z < list.size(); z++)
                 {
                     fileInfo = list.at(z);
                     ve.append(qPrintable(QString("%1").arg(fileInfo.fileName())));
                  }
                 foreach(QString str,ve)
                 {
                  qDebug()<<str;
                 }
                 li=ve.end()-1;
                 QString s=*li;
                 QFile file("D://qt//QT_TRY//build-experiment_1-Desktop_Qt_5_14_2_MinGW_64_bit-Debug//123//"+s);
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
}

