#include "dmxconsole.h"
#include "ui_dmxconsole.h"
#include <QDebug>

DMXconsole::DMXconsole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMXconsole)
{
    ui->setupUi(this);
//Btn DMX Streaming
    IsDMXRunning = false;
    ui->BtnStartStreaming->setStyleSheet("background-color:red");
    connect(ui->BtnStartStreaming, SIGNAL(clicked(bool)), this, SLOT(BtnDMXStreaming_Clicked()));
//
    UI_Init();
    DMXBuffer.resize(513);
//    DMXBuffer[0] = 0;
    for(quint16 i = 0; i < 513; i++)
    {
        DMXBuffer[i] = (int)0;
    }
    for(quint16 i = 0; i < 513; i++)
    {
        DMXBuffer_[i] = 0;
    }

    TimerTick = new QTimer(this);
    connect(TimerTick, SIGNAL(timeout()), this, SLOT(DMXTick()));
    TimerTick->start(100);
}


DMXconsole::~DMXconsole()
{
//    ui->BtnStartStreaming->setText("DMX Stream ON");
//    ui->BtnStartStreaming->setStyleSheet("background-color:red");
//    IsDMXRunning = false;


    TimerTick->stop();
    delete ui;
}


void DMXconsole::DMXTick(void)
{
    if (idx != ui->sl_virtualH->value()){
        idx = ui->sl_virtualH->value();

        ui->sl_value0->setValue(DMXBuffer_[idx + 1]);
        ui->sl_value1->setValue(DMXBuffer_[idx + 2]);
        ui->sl_value2->setValue(DMXBuffer_[idx + 3]);
        ui->sl_value3->setValue(DMXBuffer_[idx + 4]);
        ui->sl_value4->setValue(DMXBuffer_[idx + 5]);
        ui->sl_value5->setValue(DMXBuffer_[idx + 6]);
        ui->sl_value6->setValue(DMXBuffer_[idx + 7]);
        ui->sl_value7->setValue(DMXBuffer_[idx + 8]);
        ui->sl_value8->setValue(DMXBuffer_[idx + 9]);
        ui->sl_value9->setValue(DMXBuffer_[idx + 10]);
        ui->sl_value10->setValue(DMXBuffer_[idx + 11]);


        ui->grp_index0->setTitle(tr("%1").arg(idx+1));
        ui->grp_index1->setTitle(tr("%1").arg(idx+2));
        ui->grp_index2->setTitle(tr("%1").arg(idx+3));
        ui->grp_index3->setTitle(tr("%1").arg(idx+4));
        ui->grp_index4->setTitle(tr("%1").arg(idx+5));
        ui->grp_index5->setTitle(tr("%1").arg(idx+6));
        ui->grp_index6->setTitle(tr("%1").arg(idx+7));
        ui->grp_index7->setTitle(tr("%1").arg(idx+8));
        ui->grp_index8->setTitle(tr("%1").arg(idx+9));
        ui->grp_index9->setTitle(tr("%1").arg(idx+10));
        ui->grp_index10->setTitle(tr("%1").arg(idx+11));
    }
    if(ui->rd_None->isChecked()){
        ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value1->setText(tr("%1").arg(ui->sl_value1->value()));
        ui->lb_value2->setText(tr("%1").arg(ui->sl_value2->value()));
        ui->lb_value3->setText(tr("%1").arg(ui->sl_value3->value()));
        ui->lb_value4->setText(tr("%1").arg(ui->sl_value4->value()));
        ui->lb_value5->setText(tr("%1").arg(ui->sl_value5->value()));
        ui->lb_value6->setText(tr("%1").arg(ui->sl_value6->value()));
        ui->lb_value7->setText(tr("%1").arg(ui->sl_value7->value()));
        ui->lb_value8->setText(tr("%1").arg(ui->sl_value8->value()));
        ui->lb_value9->setText(tr("%1").arg(ui->sl_value9->value()));
        ui->lb_value10->setText(tr("%1").arg(ui->sl_value10->value()));


        DMXBuffer_[idx + 1] = ui->sl_value0->value();
        DMXBuffer_[idx + 2] = ui->sl_value1->value();
        DMXBuffer_[idx + 3] = ui->sl_value2->value();
        DMXBuffer_[idx + 4] = ui->sl_value3->value();
        DMXBuffer_[idx + 5] = ui->sl_value4->value();
        DMXBuffer_[idx + 6] = ui->sl_value5->value();
        DMXBuffer_[idx + 7] = ui->sl_value6->value();
        DMXBuffer_[idx + 8] = ui->sl_value7->value();
        DMXBuffer_[idx + 9] = ui->sl_value8->value();
        DMXBuffer_[idx + 10] = ui->sl_value9->value();
        DMXBuffer_[idx + 11] = ui->sl_value10->value();
    } else if(ui->rd_Even->isChecked()){
        if(idx%2 == 0){

            ui->lb_value1->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value3->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value5->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value7->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value9->setText(tr("%1").arg(ui->sl_value1->value()));

            ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value2->setText(tr("%1").arg(ui->sl_value2->value()));
            ui->lb_value4->setText(tr("%1").arg(ui->sl_value4->value()));
            ui->lb_value6->setText(tr("%1").arg(ui->sl_value6->value()));
            ui->lb_value8->setText(tr("%1").arg(ui->sl_value8->value()));
            ui->lb_value10->setText(tr("%1").arg(ui->sl_value10->value()));


            ui->sl_value3->setValue(ui->sl_value1->value());
            ui->sl_value5->setValue(ui->sl_value1->value());
            ui->sl_value7->setValue(ui->sl_value1->value());
            ui->sl_value9->setValue(ui->sl_value1->value());
            for(quint16 j = 2; j < 513; j=j+2)
            {
                DMXBuffer_[j] = ui->sl_value1->value();
            }
        }else {
            ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value2->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value4->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value6->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value8->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value10->setText(tr("%1").arg(ui->sl_value0->value()));

            ui->lb_value1->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value3->setText(tr("%1").arg(ui->sl_value3->value()));
            ui->lb_value5->setText(tr("%1").arg(ui->sl_value5->value()));
            ui->lb_value7->setText(tr("%1").arg(ui->sl_value7->value()));
            ui->lb_value9->setText(tr("%1").arg(ui->sl_value9->value()));



            ui->sl_value2->setValue(ui->sl_value0->value());
            ui->sl_value4->setValue(ui->sl_value0->value());
            ui->sl_value6->setValue(ui->sl_value0->value());
            ui->sl_value8->setValue(ui->sl_value0->value());
            ui->sl_value10->setValue(ui->sl_value0->value());
            for(quint16 j = 2; j < 513; j=j+2)
            {
                DMXBuffer_[j] = ui->sl_value0->value();
            }
        }




    }else if(ui->rd_Odd->isChecked()){
        if(idx%2 != 0){
            ui->lb_value1->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value3->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value5->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value7->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value9->setText(tr("%1").arg(ui->sl_value1->value()));

            ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value2->setText(tr("%1").arg(ui->sl_value2->value()));
            ui->lb_value4->setText(tr("%1").arg(ui->sl_value4->value()));
            ui->lb_value6->setText(tr("%1").arg(ui->sl_value6->value()));
            ui->lb_value8->setText(tr("%1").arg(ui->sl_value8->value()));
            ui->lb_value10->setText(tr("%1").arg(ui->sl_value10->value()));

            ui->sl_value3->setValue(ui->sl_value1->value());
            ui->sl_value5->setValue(ui->sl_value1->value());
            ui->sl_value7->setValue(ui->sl_value1->value());
            ui->sl_value9->setValue(ui->sl_value1->value());
            for(quint16 j = 1; j < 513; j=j+2)
            {
                DMXBuffer_[j] = ui->sl_value1->value();
            }
        }else {
            ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value2->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value4->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value6->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value8->setText(tr("%1").arg(ui->sl_value0->value()));
            ui->lb_value10->setText(tr("%1").arg(ui->sl_value0->value()));

            ui->lb_value1->setText(tr("%1").arg(ui->sl_value1->value()));
            ui->lb_value3->setText(tr("%1").arg(ui->sl_value3->value()));
            ui->lb_value5->setText(tr("%1").arg(ui->sl_value5->value()));
            ui->lb_value7->setText(tr("%1").arg(ui->sl_value7->value()));
            ui->lb_value9->setText(tr("%1").arg(ui->sl_value9->value()));

            ui->sl_value2->setValue(ui->sl_value0->value());
            ui->sl_value4->setValue(ui->sl_value0->value());
            ui->sl_value6->setValue(ui->sl_value0->value());
            ui->sl_value8->setValue(ui->sl_value0->value());
            ui->sl_value10->setValue(ui->sl_value0->value());
            for(quint16 j = 1; j < 513; j=j+2)
            {
                DMXBuffer_[j] = ui->sl_value0->value();
            }
        }
    } else if (ui->rd_Enhance->isChecked()) {


    } else if (ui->rd_SelectAll->isChecked()) {
        ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value1->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value2->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value3->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value4->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value5->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value6->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value7->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value8->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value9->setText(tr("%1").arg(ui->sl_value0->value()));
        ui->lb_value10->setText(tr("%1").arg(ui->sl_value0->value()));

        ui->sl_value1->setValue(ui->sl_value0->value());
        ui->sl_value2->setValue(ui->sl_value0->value());
        ui->sl_value3->setValue(ui->sl_value0->value());
        ui->sl_value4->setValue(ui->sl_value0->value());
        ui->sl_value5->setValue(ui->sl_value0->value());
        ui->sl_value6->setValue(ui->sl_value0->value());
        ui->sl_value7->setValue(ui->sl_value0->value());
        ui->sl_value8->setValue(ui->sl_value0->value());
        ui->sl_value9->setValue(ui->sl_value0->value());
        ui->sl_value10->setValue(ui->sl_value0->value());
        for(quint16 i = 1; i < 513; i++)
        {
            DMXBuffer_[i] = ui->sl_value0->value();
        }
    }



    if(IsDMXRunning == true)
    {
        for(quint16 k = 0; k < 513; k++)
        {
            DMXBuffer[k] = DMXBuffer_[k];
        }
        this->DMXTriggle();
    }
}

