#ifndef LEDRGBWCTRL_H
#define LEDRGBWCTRL_H

#include <QDialog>
#include "qtdmxlib.h"
#include "debug.h"
#include <QMessageBox>
#include "qtbaselib.h"
#include "loadingdialog.h"
#include "authen.h"
#include <QCloseEvent>

namespace Ui {
class LedRGBWCtrl;
}

class LedRGBWCtrl : public QDialog
{
    Q_OBJECT

public:
    explicit LedRGBWCtrl(QWidget *parent = nullptr);
    ~LedRGBWCtrl();
public slots:
    void ShowLedRGBWCtrl(void);
private slots:
    void on_btnRead_clicked();

    void on_btnWrite_clicked();

private:
    Ui::LedRGBWCtrl *ui;
};

#endif // LEDRGBWCTRL_H
