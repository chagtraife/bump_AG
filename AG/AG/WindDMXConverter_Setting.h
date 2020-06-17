#ifndef WINDDMXCONVERTER_SETTING_H
#define WINDDMXCONVERTER_SETTING_H

#include <QDialog>
#include "qtbaselib.h"

class QStandardItemModel;
class QPoint;
class QAction;
class DMXRDM;
class DeviceInfo;
namespace Ui {
class WindDMXConverter_Setting;
}

class WindDMXConverter_Setting : public QDialog
{
    Q_OBJECT

public:
    uint8_t DMX_Map[514];
    explicit WindDMXConverter_Setting(QWidget *parent = 0);
    ~WindDMXConverter_Setting();

    void showDialog(DeviceInfo dev);
private slots:
    void customMenuRequested(QPoint pos);
    void on_SelectAll(void);
    void on_SelectOdd(void);
    void on_SelectEven(void);
    void on_ChangeValue(void);

    void on_Btn_Cancel_clicked();

    void on_Btn_ReadFromDev_clicked();

    void on_Btn_WriteToDev_clicked();

private:
    Ui::WindDMXConverter_Setting *ui;
    QStandardItemModel *model;
    QAction *selectAll;
    QAction *selectOdd;
    QAction *selectEven;
    QAction *changeValue;
    UID _UID;

    void refreshDMXDisplay(void);
    void SetCell(quint16 x, quint16 y, QString data, uint8_t color);
};

#endif // WINDDMXCONVERTER_SETTING_H
