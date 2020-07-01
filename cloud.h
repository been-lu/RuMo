#ifndef CLOUD_H
#define CLOUD_H

#include <QWidget>

namespace Ui {
class cloud;
}

class cloud : public QWidget
{
    Q_OBJECT

public:
    explicit cloud(QWidget *parent = nullptr);
    ~cloud();
    void connect();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::cloud *ui;
};

#endif // CLOUD_H
