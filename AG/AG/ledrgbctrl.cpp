#include "ledrgbctrl.h"
#include "ui_ledrgbctrl.h"

LedRGBCtrl::LedRGBCtrl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LedRGBCtrl)
{
    ui->setupUi(this);
}

LedRGBCtrl::~LedRGBCtrl()
{
    delete ui;
}

void LedRGBCtrl::ShowLedRGBCtrl(void)
{
    this->show();
}

void LedRGBCtrl::on_btnRead_clicked()
{
    if(ui->rbOneOne->isChecked()){
        quint16 channel;
        ui->btnRead->setEnabled(false);
        int cnt;
        cnt =0;
        bool noise = true;
        quint16 channel_pre = 0;
        while ((cnt < 3)and (noise)){

            if(dmxrdm_rgb->askChannel_RGB_old()){
                channel_pre = dmxrdm_rgb->readChannl_RBB_old();
            }

            if(dmxrdm_rgb->askChannel_RGB_old()){
                channel_pre += dmxrdm_rgb->readChannl_RBB_old();
            }

            if(dmxrdm_rgb->askChannel_RGB_old()){
                channel = dmxrdm_rgb->readChannl_RBB_old();
            }

            if (channel_pre == 2*channel){
                noise = false;
            }else{
                channel_pre = 0;
            }
            cnt++;
        }

//        if(dmxrdm_rgb->askChannel_RGB_old())
//        {
//            channel = dmxrdm_rgb->readChannl_RBB_old();
//            channel = (channel - 1)*3 + 1;
//            ui->txt_DMX_ID->setText(QString::number(channel));
//        }
        if(!noise){
            channel = (channel - 1)*3 + 1;
            ui->txt_DMX_ID->setText(QString::number(channel));
        }
        else {
            QMessageBox::information(this, "ERROR", "Device not found!");
        }
        ui->btnRead->setEnabled(true);
    }else if (ui->rb_Loop->isChecked()){

    }
}

void LedRGBCtrl::on_btnWrite_clicked()
{
    if(ui->rbOneOne->isChecked()){
        //=================RGB one one==================
        quint16 channel = (quint16) ui->txt_DMX_ID->text().trimmed().toInt();
        if(channel == 1 || (channel - 1)%3 == 0)
        {
            channel = (channel - 1)/3 + 1;
            if(dmxrdm_rgb->writeChannel_RGB_old(channel))
            {
                QMessageBox::information(this, "Done", "Write channel done!");
            }
            else {
                QMessageBox::information(this, "ERROR", "Can't write channel");
            }
        }
        else {
            QMessageBox::information(this, "INFO", "DMX ID 1, 4, 7, 10,...!");
        }
        //===================================
     }
    else if(ui->rb_Loop->isChecked()){
        //=================RGB loop==================
        quint16 channel = (quint16) ui->txt_DMX_ID->text().trimmed().toInt();
        if(channel == 1 || (channel - 1)%3 == 0)
        {
            channel = (channel - 1)/3 + 1;
            dmxrdm_rgb->writeChannel_RGB_old_Loop(channel);
            QMessageBox::information(this, "Done", "Write channel done!");
        }
        else {
            QMessageBox::information(this, "INFO", "DMX ID 1, 4, 7, 10,...!");
        }
        //===================================
     }

}
