#ifndef SET_H
#define SET_H

#include <QMainWindow>

namespace Ui {
class Set;
}

class Set : public QMainWindow
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);
    ~Set();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Set *ui;
};

#endif // SET_H
