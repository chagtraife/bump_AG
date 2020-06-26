#ifndef THRESHOLDMANAGERSETTING_H
#define THRESHOLDMANAGERSETTING_H

#include <QDialog>
#include "QDebug"
#include "QtSql"
#include "authen.h"

namespace Ui {
class ThresholdManagerSetting;
}

class ThresholdManagerSetting : public QDialog, public Authen
{
    Q_OBJECT

public:
    explicit ThresholdManagerSetting(QWidget *parent = nullptr);
    ~ThresholdManagerSetting();
public slots:
    void ShowThresholdManagerSetting(void);
private slots:
    void on_btnSetMin_clicked();

    void on_btnSetMax_clicked();

private:
    Ui::ThresholdManagerSetting *ui;
};

#endif // THRESHOLDMANAGERSETTING_H
