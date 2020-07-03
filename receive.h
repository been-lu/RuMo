#ifndef RECEIVE_H
#define RECEIVE_H

#include <QWidget>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>

namespace Ui {
class receive;
}

class receive : public QWidget
{
    Q_OBJECT

public:
    explicit receive(QWidget *parent = nullptr);
    ~receive();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::receive *ui;
    QTableView *tableview;
};

#endif // RECEIVE_H
