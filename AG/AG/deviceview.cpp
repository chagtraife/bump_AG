#include "deviceview.h"
#include "ui_deviceview.h"
#include "WindDMXConverter_Setting.h"

#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QLabel>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QVariant>
#include <QtCore/QtGlobal>
#include <stdint.h>
#include <QObject>
#include <QCloseEvent>

DeviceView::DeviceView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeviceView)
{
    status_running = true;
    model = new QStandardItemModel(0,0,this);
    loadingDialog = new LoadingDialog(this);
    connect(loadingDialog,SIGNAL(signal_close_loadingdialog()),this, SLOT(close_loadingdialog()));

    WindDMXConverter_Form = new WindDMXConverter_Setting(this);
    ui->setupUi(this);
    ui->BtnReadPosition->setVisible(false);
    this->setUser();
    connect(ui->actionLoad, SIGNAL(triggered(bool)), this, SLOT(LoadFile()));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(SaveFile()));
    connect(ui->actionRefresh_Position, SIGNAL(triggered(bool)), this, SLOT(on_BtnReadPosition_clicked()));
    connect(ui->actionUpdate_Sub_Driver_Firmware, SIGNAL(triggered(bool)), this, SLOT(on_BtnUpdateSubDriverFW_clicked()));
    connect(ui->BtnBeginDiscovery, SIGNAL(clicked(bool)), this, SLOT(BeginDiscovery()));
    connect(this,SIGNAL(aboutToQuit()),this,SLOT(quitdevView()));

    connect(dmxrdm, SIGNAL(displayUID(QString)), this, SLOT(_DisplayUIDAddress(QString)));

    connect(dmxrdm, SIGNAL(showMessage(QString)), this, SLOT(showErrorMessage(QString)));
//    connect(dmxrdm, SIGNAL(SetUser(bool)), this, SLOT(setUser(bool)));


    DeviceTable_Clear();
    pg_percent = new QProgressBar();
    lb_status = new QLabel();
    ui->statusbar->addWidget(lb_status);
    ui->statusbar->addWidget(pg_percent);
    pg_percent->setMaximum(100);
    pg_percent->setMinimum(0);
    pg_percent->setVisible(false);


    connect(dmxrdm, SIGNAL(DiscFoundDevice(QString)), this, SLOT(DiscoveryAddDeviceList(QString)));
    ui->tableView_Device->setModel(model);
    Row_cnt = 0;
    isRunning = false;
}

void DeviceView::DiscoveryAddDeviceList(QString FoundUID)
{
    DeviceInfo FoundDevice;
    FoundDevice.UID = UID(FoundUID);
    qDebug()<<FoundDevice.UID.toString();
    FoundDevice.DMXAddr = 0;
//    FoundDevice.SensorValue = 0;
    lstOfDevice<<FoundDevice;
    SetNextRow(FoundDevice);
}

DeviceView::~DeviceView()
{
    delete ui;
}


void DeviceView::SetCell(quint16 x, quint16 y, QString data, QColor color)
{
    QStandardItem *row = new QStandardItem(data);
    //row->setForeground(color);
    row->setBackground(color);
    model->setItem(y,x,row);
}

void DeviceView::SetCell(quint16 x, quint16 y, quint32 data, QColor color)
{
    QStandardItem  *row = new QStandardItem ();//QString::number(data,10));
    QVariant t(data);
    row->setData(t, Qt::EditRole);
    //row->setForeground(color);
    row->setBackground(color);
    model->setItem(y,x,row);
}

QString DeviceView::GetCell(quint16 x, quint16 y)
{
    QStandardItem *row;
    row = model->item(y,x);
    return row->text();
}

QString DeviceView::GetCell(QModelIndex index)
{
    QStandardItem *row;
    row = model->item(index.row(), index.column());
    return row->text();
}

