#include "usermanagersetting.h"
#include "ui_usermanagersetting.h"
#include <QMessageBox>


UserManagerSetting::UserManagerSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManagerSetting)
{
    ui->setupUi(this);
}

UserManagerSetting::~UserManagerSetting()
{
    delete ui;
}

void UserManagerSetting::ShowUserManagerSetting(void)
{
    this->show();
}

void UserManagerSetting::on_pushButton_clicked()
{
    qDebug()<<"setting pass admin";
    QSqlQuery qry;
    QString value = Hash_key(ui->txtPwLv1->text());
    if(qry.exec("UPDATE Users SET Password =\'" + value+ "\' WHERE ID = 1"))
    QMessageBox::information(this, "Info", "Success");
}

void UserManagerSetting::on_pushButton_2_clicked()
{
    qDebug()<<"setting pass lv2";
    QSqlQuery qry;
    QString value = Hash_key(ui->txtPwLv2->text());
    if(qry.exec("UPDATE Users SET Password =\'" + value+ "\' WHERE ID = 2"))
    QMessageBox::information(this, "Info", "Success");
}

//void UserManagerSetting::on_pushButton_3_clicked()
//{
//    qDebug()<<"setting pass lv3";
//    QSqlQuery qry;
//    QString value = Hash_key(ui->txtPwLv3->text());
//    if(qry.exec("UPDATE Users SET Password =\'" + value+ "\' WHERE ID = 3"))
//    QMessageBox::information(this, "Info", "Success");
//}
