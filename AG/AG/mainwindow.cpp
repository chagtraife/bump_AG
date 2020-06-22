/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "qtbaselib.h"
#include "settingsdialog.h"
#include "dmxconsole.h"
#include "deviceview.h"
#include "loadingdialog.h"
#include "testdialog.h"
#include "dmx_monitor.h"
#include "usermanagersetting.h"
#include <QTimer>

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QInputDialog>

#include "qtdmxlib.h"
#include "debug.h"


//#define Path_to_DB "C:/Users/thang/Desktop/bump_AG/V2.7/db/Database_AG.db"
//#define Path_to_DB "/db/Database_AG.db"

//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //! [0]

    StartTime.start();

    AdministratorTick = new QTimer(this);
    connect(AdministratorTick, SIGNAL(timeout()), this, SLOT(AdministratorTick_Handle()));
    AdministratorTick->start(1000);

    ui->setupUi(this);
//qDebug() << QSqlDatabase::drivers();
//    myDB = QSqlDatabase::addDatabase("QSQLITE");
//    auto path = QCoreApplication::applicationDirPath() + Path_to_DB;
//    qDebug()<<path;
//    myDB.setDatabaseName(path);
//    QFileInfo checkFile(path);

//    if (checkFile.isFile())
//    {
//        if (myDB.open()){
//            qDebug("connected to DB");
//        }else{
//            qDebug("can't connected to DB");
//        }

//    }else{
//        qDebug("no have file");
//    }

    connectDB();

    setUser(false);