DeviceInfo DeviceView::GetRow(quint16 y)
{
    DeviceInfo readDev = DeviceInfo();
    readDev.UID = UID(GetCell(UID_CollumIndex, y));
    readDev.DMXAddr = GetCell(DMXAddr_CollumIndex, y).toUInt();
//    readDev.SensorValue = GetCell(Sensor_CollumIndex, y).toUInt();
    readDev.SEQAddr = GetCell(SEQAddr_CollumIndex, y).toUInt();
    readDev.strDeviceType = GetCell(DeviceType_CollumIndex, y);
    readDev.strFWVersion = GetCell(FirmwareVersion_CollumIndex, y);


    if(Authen::user_lv == 1)
    {
        readDev.MinLevel = GetCell(MinLevel_CollumIndex, y).toUInt();
        readDev.MaxLevel = GetCell(MaxLevel_CollumIndex, y).toInt();
        readDev.strEEprom = GetCell(Setting_Parameter, y);
    }
    else if ((Authen::user_lv == 2) or (Authen::user_lv == 3))
    {
        readDev.MinLevel = GetCell(MinLevel_CollumIndex, y).toUInt();
        readDev.MaxLevel = GetCell(MaxLevel_CollumIndex, y).toInt();
    }

//    if(dmxrdm->isAdministratorUser())
//    {
//        readDev.MinLevel = GetCell(MinLevel_CollumIndex, y).toUInt();
//        readDev.MaxLevel = GetCell(MaxLevel_CollumIndex, y).toInt();
//        readDev.strEEprom = GetCell(Setting_Parameter, y);
//    }
    return readDev;
}

DeviceInfo DeviceView::GetRow(QModelIndex index)
{
    DeviceInfo readDev = DeviceInfo();
    readDev.UID = UID(GetCell(UID_CollumIndex, index.row()));
    readDev.DMXAddr = GetCell(DMXAddr_CollumIndex, index.row()).toUInt();
//    readDev.SensorValue = GetCell(Sensor_CollumIndex, index.row()).toUInt();
    readDev.SEQAddr = GetCell(SEQAddr_CollumIndex, index.row()).toUInt();
    readDev.strDeviceType = GetCell(DeviceType_CollumIndex, index.row());
    readDev.strFWVersion = GetCell(FirmwareVersion_CollumIndex, index.row());

    if(Authen::user_lv == 1)
    {
        readDev.MinLevel = GetCell(MinLevel_CollumIndex, index.row()).toUInt();
        readDev.MaxLevel = GetCell(MaxLevel_CollumIndex, index.row()).toInt();
        readDev.strEEprom = GetCell(Setting_Parameter, index.row());
    }
    else if ((Authen::user_lv == 2) or (Authen::user_lv == 3))
    {
        readDev.MinLevel = GetCell(MinLevel_CollumIndex, index.row()).toUInt();
        readDev.MaxLevel = GetCell(MaxLevel_CollumIndex, index.row()).toInt();
    }

//    if(dmxrdm->isAdministratorUser())
//    {
//        readDev.MinLevel = GetCell(MinLevel_CollumIndex, index.row()).toUInt();
//        readDev.MaxLevel = GetCell(MaxLevel_CollumIndex, index.row()).toInt();
//        readDev.strEEprom = GetCell(Setting_Parameter, index.row());
//    }
    return readDev;
}

void DeviceView::showStatusMessage(const QString &message)
{
    lb_status->setText(message);
    if(!this->isActiveWindow())
    {
        dmxrdm->StopAll();
    }
}

void DeviceView::showErrorMessage(const QString &message)
{
    lb_status->setText(message);
    if(!this->isActiveWindow() && !this->loadingDialog->isActiveWindow() && isRunning)
    {
        dmxrdm->StopAll();
        lb_status->setText("Interrupted");
        isRunning = false;
    }
}

