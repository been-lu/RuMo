#ifndef SHUDONG_H
#define SHUDONG_H

#include <QWidget>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
namespace Ui {
class shudong;
}

class shudong : public QWidget
{
    Q_OBJECT

public:
    explicit shudong(QWidget *parent = nullptr);
    ~shudong();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::shudong *ui;
    QTableView *tableview;
};

#endif // SHUDONG_H
