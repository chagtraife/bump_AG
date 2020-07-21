#include "console_enhance.h"
#include "ui_console_enhance.h"

Console_Enhance::Console_Enhance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Console_Enhance)
{
    ui->setupUi(this);
}

Console_Enhance::~Console_Enhance()
{
    delete ui;
}

void Console_Enhance::process_data(){

}

void Console_Enhance::on_btnOk_clicked()
{
    From = ui->txtFrom->text().trimmed().toInt();
    To = ui->txtTo->text().trimmed().toInt();
    offset = ui->txtOffset->text().trimmed().toInt();
    this->hide();
    emit into_enhance();
}

void Console_Enhance::closeEvent (QCloseEvent *event){
    qDebug("Console_EnhancecloseEvent");
    emit turn_off_config_enhance();
}
