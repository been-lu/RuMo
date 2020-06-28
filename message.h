#ifndef MESSAGE_H
#define MESSAGE_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class message;
}

class message : public QMainWindow
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = nullptr);
    ~message();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::message *ui;
};

#endif // MESSAGE_H
