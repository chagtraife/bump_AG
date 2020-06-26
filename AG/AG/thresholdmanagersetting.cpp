#include "thresholdmanagersetting.h"
#include "ui_thresholdmanagersetting.h"
#include <QMessageBox>


ThresholdManagerSetting::ThresholdManagerSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThresholdManagerSetting)
{
    ui->setupUi(this);
}

ThresholdManagerSetting::~ThresholdManagerSetting()
{
    delete ui;
}

void ThresholdManagerSetting::ShowThresholdManagerSetting(void)
{
    this->show();
}

void ThresholdManagerSetting::on_btnSetMin_clicked()
{
    qDebug()<<"setting threshold Min";
    QSqlQuery qry_;
    QString value = Hash_key(ui->txt_Min->text().trimmed());
//    QString value = "40";
//    QString value = QString::number(ui->txt_Min->text().trimmed().toInt());
    if(qry_.exec("UPDATE Users SET Threshold_Min = " + value+ " WHERE ID = 2"))
    QMessageBox::information(this, "Info", "Success");
}

void ThresholdManagerSetting::on_btnSetMax_clicked()
{
    qDebug()<<"setting threshold Max";
    QSqlQuery qry_;
    QString value = Hash_key(ui->txt_Max->text().trimmed());
//    QString value = "40";
//    QString value = QString::number(ui->txt_Max->text().trimmed().toInt());
    if(qry_.exec("UPDATE Users SET Threshold_Max = " + value+ " WHERE ID = 2"))
    QMessageBox::information(this, "Info", "Success");
}