//    setUser(true);
    console = new Console;


    console->setEnabled(false);
    //setCentralWidget(console);
    console->setVisible(false);

    dmxrdm = new DMXRDM;


    //! [1]
    serial = new QSerialPort(this);
    //! [1]
    settings = new SettingsDialog;
    dmx = new DMXconsole(this);
    devView = new DeviceView(this);
    loadingDialog = new LoadingDialog(this);
    testDialog = new TestDialog(this);
    DMXmonitor = new DMX_Monitor(this);
    userManagerSetting = new UserManagerSetting(this);

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    initActionsConnections();
    dmxrdm_rgb = new QT_RGB_DMX_LIB::DMXRDM();
    connect(dmxrdm_rgb,SIGNAL(writeData(const QByteArray)), this, SLOT(writeData_RGB(const QByteArray)));
    connect(dmxrdm_rgb, SIGNAL(writeDataBreak(QByteArray, bool)), this, SLOT(writeDataBreak_RGB(QByteArray, bool)));

    ui_Init();
    this->showDisconnected();
    IsUSARTAvailable = false;
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));


    //! [2]
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    //! [2]
    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
    //! [3]
    connect(dmxrdm, SIGNAL(showMessage(QString)), this, SLOT(_showDMXRDMMessage(QString)));
    connect(dmxrdm, SIGNAL(displayDMXAddr(quint16)), this, SLOT(_DisplayDMXAddress(quint16)));
    connect(dmxrdm, SIGNAL(displaySEQAddr(quint16)), this, SLOT(_DisplaySEQAddress(quint16)));
    connect(dmxrdm, SIGNAL(displayUID(QString)), this, SLOT(_DisplayUIDAddress(QString)));
    connect(dmxrdm, SIGNAL(SetUser(bool)), this, SLOT(setUser(bool)));
    //DMX console UI
    connect(ui->BtnTestMode, SIGNAL(clicked(bool)), this, SLOT(_setTestMode()));
    connect(ui->BtnDMXConsole, SIGNAL(clicked(bool)), dmx, SLOT(show()));
    connect(ui->BtnDeviceDiscovery, SIGNAL(clicked(bool)), devView, SLOT(show()));
    connect(dmx, SIGNAL(DMXTriggle()), this, SLOT(_DMXStream()));
    connect(ui->BtnUpdateFirmware, SIGNAL(clicked(bool)), this, SLOT(_BtnFirmwareUpdate_Clicked()));
    connect(dmxrdm, SIGNAL(sendBreak()), this, SLOT(writeBreak()));
    connect(dmxrdm, SIGNAL(sendFrame(QByteArray)), this, SLOT(writeData(QByteArray)));
    connect(dmxrdm, SIGNAL(setBaudrate(quint32)), this, SLOT(_setBaudrate(quint32)));
    connect(dmxrdm, SIGNAL(displayThreshold(QString,QString)), this, SLOT(_DisplayThreshold(QString,QString)));
    connect(dmxrdm, SIGNAL(ClosePort()), this, SLOT(closeSerialPort()));
    connect(devView, SIGNAL(WriteSEQ_ID()), this, SLOT(_writeSEQID()));

    connect(ui->rdBtn_Light, SIGNAL(clicked(bool)), this, SLOT(on_DeviceTypeSelection_clicked()));
    connect(ui->rdBtn_OthersDevices, SIGNAL(clicked(bool)), this, SLOT(on_DeviceTypeSelection_clicked()));
    connect(ui->rdBtn_LightRGBW, SIGNAL(clicked(bool)), this, SLOT(on_DeviceTypeSelection_clicked()));
    connect(this, SIGNAL(showLoadingDialog()), loadingDialog, SLOT(show()));
    connect(this, SIGNAL(hideLoadingDialog()), loadingDialog, SLOT(hide()));
}
//! [3]
void MainWindow::on_DeviceTypeSelection_clicked()
{
    if(ui->rdBtn_OthersDevices->isChecked())
    {
        ui->gboptionRGB->setVisible(false);
        ui->rdLoop->setVisible(false);
        ui->rdOneOne->setVisible(false);
        ui->BtnReadDMXID->setVisible(false);
        ui->TxtUID->setEnabled(true);
        ui->TxtMaxHeight->setEnabled(true);
        ui->TxtMinHeight->setEnabled(true);
        ui->BtnDeviceDiscovery->setEnabled(true);
        ui->BtnSearchDev->setEnabled(true);
        ui->BtnWriteUID->setEnabled(true);
        ui->BtnWrThreshold->setEnabled(true);
        ui->BtnUpdateFirmware->setEnabled(true);
        ui->BtnTestMode->setEnabled(true);
    }
    else
    {
        ui->gboptionRGB->setVisible(true);
        ui->rdLoop->setVisible(true);
        ui->rdOneOne->setVisible(true);
        ui->BtnReadDMXID->setVisible(true);
        ui->TxtUID->setEnabled(false);
        ui->TxtMaxHeight->setEnabled(false);
        ui->TxtMinHeight->setEnabled(false);
        ui->BtnDeviceDiscovery->setEnabled(false);
        ui->BtnSearchDev->setEnabled(false);
        ui->BtnWriteUID->setEnabled(false);
        ui->BtnWrThreshold->setEnabled(false);
        ui->BtnUpdateFirmware->setEnabled(false);
        ui->BtnTestMode->setEnabled(false);
    }

}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
    myDB.close();
}

void MainWindow::setUser(bool isAdministratorUser)
{
    if(isAdministratorUser)
    {
        ui->BtnWriteUID->setVisible(true);
        ui->BtnWrThreshold->setVisible(true);
        ui->lb_MaxHeight->setVisible(true);
        ui->lb_MinHeight->setVisible(true);
        ui->TxtMinHeight->setVisible(true);
        ui->TxtMaxHeight->setVisible(true);
    }
    else
    {
        ui->gboptionRGB->setVisible(false);
        ui->BtnReadDMXID->setVisible(false);
        ui->actionUser_Manager->setVisible(false);
        ui->BtnWriteUID->setVisible(false);
        ui->BtnWrThreshold->setVisible(false);
        ui->BtnUpdateFirmware->setVisible(false);
        ui->lb_MaxHeight->setVisible(false);
        ui->lb_MinHeight->setVisible(false);
        ui->TxtMinHeight->setVisible(false);
        ui->TxtMaxHeight->setVisible(false);
    }
}

void MainWindow::ui_Init(void)
{
    connect(ui->BtnWrDMXID, SIGNAL(clicked()), this, SLOT(_writeDMXID()));
}