void DMXconsole::UI_Init(void)
{
//    connect(ui->chk_SelectAll, SIGNAL(clicked(bool)), this, SLOT(_chk_SelectAll_Changed()));

    ui->grp_index0->setTitle(tr("%1").arg(ui->sl_virtualH->value()+1));
    ui->grp_index1->setTitle(tr("%1").arg(ui->sl_virtualH->value()+2));
    ui->grp_index2->setTitle(tr("%1").arg(ui->sl_virtualH->value()+3));
    ui->grp_index3->setTitle(tr("%1").arg(ui->sl_virtualH->value()+4));
    ui->grp_index4->setTitle(tr("%1").arg(ui->sl_virtualH->value()+5));
    ui->grp_index5->setTitle(tr("%1").arg(ui->sl_virtualH->value()+6));
    ui->grp_index6->setTitle(tr("%1").arg(ui->sl_virtualH->value()+7));
    ui->grp_index7->setTitle(tr("%1").arg(ui->sl_virtualH->value()+8));
    ui->grp_index8->setTitle(tr("%1").arg(ui->sl_virtualH->value()+9));
    ui->grp_index9->setTitle(tr("%1").arg(ui->sl_virtualH->value()+10));
    ui->grp_index10->setTitle(tr("%1").arg(ui->sl_virtualH->value()+11));

}