void DeviceView::setUser(void)
{
//    Authen::user_lv;
    if(Authen::user_lv == 1)
    {
        ui->BtnWriteLevel->setVisible(true);
        ui->BtnWriteParameter->setVisible(true);
    }
    else if ((Authen::user_lv == 2) or (Authen::user_lv == 3))
    {
        ui->BtnWriteLevel->setVisible(true);
        ui->BtnWriteParameter->setVisible(false);
    }
    else if (Authen::user_lv == 4)
    {
        ui->BtnWriteLevel->setVisible(false);
        ui->BtnWriteParameter->setVisible(false);
    }

    DeviceTable_Clear();
    lstOfDevice.clear();
    BeginSetRow();
}

void DeviceView::on_tableView_Device_clicked(const QModelIndex &index)
{
    if(index.column() == UserSetting_CollumIndex)
    {
        if(lstOfDevice.size() > 0)
        {
            DeviceInfo _dev = GetRow(index.row());
            //if(_dev.strDeviceType == _dev.DEVICE_NAME[DeviceInfo::WIND_DMX_CONVERTER])
            {
                UserSetting_Wind_DMX_Converter_Handle(_dev);
            }

        }
    }
    //qDebug()<<"chose" << index.column() << index.row();// << GetCell(index.column(), index.row());

}

void DeviceView::UserSetting_Wind_DMX_Converter_Handle(DeviceInfo dev)
{
    WindDMXConverter_Form->showDialog(dev);
}

void DeviceView::BeginSetRow(void)
{
    this->Row_cnt = 0;
}

void DeviceView::DeviceTable_Clear(void)
{
    model->clear();
    for(int i = 0; i < NumberOfUserCollum; i++)
    {
        model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndex[i]));
    }

    if(Authen::user_lv == 1)
    {
        for(int i = NumberOfUserCollum; i < NumberOfCollum; i++)
        {
            model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndex[i]));
        }
    }
    else if ((Authen::user_lv == 2) or (Authen::user_lv == 3))
    {
        for(int i = NumberOfUserCollum; i <= MaxLevel_CollumIndex; i++)
        {
            model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndex[i]));
        }
    }
//    if(dmxrdm->isAdministratorUser())
//    {
//        for(int i = NumberOfUserCollum; i < NumberOfCollum; i++)
//        {
//            model->setHorizontalHeaderItem(i, new QStandardItem(strCollumIndex[i]));
//        }
//    }
}

void DeviceView::SetNextRow(DeviceInfo devInfo, QColor color)
{
    qDebug()<<devInfo.UID.toString();
    SetCell(UID_CollumIndex, Row_cnt, devInfo.UID.toString(), color);
    SetCell(DMXAddr_CollumIndex, Row_cnt, devInfo.DMXAddr, color);
    SetCell(SEQAddr_CollumIndex, Row_cnt, devInfo.SEQAddr, color);
//    SetCell(Sensor_CollumIndex, Row_cnt, QString::number(devInfo.SensorValue,16), color);
    SetCell(DeviceType_CollumIndex, Row_cnt, devInfo.strDeviceType, color);
    SetCell(FirmwareVersion_CollumIndex, Row_cnt, devInfo.strFWVersion, color);
    if(Authen::user_lv == 1)
    {
        SetCell(MinLevel_CollumIndex, Row_cnt, devInfo.MinLevel, color);
        SetCell(MaxLevel_CollumIndex, Row_cnt, devInfo.MaxLevel, color);
        SetCell(Setting_Parameter, Row_cnt, devInfo.strEEprom, color);
    }
    else if ((Authen::user_lv == 2) or (Authen::user_lv == 3))
    {
        SetCell(MinLevel_CollumIndex, Row_cnt, devInfo.MinLevel, color);
        SetCell(MaxLevel_CollumIndex, Row_cnt, devInfo.MaxLevel, color);
    }

//    if(dmxrdm->isAdministratorUser())
//    {
//        SetCell(MinLevel_CollumIndex, Row_cnt, devInfo.MinLevel, color);
//        SetCell(MaxLevel_CollumIndex, Row_cnt, devInfo.MaxLevel, color);
//        SetCell(Setting_Parameter, Row_cnt, devInfo.strEEprom, color);
//    }
    Row_cnt++;
}