void MainWindow::_searchDevice()
{
    //    dmxrdm->searchDevice();
    //    serial->sendBreak(1);
    //    writeData(dmxrdm->TxFrame);
}

void MainWindow::_writeUID()
{
    dmxrdm->writeUID("UID");
}

void MainWindow::_showDMXRDMMessage(const QString message)
{
    showStatusMessage(message);
}

void MainWindow::_DMXStream(void)
{
    this->writeBreak();
    this->writeData(dmx->DMXBuffer);
}

//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();

    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    serial->setReadBufferSize(100);


    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        //serial->setBreakEnabled(true);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
        IsUSARTAvailable = true;
        this->showConnected();

    } else {
        if(IsUSARTAvailable == true) QMessageBox::critical(this, tr("Error"), serial->errorString());
        IsUSARTAvailable = false;
        showStatusMessage(tr("Open error"));
        this->showDisconnected();
        this->settings->ShowSetting();
    }
}

void MainWindow::AdministratorTick_Handle(void)
{
    if(StartTime.elapsed() > 43200000) this->close();
}

//! [4]
void MainWindow::_setBaudrate(quint32 br)
{
    serial->setBaudRate(br);
}

//! [5]
void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
    this->showDisconnected();
    IsUSARTAvailable = false;
}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("DMX Device Manager"),
                       tr("AG Device Manager V4.0 \r\n"));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    if(serial->isOpen() == false)
    {
        IsUSARTAvailable = false;
        openSerialPort();
        dmxrdm->delay_ms(500);
//        serial->write(data);
    }
    else if(IsUSARTAvailable == true)
    {
        serial->write(data);
    }
}
//! [6]
void MainWindow::writeData_RGB(const QByteArray &data)
{
    if(serial->isOpen() == false)
    {
        IsUSARTAvailable = false;
        openSerialPort();
        dmxrdm_rgb->delay(500);
    }

    if(serial->isOpen())
    {
        /*
        QString _sprint = tr("data send. Size:\t%1. Data").arg(data.size());
        for(int i = 0; i < data.size(); i++)
        {
            _sprint += tr(" %1").arg((quint8)data[i]);
        }
        DEBUG(_sprint);
*/
        serial->sendBreak(1);
        //dmxrdm->delay(1);
        serial->write(data);
    }
}

void MainWindow::writeDataBreak_RGB(const QByteArray &data, bool _break)
{
    QString _sprint = tr("data send. Size:\t%1. Data").arg(data.size());

    if(serial->isOpen() == false)
    {
        IsUSARTAvailable = false;
        openSerialPort();
        dmxrdm_rgb->delay(500);
    }

    for(int i = 0; i < data.size(); i++)
    {
        _sprint += tr(" %1").arg((quint8)data[i]);
    }
    if(_break)
    {
        serial->sendBreak(1);
        dmxrdm_rgb->delay(1);
    }
    else {
    }
    serial->write(data);
}

void MainWindow::readData_RGB()
{
    const QByteArray data = serial->readAll();
    //m_console->putData(data);

    QString _sprint;
    _sprint = tr("Data rec. Size: %1, data: ").arg(data.size());
    for(int i = 0; i < data.size(); i++)
    {
        _sprint += tr("%1 ").arg((quint8)data[i]);
    }
    DEBUG(_sprint);
    dmxrdm_rgb->RDMRecHandler(data);
}


void MainWindow::writeBreak(void)
{
    if(IsUSARTAvailable == true && serial->isOpen() == true)
    {
        serial->sendBreak(1);
    }
}

//! [7]
void MainWindow::readData()
{
    if(serial->isOpen() == false)
    {
        IsUSARTAvailable = false;
        openSerialPort();
        dmxrdm->delay_ms(500);
        dmxrdm->RxFrame.clear();
        dmxrdm->RxFrame = serial->readAll();
    }

    if(IsUSARTAvailable == true)
    {
        QByteArray _dat;
        _dat.clear();
        _dat = serial->readAll();
        dmxrdm->RxFrame.clear();
        dmxrdm->RxFrame = _dat;
        DMXmonitor->ReadData(_dat);
        dmxrdm_rgb->RDMRecHandler(_dat);
    }
}
//! [7]


