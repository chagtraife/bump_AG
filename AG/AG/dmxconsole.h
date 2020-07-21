#ifndef DMXCONSOLE_H
#define DMXCONSOLE_H

#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QTimer>
#include <QCloseEvent>
#include "console_enhance.h"
#include "QString"


namespace Ui {
class DMXconsole;
}

class Console_Enhance;

class DMXconsole : public QDialog
{
    Q_OBJECT
signals:
    void DMXTriggle(void);
    void signal_close(void);

public:
    explicit DMXconsole(QWidget *parent = 0);
    ~DMXconsole();
    QByteArray DMXBuffer;
    int DMXBuffer_[513];
    void reset_choice(void);

private slots:
    void BtnDMXStreaming_Clicked(void);
    void DMXTick(void);

private:
    Ui::DMXconsole *ui;
    QHBoxLayout *layout;
    QTimer *TimerTick;
    bool IsDMXRunning, IsSelectAll;
    bool enhance_state,odd_state, even_state, all_state;
    Console_Enhance *enhance_config;
    typedef enum state_choice
    {
        None = 0,
        All = 1,
        Odd = 2,
        Even = 3,
        Enhance = 4
    }state_choice;
    state_choice state, state_temp;
    void UI_Init(void);
    quint16 GetIndex(void);

public:
    static int idx;


private slots:
    void _updateLb_value0(int val);

    void _syncDMXBuffer(int index);
    void _chk_SelectAll_Changed(void);
    void FocusChanged(bool dir);
    void closeEvent (QCloseEvent *event);
    void on_rd_Enhance_clicked();
    void on_rd_Odd_clicked();
    void on_rd_Even_clicked();
    void on_rd_SelectAll_clicked();
    void into_mode_enhance(void);
    void goback(void);
    void on_sl_value0_valueChanged(int value);
    void on_sl_value1_valueChanged(int value);
    void on_sl_value2_valueChanged(int value);
    void on_sl_value3_valueChanged(int value);
    void on_sl_value4_valueChanged(int value);
    void on_sl_value5_valueChanged(int value);
    void on_sl_value6_valueChanged(int value);
    void on_sl_value7_valueChanged(int value);
    void on_sl_value8_valueChanged(int value);
    void on_sl_value9_valueChanged(int value);
    void on_sl_value10_valueChanged(int value);
};

#endif // DMXCONSOLE_H