void DeviceView::SetRow(DeviceInfo devInfo, quint16 row, QColor color)
{
    qDebug()<<"Set row"<<devInfo.UID.toString();
    SetCell(UID_CollumIndex, row, devInfo.UID.toString(), color);
    SetCell(DMXAddr_CollumIndex, row, devInfo.DMXAddr, color);
    SetCell(SEQAddr_CollumIndex, row, devInfo.SEQAddr, color);
//    SetCell(Sensor_CollumIndex, row, QString::number(devInfo.SensorValue,16), color);
    SetCell(DeviceType_CollumIndex, row, devInfo.strDeviceType, color);
    SetCell(FirmwareVersion_CollumIndex, row, devInfo.strFWVersion, color);

    if(Authen::user_lv == 1)
    {
        SetCell(MinLevel_CollumIndex, row, devInfo.MinLevel, color);
        SetCell(MaxLevel_CollumIndex, row, devInfo.MaxLevel, color);
        SetCell(Setting_Parameter, row, devInfo.strEEprom, color);
    }
    else if ((Authen::user_lv == 2) or (Authen::user_lv == 3))
    {
        SetCell(MinLevel_CollumIndex, row, devInfo.MinLevel, color);
        SetCell(MaxLevel_CollumIndex, row, devInfo.MaxLevel, color);
    }


//    if(dmxrdm->isAdministratorUser())
//    {
//        SetCell(MinLevel_CollumIndex, row, devInfo.MinLevel, color);
//        SetCell(MaxLevel_CollumIndex, row, devInfo.MaxLevel, color);
//        SetCell(Setting_Parameter, row, devInfo.strEEprom, color);
//    }
}

void DeviceView::BeginDiscovery()
{
    status_running = true;
    bool ok = false;
    loadingDialog->showDialog();
    DeviceTable_Clear();
    lstOfDevice.clear();
    BeginSetRow();
    isRunning = true;
//    dmxrdm->discoveryProcess(UID::BroadcastUID());
    //======================
    DeviceInfo newDevice;
    newDevice.DMXAddr = 1;
    newDevice.SensorValue = 0;
    quint8 a1;

    for (a1 = 0; a1 <=254;a1++){
        dmxrdm->SetUID((QString)"ff");
        dmxrdm->GetDeviceInfo();
        newDevice = dmxrdm->GetDeviceInfo(UID(scanUID), &ok);
//                            _DisplayUIDAddress
        if (!status_running)
        {
                loadingDialog->hideDialog();
                return;
        }

        if(ok)
        {
            bool repeat_list = false;
            foreach (DeviceInfo _dev, lstOfDevice) {
                if(_dev.UID.toString() == newDevice.UID.toString())
                {
                    repeat_list = true;
                }
            }
            if(!repeat_list){
                lstOfDevice<<newDevice;
                SetNextRow(newDevice);
            }
        }
        dmxrdm->showMessage("scanning");
    }





    //=====================
    isRunning = false;
    loadingDialog->hideDialog();
}

void DeviceView::on_tableView_Device_entered(const QModelIndex &index)
{

}

