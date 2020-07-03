#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <qfiledialog.h>
#include<QDir>
#include<QList>
#include<widget.h>
#include<ui_widget.h>
#include<QDebug>
#include<QVector>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_backbutton_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();



private:
    Ui::Dialog *ui;
    QVector<QString> ve;
    QVector<QString>::iterator li;//容器
};

#endif // DIALOG_H