quint16 DMXconsole::GetIndex(void)
{
    return ui->sl_virtualH->value();
}

void DMXconsole::_updateLb_value0(int val)
{
    qDebug()<<"hello";
////    if(ui->chk_SelectAll->isChecked() == true)
//    {
//        for(quint16 i = 1; i < 513; i++)
//        {
//            DMXBuffer[i] = ui->sl_value0->value();
//        }
////        DMXBuffer_ = DMXBuffer;
//        ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value1->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value2->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value3->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value4->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value5->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value6->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value7->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value8->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value9->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value10->setText(tr("%1").arg(ui->sl_value0->value()));

//        ui->sl_value1->setValue(ui->sl_value0->value());
//        ui->sl_value2->setValue(ui->sl_value0->value());
//        ui->sl_value3->setValue(ui->sl_value0->value());
//        ui->sl_value4->setValue(ui->sl_value0->value());
//        ui->sl_value5->setValue(ui->sl_value0->value());
//        ui->sl_value6->setValue(ui->sl_value0->value());
//        ui->sl_value7->setValue(ui->sl_value0->value());
//        ui->sl_value8->setValue(ui->sl_value0->value());
//        ui->sl_value9->setValue(ui->sl_value0->value());
//        ui->sl_value10->setValue(ui->sl_value0->value());
//    }
//    else
//    {
//        ui->lb_value0->setText(tr("%1").arg(ui->sl_value0->value()));
//        ui->lb_value1->setText(tr("%1").arg(ui->sl_value1->value()));
//        ui->lb_value2->setText(tr("%1").arg(ui->sl_value2->value()));
//        ui->lb_value3->setText(tr("%1").arg(ui->sl_value3->value()));
//        ui->lb_value4->setText(tr("%1").arg(ui->sl_value4->value()));
//        ui->lb_value5->setText(tr("%1").arg(ui->sl_value5->value()));
//        ui->lb_value6->setText(tr("%1").arg(ui->sl_value6->value()));
//        ui->lb_value7->setText(tr("%1").arg(ui->sl_value7->value()));
//        ui->lb_value8->setText(tr("%1").arg(ui->sl_value8->value()));
//        ui->lb_value9->setText(tr("%1").arg(ui->sl_value9->value()));
//        ui->lb_value10->setText(tr("%1").arg(ui->sl_value10->value()));
//        DMXBuffer_[idx + 1] = ui->sl_value0->value();
//        DMXBuffer_[idx + 2] = ui->sl_value1->value();
//        DMXBuffer_[idx + 3] = ui->sl_value2->value();
//        DMXBuffer_[idx + 4] = ui->sl_value3->value();
//        DMXBuffer_[idx + 5] = ui->sl_value4->value();
//        DMXBuffer_[idx + 6] = ui->sl_value5->value();
//        DMXBuffer_[idx + 7] = ui->sl_value6->value();
//        DMXBuffer_[idx + 8] = ui->sl_value7->value();
//        DMXBuffer_[idx + 9] = ui->sl_value8->value();
//        DMXBuffer_[idx + 10] = ui->sl_value9->value();
//        DMXBuffer_[idx + 11] = ui->sl_value10->value();
//    }
  }