void DeviceView::on_BtnReadParameters_clicked()
{
    qDebug()<<"on_BtnReadParameters_clicked";
    bool ok;
    QModelIndexList selectedList;
    selectedList = ui->tableView_Device->selectionModel()->selectedRows();
    if(selectedList.count() <= 0)
    {
        ui->tableView_Device->selectAll();
        selectedList = ui->tableView_Device->selectionModel()->selectedRows();
        if(selectedList.count() <= 0)
        {
            QMessageBox::information(this, "Read device", "No device selected!");
            return;
        }
    }
    loadingDialog->showDialog();
    isRunning = true;
    ui->BtnReadParameters->setEnabled(false);


    foreach (QModelIndex index, selectedList)
    {
        if(!isRunning) break;
        DeviceInfo devInfo;
        devInfo = dmxrdm->GetDeviceInfo(UID(GetCell(UID_CollumIndex, index.row())), &ok);
        if(!ok){
            dmxrdm->delay_ms(500);
            devInfo = dmxrdm->GetDeviceInfo(UID(GetCell(UID_CollumIndex, index.row())), &ok);
        }

        if(ok)
        {
            this->SetRow(devInfo, index.row());
            qDebug()<<"DMXAddr:" + QString::number(devInfo.DMXAddr);
            qDebug()<<"Sensor:" + QString::number(devInfo.Sensor);
            qDebug()<<"SEQAddr:" + QString::number(devInfo.SEQAddr);
            qDebug()<<"DeviceType:" + QString::number(devInfo.DeviceType);
            qDebug()<<"strDeviceType:" + devInfo.strDeviceType;
            qDebug()<<"SEQAddr:" + QString::number(devInfo.SEQAddr);
            qDebug()<<"SensorValue:" + QString::number(devInfo.SensorValue);
            qDebug()<<"rawSensorValue:" + QString::number(devInfo.rawSensorValue);
            qDebug("===============");
            QT_RGB_DMX_LIB::UID uid_ = GetCell(UID_CollumIndex, index.row());
//            QByteArray uid_;
//            uid_.resize(6);
//            uid_[0] = 0x14;
//            uid_[1] = 0x00;
//            uid_[2] = 0x00;
//            uid_[3] = 0x00;
//            uid_[4] = 0x00;
//            uid_[5] = 0x01;
            dmxrdm_rgb->AskTemperaterSensor(uid_.toQByteArray());
            dmxrdm_rgb->AskCurrentSensor(uid_.toQByteArray());
            this->SetCell(TempSensor_CollumIndex, index.row(), dmxrdm_rgb->DeviceInfo.TemperaterSensor);
            this->SetCell(CurrSensor_CollumIndex, index.row(), dmxrdm_rgb->DeviceInfo.CurrentSensor);
            qDebug()<< QString::number(dmxrdm_rgb->DeviceInfo.TemperaterSensor);
            qDebug()<< QString::number(dmxrdm_rgb->DeviceInfo.CurrentSensor);

//            qDebug()<<QString::number(index.row());
        }
        else
        {
//            qDebug()<<QString::number(index.row());
            this->SetRow(devInfo, index.row(), Qt::red);
            this->SetCell(TempSensor_CollumIndex, index.row(), dmxrdm_rgb->DeviceInfo.TemperaterSensor, Qt::red );
            this->SetCell(CurrSensor_CollumIndex, index.row(), dmxrdm_rgb->DeviceInfo.CurrentSensor, Qt::red);
        }
    }
    ui->BtnReadParameters->setEnabled(true);
    isRunning = false;
    dmxrdm->StopAll();
    loadingDialog->hideDialog();

}

void DeviceView::on_BtnAddNewDev_clicked()
{
    DeviceInfo newDevice;
    bool ok;
    newDevice.DMXAddr = 1;
    newDevice.SensorValue = 0;

    QString sUID = QInputDialog::getText(this, tr("Enter new UID"),
                                         tr("New UID:"), QLineEdit::Normal,
                                         "000:000:000:000:000:001", &ok);
    newDevice.UID = UID(sUID);
    if(ok && newDevice.UID.isValid())
    {
        foreach (DeviceInfo _dev, lstOfDevice) {
            if(_dev.UID.toString() == newDevice.UID.toString())
            {
                QMessageBox::warning(this, "Add new UID", "This device is existed");
                return;
            }
        }
        lstOfDevice<<newDevice;
        SetNextRow(newDevice);
    }
}

void DeviceView::on_BtnSelectAll_clicked()
{
    ui->tableView_Device->selectAll();
}

void DeviceView::on_BtnDeselectAll_clicked()
{
    ui->tableView_Device->clearSelection();
}

