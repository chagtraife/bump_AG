#ifndef USERMANAGERSETTING_H
#define USERMANAGERSETTING_H

#include <QDialog>
#include "QDebug"
#include "QtSql"
#include "authen.h"
namespace Ui {
class UserManagerSetting;
}

class UserManagerSetting : public QDialog,  public Authen
{
    Q_OBJECT

public:
    explicit UserManagerSetting(QWidget *parent = 0);
    ~UserManagerSetting();
public slots:
    void ShowUserManagerSetting(void);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::UserManagerSetting *ui;
};

#endif // USERMANAGERSETTING_H