//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::BreakConditionError)
    {
        //Break signal detected
        dmxrdm->BreakDetected();
        DMXmonitor->ReadBreak();
        serial->clearError();
        //serial->clear();
    }

    if(error == QSerialPort::ResourceError)
    {
        IsUSARTAvailable = false;
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(ShowSetting()));
    connect(ui->actionClear, SIGNAL(triggered()), console, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionUser, SIGNAL(triggered()), this, SLOT(on_ActionUser()));
    connect(ui->actionDMX_monitor_2, SIGNAL(triggered()),DMXmonitor, SLOT(ShowDMXmonitor()));
    connect(ui->actionUser_Manager,SIGNAL(triggered()),userManagerSetting,SLOT(ShowUserManagerSetting()));
}

void MainWindow::on_ActionUser(void)
{
    bool ok;
    QString sPW, usernane, password,role;

    sPW = QInputDialog::getText(this, tr("Enter user password"),
                                tr("Password"), QLineEdit::Password,
                                "", &ok);
    sPW = Hash_key(sPW);

    if(ok)
    {


        if (!myDB.isOpen()){
            qDebug()<< "No connection to db";
            return;
        }
        QSqlQuery qry;
        if (qry.exec("SELECT Username, Password, Role FROM Users WHERE Password=\'"+sPW+"\'")){
            if (qry.next()){
                role = qry.value(2).toString();
                qDebug()<<role;
            }
        }

        // check level of sPW
        if (role == "admin" ) {
            qDebug()<<"admin level";
            setUser(false);
            ui->BtnWriteUID->setVisible(true);
            ui->BtnWrThreshold->setVisible(true);
            ui->BtnUpdateFirmware->setVisible(true);
            ui->lb_MaxHeight->setVisible(true);
            ui->lb_MinHeight->setVisible(true);
            ui->TxtMinHeight->setVisible(true);
            ui->TxtMaxHeight->setVisible(true);
            ui->actionUser_Manager->setVisible(true);
        }else if(role == "lv2"){
            qDebug()<<"lv2 level";
            setUser(false);
            ui->BtnUpdateFirmware->setVisible(true);
            ui->lb_MaxHeight->setVisible(true);
            ui->lb_MinHeight->setVisible(true);
            ui->TxtMinHeight->setVisible(true);
            ui->TxtMaxHeight->setVisible(true);
        }else if(role == "lv3"){
            qDebug()<<"lv3 level";
            setUser(false);
            ui->lb_MaxHeight->setVisible(true);
            ui->lb_MinHeight->setVisible(true);
            ui->TxtMinHeight->setVisible(true);
            ui->TxtMaxHeight->setVisible(true);
        }

//        QString key_crack = "BB05:OpenSesame";
//        dmxrdm->SetAdministratorUser(key_crack);
    }
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void MainWindow::showConnected(void)
{
    ui->lb_ConnectIcon->setPixmap(QPixmap(":/images/USB_Connected.png"));
}

void MainWindow::showDisconnected(void)
{
    ui->lb_ConnectIcon->setPixmap(QPixmap(":/images/USB_Disconnected.png"));
}

void MainWindow::_DisplayDMXAddress(quint16 DMXAdd)
{
    ui->TxtDMXID->setText(tr("%1").arg(DMXAdd));
}

void MainWindow::_DisplaySEQAddress(quint16 SEQAdd)
{
    ui->TxtSEQID->setText(tr("%1").arg(SEQAdd));
}

void MainWindow::_DisplayUIDAddress(QString UID)
{
    ui->TxtUID->setText(UID);
}

void MainWindow::_DisplayThreshold(QString Max, QString Min)
{
    ui->TxtMaxHeight->setText(Max);
    ui->TxtMinHeight->setText(Min);
}

void MainWindow::_BtnDMX_Clicked(void)
{

}

void MainWindow::_BtnFirmwareUpdate_Clicked(void)
{
    QString s;


    ui->BtnUpdateFirmware->setEnabled(false);
    this->showLoadingDialog();
    s = ui->TxtUID->text().trimmed();
    dmxrdm->SetUID(s);
    dmxrdm->Firmware_Update();
    this->hideLoadingDialog();
    ui->BtnUpdateFirmware->setEnabled(true);
}

void MainWindow::on_BtnSearchDev_clicked()
{
    QString s;
    ui->BtnSearchDev->setEnabled(false);
    this->showLoadingDialog();
    s = ui->TxtUID->text().trimmed();
    dmxrdm->SetUID(s);
    dmxrdm->GetDeviceInfo();
    this->hideLoadingDialog();
    ui->BtnSearchDev->setEnabled(true);
}

void MainWindow::on_BtnWrThreshold_clicked()
{
    QString s;
    quint8 Min, Max;
    ui->BtnWrThreshold->setEnabled(false);
    this->showLoadingDialog();
    s = ui->TxtUID->text().trimmed();
    dmxrdm->SetUID(s);
    Min = ui->TxtMinHeight->text().trimmed().toInt();
    Max = ui->TxtMaxHeight->text().trimmed().toInt();
    dmxrdm->SetThreshold(Max, Min);
    this->hideLoadingDialog();
    ui->BtnWrThreshold->setEnabled(true);
}

void MainWindow::on_BtnWriteUID_clicked()
{
    bool ok;
    QString sUID;
    QString s;
    ui->BtnWriteUID->setEnabled(false);

    s = ui->TxtUID->text().trimmed();
    dmxrdm->SetUID(s);
    if(dmxrdm->GetUID().isBroadcast())
    {
        QMessageBox::critical(this,"Error","UID must not be broadcast");
        ui->BtnWriteUID->setEnabled(true);
        this->hideLoadingDialog();
        return;
    }

    sUID = QInputDialog::getText(this, tr("Enter new UID"),
                                 tr("New UID:"), QLineEdit::Normal,
                                 dmxrdm->GetUID().toString(), &ok);
    if(!ok)
    {
        ui->BtnWriteUID->setEnabled(true);
        this->hideLoadingDialog();
        return;
    }
    UID newUID = UID(sUID);

    if(!newUID.isValid())
    {
        QMessageBox::critical(this,"Error","Wrong UID format");
        ui->BtnWriteUID->setEnabled(true);
        this->hideLoadingDialog();
        return;
    }

    if(newUID.isBroadcast())
    {
        QMessageBox::critical(this,"Error","UID must not be broadcast");
        ui->BtnWriteUID->setEnabled(true);
        this->hideLoadingDialog();
        return;
    }
    this->showLoadingDialog();
    dmxrdm->writeUID(newUID.toString());

    ui->BtnWriteUID->setEnabled(true);
    this->hideLoadingDialog();
}

void MainWindow::_setTestMode()
{
    QString s;
    ui->BtnTestMode->setEnabled(false);
    this->showLoadingDialog();
    s = ui->TxtUID->text().trimmed();
    dmxrdm->SetUID(s);
    if(!dmxrdm->isAdministratorUser())
    {
        dmxrdm->setTestMode(1);
    }
    else
    {
        testDialog->show();
    }
    this->hideLoadingDialog();
    ui->BtnTestMode->setEnabled(true);
}
void MainWindow::_writeSEQID()
{
        QByteArray addressing = dmxrdm->tr1Array();
    this->writeData(addressing);
    dmxrdm->delay_ms(500);

    //open gate
    for(int i = 1; i <= 170; i++)
    {
        addressing = dmxrdm->tr2Array();
        addressing.append(i);
        addressing.append((char)0);
        //write continously
        this->writeBreak();
        this->writeData(addressing);
        dmxrdm->delay_ms(8);
    }
    QMessageBox::information(this, "SEQ Addressing", "Done");
}

void MainWindow::_writeDMXID()
{
    QString s;
    uint16_t pArray[16] = {17,17,17,17,5,5,5,5,9,9,9,9,13,13,13,13};
    this->showLoadingDialog();
    ui->BtnWrDMXID->setEnabled(false);
    s = ui->TxtDMXID->text().trimmed();
    quint16 _DMXID = s.toUInt();
    for(int i = 0; i < 16;)
    {
        pArray[i] = _DMXID;
        //        pArray[i+1] = _DMXID;
        //        pArray[i+2] = _DMXID;
        //        pArray[i+3] = _DMXID;
        //        pArray[i+4] = _DMXID;
        //        pArray[i+5] = _DMXID;
        //        pArray[i+6] = _DMXID;
        //        pArray[i+7] = _DMXID;
        _DMXID += 4;
        i += 1;
    }
    if(ui->rdBtn_Light->isChecked())
    {
        if(ui->rdOneOne->isChecked()){
            //=================RGB one one==================
            quint16 channel = (quint16) ui->TxtDMXID->text().trimmed().toInt();
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
        else if(ui->rdOneOne->isChecked()){
            //=================RGB loop==================
            quint16 channel = (quint16) ui->TxtDMXID->text().trimmed().toInt();
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
    else if(ui->rdBtn_LightRGBW->isChecked())
    {
        if(ui->rdOneOne->isChecked()){
            //================RGBW one one===================
            quint16 channel = (quint16) ui->TxtDMXID->text().trimmed().toInt();
            if(channel == 1 || (channel - 1)%4 == 0)
            {
                channel = (channel - 1)/4 + 1;
                if(dmxrdm_rgb->writeChannel_RGB_old(channel))
                {
                    QMessageBox::information(this, "Done", "Write channel done!");
                }
                else {
                    QMessageBox::information(this, "ERROR", "Can't write channel");
                }
            }
            else {
                QMessageBox::information(this, "INFO", "DMX ID 1, 5, 9, 13, ...!");
            }
            //===================================
        }
        else if(ui->rdLoop->isChecked()){
            //================RGBW loop===================
            quint16 channel = (quint16) ui->TxtDMXID->text().trimmed().toInt();
            if(channel == 1 || (channel - 1)%4 == 0)
            {
                channel = (channel - 1)/4 + 1;
                dmxrdm_rgb->writeChannel_RGB_old_Loop(channel);
                QMessageBox::information(this, "Done", "Write channel done!");
            }
            else {
                QMessageBox::information(this, "INFO", "DMX ID 1, 5, 9, 13, ...!");
            }
            //===================================
        }
    }
    else
    {
        s = ui->TxtUID->text().trimmed();
        dmxrdm->SetUID(s);
        s = ui->TxtDMXID->text().trimmed();
        dmxrdm->writeDMXID(s.toInt());
    }
    this->hideLoadingDialog();
    ui->BtnWrDMXID->setEnabled(true);
}

void MainWindow::on_BtnDeviceDiscovery_clicked()
{

}


void MainWindow::on_BtnReadDMXID_clicked()
{
    if(ui->rdBtn_LightRGBW->isChecked()){
        if(ui->rdOneOne->isChecked()){
            quint16 channel;
            ui->BtnReadDMXID->setEnabled(false);
            if(dmxrdm_rgb->askChannel_RGB_old())
            {
                channel = dmxrdm_rgb->readChannl_RBB_old();
                channel = (channel - 1)*4 + 1;
                ui->TxtDMXID->setText(QString::number(channel));
            }
            else {
                QMessageBox::information(this, "ERROR", "Device not found!");
            }
            ui->BtnReadDMXID->setEnabled(true);
        }else if (ui->rdLoop->isChecked()){

        }
    }else if (ui->rdBtn_Light->isChecked()){
            if(ui->rdOneOne->isChecked()){
                quint16 channel;
                ui->BtnReadDMXID->setEnabled(false);
                if(dmxrdm_rgb->askChannel_RGB_old())
                {
                    channel = dmxrdm_rgb->readChannl_RBB_old();
                    channel = (channel - 1)*3 + 1;
                    ui->TxtDMXID->setText(QString::number(channel));
                }
                else {
                    QMessageBox::information(this, "ERROR", "Device not found!");
                }
                ui->BtnReadDMXID->setEnabled(true);
            }else if (ui->rdLoop->isChecked()){

            }
    }


}