void DeviceView::on_BtnWriteDMXAddress_clicked()
{
    bool ok;
    QModelIndexList selectedList;
    selectedList = ui->tableView_Device->selectionModel()->selectedRows();
    if(selectedList.count() <= 0)
    {
        ui->tableView_Device->selectAll();
        selectedList = ui->tableView_Device->selectionModel()->selectedRows();
        if(selectedList.count() <= 0)
        {
            QMessageBox::information(this, "Read device", "No device selected!");
            return;
        }
    }

    ui->BtnWriteDMXAddress->setEnabled(false);
    loadingDialog->showDialog();
    isRunning = true;
    foreach (QModelIndex index, selectedList)
    {
        if(!isRunning) break;
        DeviceInfo devInfo = GetRow(index);
        dmxrdm->SetUID(devInfo.UID);
        dmxrdm->writeDMXID(devInfo.DMXAddr, &ok);
        if(ok)
        {
            this->SetRow(devInfo, index.row());
        }
        else
        {

            this->SetRow(devInfo, index.row(), Qt::red);
        }
    }
    ui->BtnWriteDMXAddress->setEnabled(true);
    isRunning = false;
    loadingDialog->hideDialog();
}

void DeviceView::on_BtnSetTestMode_clicked()
{
    bool ok;
    QModelIndexList selectedList;
    selectedList = ui->tableView_Device->selectionModel()->selectedRows();
    if(selectedList.count() <= 0)
    {
        ui->tableView_Device->selectAll();
        selectedList = ui->tableView_Device->selectionModel()->selectedRows();
        if(selectedList.count() <= 0)
        {
            QMessageBox::information(this, "Read device", "No device selected!");
            return;
        }
    }

    ui->BtnSetTestMode->setEnabled(false);
    loadingDialog->showDialog();
    isRunning = true;
    foreach (QModelIndex index, selectedList)
    {
        if(!isRunning) break;
        DeviceInfo devInfo = GetRow(index);
        dmxrdm->SetUID(devInfo.UID);
        dmxrdm->setTestMode(1, &ok);
        if(ok)
        {
            this->SetRow(devInfo, index.row());
        }
        else
        {

            this->SetRow(devInfo, index.row(), Qt::red);
        }
    }
    ui->BtnSetTestMode->setEnabled(true);
    isRunning = false;
    loadingDialog->hideDialog();
}

void DeviceView::on_BtnWriteLevel_clicked()
{
    bool ok;
    QModelIndexList selectedList;
    selectedList = ui->tableView_Device->selectionModel()->selectedRows();
    if(selectedList.count() <= 0)
    {
        ui->tableView_Device->selectAll();
        selectedList = ui->tableView_Device->selectionModel()->selectedRows();
        if(selectedList.count() <= 0)
        {
            QMessageBox::information(this, "Read device", "No device selected!");
            return;
        }
    }

    ui->BtnWriteLevel->setEnabled(false);
    loadingDialog->showDialog();
    isRunning = true;
    foreach (QModelIndex index, selectedList)
    {
        if(!isRunning) break;
        DeviceInfo devInfo = GetRow(index);
//        dmxrdm->SetUID(devInfo.UID);

        if(Authen::user_lv == 1){
//            dmxrdm->SetThreshold(Max, Min);
            dmxrdm->SetUID(devInfo.UID);
            dmxrdm->SetThreshold(devInfo.MaxLevel, devInfo.MinLevel, &ok);
            if(ok)
            {
                this->SetRow(devInfo, index.row());
//                dmxrdm->delay_ms(2000);
            }
            else
            {

                this->SetRow(devInfo, index.row(), Qt::red);
            }
        }
        if(Authen::user_lv > 1){
            if((Authen::threshold_min <= devInfo.MinLevel)and(devInfo.MaxLevel <= Authen::threshold_max)){
                dmxrdm->SetUID(devInfo.UID);
                dmxrdm->SetThreshold(devInfo.MaxLevel, devInfo.MinLevel, &ok);
                if(ok)
                {
                    this->SetRow(devInfo, index.row());
//                    dmxrdm->delay_ms(2000);
                }
                else
                {

                    this->SetRow(devInfo, index.row(), Qt::red);
                }
            }
            else{
                QMessageBox::information(this, "Warning", "Out of limit:"+QString::number(Authen::threshold_min)+"->"+QString::number(Authen::threshold_max));
            }
        }

//        dmxrdm->SetThreshold(devInfo.MaxLevel, devInfo.MinLevel, &ok);
//        if(ok)
//        {
//            this->SetRow(devInfo, index.row());
//        }
//        else
//        {

//            this->SetRow(devInfo, index.row(), Qt::red);
//        }
    }

    isRunning = false;
    loadingDialog->hideDialog();
    ui->BtnWriteLevel->setEnabled(true);
}

