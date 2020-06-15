#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include <QTimer>
#include <stdint.h>
namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();
private slots:
    void on_Test1_Clicked(void);
    void on_Test2_Clicked(void);
    void on_Test3_Clicked(void);
    void on_Test4_Clicked(void);
    void on_Timer_Tick(void);
private:
    uint8_t step;
    Ui::TestDialog *ui;
    QTimer *TimerTick;
    uint16_t Timeout;
};

#endif // TESTDIALOG_H
