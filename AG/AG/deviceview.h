#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include <QMainWindow>
#include <QList>
#include <QProgressBar>
#include "qtbaselib.h"
#include "qtdmxlib.h"
#include "loadingdialog.h"
#include "authen.h"
#include <QCloseEvent>
#include "qtdmxlib.h"
class QStandardItemModel;
class QLabel;
class DMXRDM;
class LoadingDialog;
class WindDMXConverter_Setting;

namespace Ui {
class DeviceView;
}

class DeviceView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeviceView(QWidget *parent = 0);
    ~DeviceView();

signals:
    void DiscoveryActived(UID startUID);
    void WriteSEQ_ID(void);

private slots:
    void on_tableView_Device_clicked(const QModelIndex &index);
    void closeEvent (QCloseEvent *event);
    void BeginDiscovery(void);

    void on_tableView_Device_entered(const QModelIndex &index);

    void DiscoveryAddDeviceList(QString FoundUID);
    void on_BtnReadParameters_clicked();

    void on_BtnAddNewDev_clicked();

    void on_BtnSelectAll_clicked();

    void on_BtnDeselectAll_clicked();

    void on_BtnWriteDMXAddress_clicked();

    void on_BtnSetTestMode_clicked();

    void on_BtnWriteLevel_clicked();

    void SaveFile(void);

    void LoadFile(void);

    void showErrorMessage(const QString &message);

    void setUser(void);
    void on_pushButton_clicked();

    void on_BtnReadPosition_clicked();

    void on_BtnWriteParameter_clicked();
    void on_BtnUpdateSubDriverFW_clicked();

    void close_loadingdialog(void);
    void _DisplayUIDAddress(QString UID);


private:
    enum UserCollumIndex
    {
        SEQAddr_CollumIndex = 0,
        UID_CollumIndex,
        DMXAddr_CollumIndex,
        DeviceType_CollumIndex,
        Sensor_CollumIndex,
        UserSetting_CollumIndex,
        FirmwareVersion_CollumIndex,
        NumberOfUserCollum
    };

    enum ManufacturerCollumIndex
    {
        MinLevel_CollumIndex = NumberOfUserCollum,
        MaxLevel_CollumIndex,
        Setting_Parameter,
        NumberOfCollum
    };

    const QString strCollumIndex[NumberOfCollum] =
    {
        "Position",
        "UID",
        "DMX Address",
        "Device type",
        "Sensor",
        "Setting",
        "Firmware Version",
        "Min Level",
        "Max Level",
        "EEPROM",
    };

    Ui::DeviceView *ui;
    QStandardItemModel *model;

    QList<DeviceInfo> lstOfDevice;
    quint16 Row_cnt;
    bool isRunning;
    void DeviceTable_Clear(void);
    void BeginSetRow(void);
    void SetNextRow(DeviceInfo devInfo, QColor color = Qt::white);
    void SetRow(DeviceInfo devInfo, quint16 row, QColor color = Qt::white);
    void SetCell(quint16 x, quint16 y, QString data, QColor color = Qt::white);
    void SetCell(quint16 x, quint16 y, quint32 data, QColor color = Qt::white);
    void UserSetting_Wind_DMX_Converter_Handle(DeviceInfo dev);
    QString GetCell(quint16 x, quint16 y);
    QString GetCell(QModelIndex index);
    DeviceInfo GetRow(quint16 y);
    DeviceInfo GetRow(QModelIndex index);
    QProgressBar *pg_percent;
    QLabel *lb_status;
    WindDMXConverter_Setting *WindDMXConverter_Form;
    LoadingDialog *loadingDialog;
    QString scanUID;

    bool status_running;
    void showStatusMessage(const QString &message);
};



#endif // DEVICEVIEW_H