void DeviceView::SaveFile(void)
{
    QString FileName;
    if(lstOfDevice.count() == 0) return;
    FileName = QFileDialog::getSaveFileName(this, "Open Device list",
                                            "",
                                            "List files (*.xml)");
    if(FileName == "") return;


    QString content;
    QXmlStreamWriter writer(&content);
    writer.setAutoFormatting(true);

    writer.writeStartDocument();
    writer.writeStartElement("ListOfDevice");
    for (int row_cnt = 0; row_cnt < lstOfDevice.count(); row_cnt++) {
        DeviceInfo _dev = GetRow(row_cnt);

        writer.writeStartElement("DeviceInfo");
        writer.writeAttribute("UID", _dev.UID.toString());
        writer.writeAttribute("DMXAddress", QString::number(_dev.DMXAddr));
        writer.writeAttribute("SEQAddress", QString::number(_dev.SEQAddr));
        writer.writeAttribute("MaxLevel", QString::number(_dev.MaxLevel));
        writer.writeAttribute("MinLevel", QString::number(_dev.MinLevel));
        writer.writeAttribute("DeviceType", _dev.strDeviceType);// QString::number(_dev.DeviceType));
        writer.writeAttribute("FirmwareVersion", _dev.strFWVersion);// QString::number(_dev.FWVersion));
        writer.writeAttribute("EEprom", _dev.strEEprom);
        writer.writeEndElement();
    }

    writer.writeEndElement();
    writer.writeEndDocument();

    QFile savFile(FileName);
    if(!savFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Saving file", "Can not save file!");
        savFile.close();
        return;
    }
    savFile.write(content.toLatin1());
    savFile.close();
}

void DeviceView::LoadFile(void)
{
    QString FileName;
    FileName = QFileDialog::getOpenFileName(this, "Save Device list",
                                            "",
                                            "List files (*.xml)");
    if(FileName == "") return;

    QFile opnFile(FileName);
    if(!opnFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, "Opening file", "Can not open file!");
        return;
    }

    DeviceTable_Clear();
    lstOfDevice.clear();
    BeginSetRow();

    QXmlStreamReader reader(&opnFile);

    while(!reader.isEndDocument())
    {
        DeviceInfo readDev = DeviceInfo();
        if(reader.hasError())
        {
            break;
        }

        if(reader.isStartElement())
        {
            if(reader.attributes().hasAttribute("UID"))
            {
                //read device UID
                readDev.UID = UID(reader.attributes().value("UID").toString());
                //If UID is invailid skip this element
                //else read DMX address
                if(readDev.UID.isValid())
                {
                    if(reader.attributes().hasAttribute("DMXAddress"))
                    {
                        readDev.DMXAddr = reader.attributes().value("DMXAddress").toUInt();
                    }
                    if(reader.attributes().hasAttribute("SEQAddress"))
                    {
                        readDev.SEQAddr = reader.attributes().value("SEQAddress").toUInt();
                    }
                    if(reader.attributes().hasAttribute("MaxLevel"))
                    {
                        readDev.MaxLevel = reader.attributes().value("MaxLevel").toUShort();
                    }
                    if(reader.attributes().hasAttribute("MinLevel"))
                    {
                        readDev.MinLevel = reader.attributes().value("MinLevel").toUShort();
                    }
                    if(reader.attributes().hasAttribute("DeviceType"))
                    {
                        readDev.strDeviceType = reader.attributes().value("DeviceType").toString();
                    }
                    if(reader.attributes().hasAttribute("FirmwareVersion"))
                    {
                        readDev.strFWVersion = reader.attributes().value("FirmwareVersion").toString();
                    }
                    if(reader.attributes().hasAttribute("EEprom"))
                    {
                        readDev.strEEprom = reader.attributes().value("EEprom").toString();
                    }
                    lstOfDevice<<readDev;
                    reader.skipCurrentElement();
                }
                else
                    reader.skipCurrentElement();
            }
        }

        reader.readNext();

    }

    opnFile.close();
    BeginSetRow();
    foreach (DeviceInfo _devInfo, lstOfDevice)
    {
        SetNextRow(_devInfo);
    }

}

