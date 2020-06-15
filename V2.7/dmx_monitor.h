#ifndef DMX_MONITOR_H
#define DMX_MONITOR_H

#include <QDialog>
#include <QList>
#include <QTimer>
#include <QElapsedTimer>
#include <QFile>
#include <QTextStream>
#include <stdint.h>
class QStandardItemModel;

namespace Ui {
class DMX_Monitor;
}

class DMX_Monitor : public QDialog
{
    Q_OBJECT

public:
    explicit DMX_Monitor(QWidget *parent = 0);
    ~DMX_Monitor();
    void ReadBreak(void);
    void ReadData(QByteArray dat);
public slots:
    void ShowDMXmonitor(void);

private slots:
    void _1sTick(void);
    void on_txt_SampleRate_textChanged(const QString &arg1);
    void on_txt_RecordedChannel_textChanged(const QString &arg1);
    void on_btn_Rec_clicked();

private:
    typedef enum DMX_ERROR_TYPE
    {
        NO_ERROR = 0,
        FRAME_LENGTH,
        FRAME_SYNTAX,
        FRAME_RDM,
    }DMX_ERROR_TYPE;
    const QString DMX_ERROR_TYPE_str[4] =
    {
        "NO_ERROR",
        "FRAME_LENGTH",
        "FRAME_SYNTAX",
        "FRAME_RDM",
    };

    Ui::DMX_Monitor *ui;
    QStandardItemModel *model;
    QTimer *TimerTick;
    QElapsedTimer *RecordTimer;
    DMX_ERROR_TYPE _error, _lst_error;
    uint8_t _DMX_buffer[518];
    uint32_t _frameRate, _frameCnt, _frameLength, _frameByteCnt, _frameERRcnt, _frameVerifyCnt;
    uint32_t _frameRateDisp, _frameLengthDisp, _frameERRpercentDisp;
    uint16_t _sampleRate, _samplePeriod;
    uint16_t _beginChannel, _endChannel;
    uint32_t _recByteCnt;
    bool _isRecording;
    bool refreshDMXDisplay_request;
    void SetCell(quint16 x, quint16 y, QString data, uint8_t color);
    void SetCell(quint16 x, quint16 y, uint32_t data, uint8_t color);
    void refreshDMXDisplay(void);

    const QString outputFilename = "temp.txt";
    QFile outputFile;
    QTextStream outStream;
    uint32_t _recordedFileSize;
    const QString str_Recording_Header =
            "const unsigned char prog1[] __attribute__((at(0x08010400))) =\r\n"
            "{\r\n";
};

#endif // DMX_MONITOR_H
