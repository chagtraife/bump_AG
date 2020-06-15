#include "WindDMXConverter_Setting.h"
#include "ui_WindDMXConverter_Setting.h"
#include <QStandardItemModel>
#include <QPoint>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QInputDialog>
#include "qtbaselib.h"

WindDMXConverter_Setting::WindDMXConverter_Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindDMXConverter_Setting)
{
    model = new QStandardItemModel(0,0,this);
    ui->setupUi(this);
    for(int i = 0; i < 16; i++)
    {
        model->setHorizontalHeaderItem(i, new QStandardItem(QString::number(i+1)));
    }
    ui->tableView_DMXMap->setModel(model);
    refreshDMXDisplay();
    memset(DMX_Map, 0, sizeof(DMX_Map));
    connect(ui->tableView_DMXMap, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(customMenuRequested(QPoint)));
    selectAll = new QAction("Select all", this);
    selectOdd = new QAction("Select Odd", this);
    selectEven = new QAction("Select Even", this);
    changeValue = new QAction("Change value", this);
    connect(this->selectAll, SIGNAL(triggered(bool)), this, SLOT(on_SelectAll()));
    connect(this->selectOdd, SIGNAL(triggered(bool)), this, SLOT(on_SelectOdd()));
    connect(this->selectEven, SIGNAL(triggered(bool)), this, SLOT(on_SelectEven()));
    connect(this->changeValue, SIGNAL(triggered(bool)), this, SLOT(on_ChangeValue()));
    _UID = UID::BroadcastUID();
}

void WindDMXConverter_Setting::on_SelectAll(void)
{
    ui->tableView_DMXMap->selectAll();
}

void WindDMXConverter_Setting::on_SelectOdd(void)
{
    QModelIndexList qModelList;
    qModelList = ui->tableView_DMXMap->selectionModel()->selectedIndexes();
    if(qModelList.count() <= 0)
    {
        ui->tableView_DMXMap->selectAll();
    }

    qModelList = ui->tableView_DMXMap->selectionModel()->selectedIndexes();
    if(qModelList.count() > 0)
    {
        int i = 0;
        foreach (QModelIndex cell, qModelList)
        {
            if(i++%2 != 0)
            {
                ui->tableView_DMXMap->selectionModel()->select(cell, QItemSelectionModel::Deselect);
            }
        }
    }
}

void WindDMXConverter_Setting::on_SelectEven(void)
{
    QModelIndexList qModelList;
    qModelList = ui->tableView_DMXMap->selectionModel()->selectedIndexes();
    if(qModelList.count() <= 0)
    {
        ui->tableView_DMXMap->selectAll();
    }

    qModelList = ui->tableView_DMXMap->selectionModel()->selectedIndexes();
    if(qModelList.count() > 0)
    {
        int i = 0;
        foreach (QModelIndex cell, qModelList)
        {
            if(i++%2 == 0)
            {
                ui->tableView_DMXMap->selectionModel()->select(cell, QItemSelectionModel::Deselect);
            }
        }
    }
}

void WindDMXConverter_Setting::on_ChangeValue(void)
{
    QModelIndexList qModelList;
    qModelList = ui->tableView_DMXMap->selectionModel()->selectedIndexes();
    if(qModelList.count() <= 0)
    {
        return;
    }

    bool ok;
    int _val = QInputDialog::getInt(this, tr("Enter new value (0~100)"),
                                    tr("new value:"), 100, 0, 100, 1, &ok);

    if(ok)
    {
        foreach (QModelIndex cell, qModelList)
        {
            SetCell(cell.column(), cell.row(), QString::number(_val), 0);
        }
    }
}

void WindDMXConverter_Setting::customMenuRequested(QPoint pos){
    QModelIndex index=ui->tableView_DMXMap->indexAt(pos);

    QMenu *menu=new QMenu(this);
    menu->addAction(selectAll);
    menu->addAction(selectOdd);
    menu->addAction(selectEven);
    menu->addAction(changeValue);
    menu->popup(ui->tableView_DMXMap->viewport()->mapToGlobal(pos));
}

WindDMXConverter_Setting::~WindDMXConverter_Setting()
{
    delete ui;
}

void WindDMXConverter_Setting::showDialog(DeviceInfo dev)
{
    _UID = dev.UID;
    refreshDMXDisplay();
    this->show();
}

void WindDMXConverter_Setting::refreshDMXDisplay(void)
{
    int cellCnt = 0;
    for(int y = 0; y < 32; y++)
    {
        for( int x = 0; x < 16; x++)
        {
            if(cellCnt >= sizeof(DMX_Map)) break;
            SetCell(x, y, QString::number(DMX_Map[cellCnt]), DMX_Map[cellCnt]);
            cellCnt++;
        }
    }
}

void WindDMXConverter_Setting::SetCell(quint16 x, quint16 y, QString data, uint8_t color)
{
    QColor _color = QColor::fromRgb(0, 0, color*255/100);
    QStandardItem *row = new QStandardItem(data);
    row->setForeground(_color);
    model->setItem(y,x,row);
}

void WindDMXConverter_Setting::on_Btn_Cancel_clicked()
{
    this->close();
}

void WindDMXConverter_Setting::on_Btn_ReadFromDev_clicked()
{
    uint16_t _byteCnt = 0;
    QByteArray _buff;
    ui->tableView_DMXMap->selectAll();
    dmxrdm->SetUID(_UID);
    QModelIndexList qModelList;
    qModelList = ui->tableView_DMXMap->selectionModel()->selectedIndexes();

    for(int i = 0; i < 64; i++)
    {
        _buff = dmxrdm->ReadInternalMemory(i*8, 8);
        if(_buff.size() != 8)
        break;

        for(int j = 0; j < 8; j++)
        {
            ui->tableView_DMXMap->selectionModel()->select(qModelList[_byteCnt], QItemSelectionModel::Deselect);
            DMX_Map[_byteCnt] = (uint8_t)_buff[j];
            _byteCnt++;
        }
    }
    refreshDMXDisplay();
}

void WindDMXConverter_Setting::on_Btn_WriteToDev_clicked()
{
    uint16_t _byteCnt = 0;
    QByteArray _buff;
    bool ok;
    ui->tableView_DMXMap->selectAll();
    dmxrdm->SetUID(_UID);
    QModelIndexList qModelList;
    qModelList = ui->tableView_DMXMap->selectionModel()->selectedIndexes();

    _byteCnt = 0;
    foreach (QModelIndex cell, qModelList) {
        QStandardItem *row;
        row = model->item(cell.row(), cell.column());

        if(_byteCnt >= sizeof(DMX_Map))
            break;

        DMX_Map[_byteCnt] = ((QString)(row->text())).toInt();
        _byteCnt++;
    }

    _byteCnt = 0;

    for(int i = 0; i < 64; i++)
    {
        _buff.clear();
        for(int j = 0; j < 8; j++)
        {
            ui->tableView_DMXMap->selectionModel()->select(qModelList[_byteCnt], QItemSelectionModel::Deselect);
            _buff.append(DMX_Map[_byteCnt]);
            _byteCnt++;
        }
        dmxrdm->WriteInternalMemory(i*8, _buff, &ok);
        if(!ok)
            break;
    }
}
