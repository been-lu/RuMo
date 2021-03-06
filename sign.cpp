#include "sign.h"
#include "ui_sign.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connect.h"
#include "QMessageBox"

QString username;
QString password;


sign::sign(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
    {
        ui->label_3->setPixmap(QPixmap(":/mainpic/pic/sign_bac.jpg"));
        ui->lineEdit_2->setAlignment(Qt::AlignHCenter);
        ui->lineEdit_2->setPlaceholderText("请输入密码");
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
        ui->lineEdit->setAlignment(Qt::AlignHCenter);
        ui->lineEdit->setPlaceholderText("请输入用户名");
        connectMYSQL();
    }
}

sign::~sign()
{
    delete ui;
}

//登录检测
bool check_log(QString name, QString password)
{
    MySql *mysql=new MySql();
    bool ret=mysql->loguser(name,password);
    return ret;
}

//注册检测
bool check_sign(QString name, QString password)
{
    MySql *mysql=new MySql();
    bool ret=mysql->signup(name,password);
    return ret;

}
//注册
void sign::on_pushButton_clicked()
{
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();

    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::about(NULL,"message","用户名不能为空");
        return;
    }
    if(ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::about(NULL,"message","密码不能为空！");
        return;
    }
    if(check_sign(username,password)==1)
    {
        QMessageBox::about(NULL,"message","注册成功，请重新登录");
        ui->lineEdit_2->clear();
    }
    else
        QMessageBox::about(NULL,"message!","用户名已存在！");

}
//登录
void sign::on_pushButton_2_clicked()
{
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    if(check_log(username,password))
    {
       QMessageBox::about(NULL,"message","啊啊啊！\n奇怪的东西来了！");
       this->close();
       MainWindow *w=new MainWindow (this);
       w->show();
    }
    else
    {
        QMessageBox::about(NULL,"message!","errror");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
}

void sign::connectMYSQL()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("88888888");
    db.setDatabaseName("user");
    if(db.open())
    {
        qDebug()<<"Database connected successfully!";
        return;
    }
    else
    {
        qDebug()<<"Database connected failed!";
        return;
    }
}