void DMXconsole::_syncDMXBuffer(int index)
{
//    ui->sl_value0->setValue(DMXBuffer[index + 1]);
//    ui->sl_value1->setValue(DMXBuffer[index + 2]);
//    ui->sl_value2->setValue(DMXBuffer[index + 3]);
//    ui->sl_value3->setValue(DMXBuffer[index + 4]);
//    ui->sl_value4->setValue(DMXBuffer[index + 5]);
//    ui->sl_value5->setValue(DMXBuffer[index + 6]);
//    ui->sl_value6->setValue(DMXBuffer[index + 7]);
//    ui->sl_value7->setValue(DMXBuffer[index + 8]);
//    ui->sl_value8->setValue(DMXBuffer[index + 9]);
//    ui->sl_value9->setValue(DMXBuffer[index + 10]);
//    ui->sl_value10->setValue(DMXBuffer[index + 11]);
//    ui->grp_index0->setTitle(tr("%1").arg(ui->sl_virtualH->value()+1));
//    ui->grp_index1->setTitle(tr("%1").arg(ui->sl_virtualH->value()+2));
//    ui->grp_index2->setTitle(tr("%1").arg(ui->sl_virtualH->value()+3));
//    ui->grp_index3->setTitle(tr("%1").arg(ui->sl_virtualH->value()+4));
//    ui->grp_index4->setTitle(tr("%1").arg(ui->sl_virtualH->value()+5));
//    ui->grp_index5->setTitle(tr("%1").arg(ui->sl_virtualH->value()+6));
//    ui->grp_index6->setTitle(tr("%1").arg(ui->sl_virtualH->value()+7));
//    ui->grp_index7->setTitle(tr("%1").arg(ui->sl_virtualH->value()+8));
//    ui->grp_index8->setTitle(tr("%1").arg(ui->sl_virtualH->value()+9));
//    ui->grp_index9->setTitle(tr("%1").arg(ui->sl_virtualH->value()+10));
//    ui->grp_index10->setTitle(tr("%1").arg(ui->sl_virtualH->value()+11));
}

void DMXconsole::_chk_SelectAll_Changed(void)
{

}

void DMXconsole::FocusChanged(bool dir)
{

}

void DMXconsole::BtnDMXStreaming_Clicked(void)
{
    if(IsDMXRunning)
    {
        ui->BtnStartStreaming->setText("DMX Stream ON");
        ui->BtnStartStreaming->setStyleSheet("background-color:red");
        IsDMXRunning = false;
    }
    else
    {
        ui->BtnStartStreaming->setText("DMX Stream OFF");
        ui->BtnStartStreaming->setStyleSheet("background-color:lightgreen");
        IsDMXRunning = true;
    }
}

void DMXconsole::closeEvent (QCloseEvent *event){
    ui->BtnStartStreaming->setText("DMX Stream ON");
    ui->BtnStartStreaming->setStyleSheet("background-color:red");
    IsDMXRunning = false;
    emit signal_close();
}

int DMXconsole::idx = 0;