void DeviceView::on_BtnReadPosition_clicked()
{
    ui->BtnReadPosition->setEnabled(false);
    this->WriteSEQ_ID();
    ui->BtnReadPosition->setEnabled(true);
}

void DeviceView::on_BtnUpdateSubDriverFW_clicked()
{
    bool ok;
    QModelIndexList selectedList;
    selectedList = ui->tableView_Device->selectionModel()->selectedRows();
    if(selectedList.count() <= 0)
    {
        QMessageBox::information(this, "Read device", "No device selected!");
        return;
    }
    else if(selectedList.count() != 1)
    {
        QMessageBox::information(this, "Read device", "Please choose 1 device ONLY!");
        return;
    }
    loadingDialog->showDialog();
    isRunning = true;
    foreach (QModelIndex index, selectedList)
    {
        if(!isRunning) break;
        DeviceInfo devInfo = GetRow(index);
        dmxrdm->SetUID(devInfo.UID);
        qDebug()<<"Open gate"<<devInfo.UID.toString();
        int _drvID = QInputDialog::getInt(this, tr("Enter Driver ID (1~3)"),
                                          tr("Driver ID:"), 1, 1, 3, 1, &ok);
        if(ok)
        {
            qDebug()<<_drvID;
            ok = dmxrdm->SubDrvFirmware_Update(_drvID);

            if(ok)
            {
                this->SetRow(devInfo, index.row());

            }
            else
            {

                this->SetRow(devInfo, index.row(), Qt::red);
            }
        }
    }
    isRunning = false;
    loadingDialog->hideDialog();
}

void DeviceView::on_pushButton_clicked()
{

}

void DeviceView::on_BtnWriteParameter_clicked()
{

    bool ok;
    QModelIndexList selectedList;
    selectedList = ui->tableView_Device->selectionModel()->selectedRows();
    if(selectedList.count() <= 0)
    {
        ui->tableView_Device->selectAll();
        selectedList = ui->tableView_Device->selectionModel()->selectedRows();
        if(selectedList.count() <= 0)
        {
            QMessageBox::information(this, "Read device", "No device selected!");
            return;
        }
    }
    ui->BtnWriteParameter->setEnabled(false);
    loadingDialog->showDialog();
    isRunning = true;
    foreach (QModelIndex index, selectedList)
    {
        if(!isRunning) break;
        DeviceInfo devInfo = GetRow(index);
        dmxrdm->SetUID(devInfo.UID);
        qDebug()<<"Write EEprom"<<devInfo.strEEprom;
        dmxrdm->writeEEprom(devInfo.strEEprom, &ok);
        if(ok)
        {
            this->SetRow(devInfo, index.row());
        }
        else
        {

            this->SetRow(devInfo, index.row(), Qt::red);
        }
    }
    isRunning = false;
    loadingDialog->hideDialog();
    ui->BtnWriteParameter->setEnabled(true);
}

void DeviceView::closeEvent (QCloseEvent *event)
{
    qDebug("close DeviceView window");
    status_running = false;
}


void DeviceView::close_loadingdialog(){
    qDebug("event close loadingdialog window");
   status_running = false;
}


void DeviceView::_DisplayUIDAddress(QString UID){
qDebug()<< "_DisplayUIDAddress:"+UID;
scanUID = UID;
}
