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


namespace Ui {
class DMXconsole;
}


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

private slots:
    void BtnDMXStreaming_Clicked(void);
    void DMXTick(void);

private:
    Ui::DMXconsole *ui;
    QHBoxLayout *layout;
    QTimer *TimerTick;
    bool IsDMXRunning, IsSelectAll;
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
};

#endif // DMXCONSOLE_H
