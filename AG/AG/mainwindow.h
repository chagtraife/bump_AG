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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>

#include "QDebug"
//#include "QtSql"
//#include "QFileInfo"
#include "authen.h"
#include <string>
using namespace std;
#include <QTime>
#include "qtdmxlib.h"

extern QT_RGB_DMX_LIB::DMXRDM *dmxrdm_rgb;

QT_BEGIN_NAMESPACE

class QLabel;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class DMXRDM;
class Console;
class SettingsDialog;
class DMXconsole;
class DeviceView;
class LoadingDialog;
class TestDialog;
class DMX_Monitor;
class UserManagerSetting;

class MainWindow : public QMainWindow, public Authen
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeBreak(void);
    void writeData(const QByteArray &data);
    void writeData_RGB(const QByteArray &data);
    void writeDataBreak_RGB(const QByteArray &data, bool _break);
    void readData_RGB();
    void readData();
    void _setBaudrate(quint32 br);
    void handleError(QSerialPort::SerialPortError error);
    void AdministratorTick_Handle(void);
    //DMX RDM signal interface
    void _searchDevice();
    void _writeDMXID();
    void _writeSEQID();
    void _writeUID();
    void _setTestMode();
    void _showDMXRDMMessage(const QString message);
    void _DisplayDMXAddress(quint16 DMXAdd);
    void _DisplayUIDAddress(QString UID);
    void _DisplaySEQAddress(quint16 SEQAdd);
    void _DisplayThreshold(QString Max, QString Min);
    void _BtnDMX_Clicked(void);
    void _BtnFirmwareUpdate_Clicked(void);
    void _DMXStream(void);

    void on_BtnSearchDev_clicked();


    void on_BtnWrThreshold_clicked();

    void on_BtnWriteUID_clicked();

    void on_BtnDeviceDiscovery_clicked();

    void on_ActionUser(void);
    void setUser(bool isAdministratorUser);


    void on_DeviceTypeSelection_clicked();
private:
    void initActionsConnections();
    void ui_Init(void);
    void showStatusMessage(const QString &message);
    void showConnected(void);
    void showDisconnected(void);

signals:
    void showLoadingDialog(void);
    void hideLoadingDialog(void);

private:
    Ui::MainWindow *ui;
    QLabel *status;
    Console *console;
    SettingsDialog *settings;
    QSerialPort *serial;
    QTimer *timerTick;
    DMXconsole *dmx;
    DeviceView *devView;
    LoadingDialog *loadingDialog;
    TestDialog *testDialog;
    DMX_Monitor *DMXmonitor;
    UserManagerSetting *userManagerSetting;
    bool IsUSARTAvailable;

    QTime StartTime;
    QTimer *AdministratorTick;

//    QSqlDatabase myDB;
};

#endif // MAINWINDOW_H
