#ifndef LEDRGBCTRL_H
#define LEDRGBCTRL_H

#include <QDialog>
#include "qtdmxlib.h"
#include "debug.h"
#include <QMessageBox>
#include "qtbaselib.h"
#include "loadingdialog.h"
#include "authen.h"
#include <QCloseEvent>

namespace Ui {
class LedRGBCtrl;
}

class LedRGBCtrl : public QDialog
{
    Q_OBJECT

public:
    explicit LedRGBCtrl(QWidget *parent = nullptr);
    ~LedRGBCtrl();
public slots:
    void ShowLedRGBCtrl(void);
private slots:
    void on_btnRead_clicked();

    void on_btnWrite_clicked();

private:
    Ui::LedRGBCtrl *ui;
};

#endif // LEDRGBCTRL_H
