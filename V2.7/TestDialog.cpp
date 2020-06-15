#include "TestDialog.h"
#include "ui_TestDialog.h"
#include "qtbaselib.h"

extern DMXRDM *dmxrdm;
TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);
    connect(ui->Btn_Test1, SIGNAL(clicked(bool)), this, SLOT(on_Test1_Clicked()));
    connect(ui->Btn_Test2, SIGNAL(clicked(bool)), this, SLOT(on_Test2_Clicked()));
    connect(ui->Btn_Test3, SIGNAL(clicked(bool)), this, SLOT(on_Test3_Clicked()));
    connect(ui->Btn_Test4, SIGNAL(clicked(bool)), this, SLOT(on_Test4_Clicked()));
    step = 0;

    TimerTick = new QTimer(this);
    connect(TimerTick, SIGNAL(timeout()), this, SLOT(on_Timer_Tick()));
    TimerTick->start(1000);
    Timeout = 0;
}

void TestDialog::on_Test1_Clicked(void)
{
    step = 0;
    dmxrdm->setTestMode(2);
    Timeout = 30;
    ui->Btn_Test1->setEnabled(false);
    ui->Btn_Test2->setEnabled(false);
    ui->Btn_Test3->setEnabled(false);
    ui->Btn_Test4->setEnabled(false);
}

void TestDialog::on_Test2_Clicked(void)
{
    step = 1;
    dmxrdm->setTestMode(3);
    Timeout = 30;
    ui->Btn_Test1->setEnabled(false);
    ui->Btn_Test2->setEnabled(false);
    ui->Btn_Test3->setEnabled(false);
    ui->Btn_Test4->setEnabled(false);
}

void TestDialog::on_Test3_Clicked(void)
{
    step = 2;
    dmxrdm->setTestMode(4);
    Timeout = 20;
    ui->Btn_Test1->setEnabled(false);
    ui->Btn_Test2->setEnabled(false);
    ui->Btn_Test3->setEnabled(false);
    ui->Btn_Test4->setEnabled(false);
}

void TestDialog::on_Test4_Clicked(void)
{
    step = 3;
    dmxrdm->setTestMode(5);
    Timeout = 60;
    ui->Btn_Test1->setEnabled(false);
    ui->Btn_Test2->setEnabled(false);
    ui->Btn_Test3->setEnabled(false);
    ui->Btn_Test4->setEnabled(false);
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::on_Timer_Tick(void)
{
    if(Timeout > 0)
    {
        Timeout--;
        ui->lcd_TimeRemain->display(Timeout);
    }
    if(Timeout == 1)
    {
        ui->Btn_Test1->setEnabled(true);
        ui->Btn_Test2->setEnabled(true);
        ui->Btn_Test3->setEnabled(true);
        ui->Btn_Test4->setEnabled(true);
        dmxrdm->setTestMode(0);
    }
}
