#ifndef DMXRDM_H
#define DMXRDM_H

#include <QtCore/QtGlobal>

#include <QMainWindow>
#include <QObject>
#include <QPlainTextEdit>
#include <QDateTime>
#include <QProcess>
#include <stdint.h>
extern QString DMXRDM_message;

class UID
{
public:
    UID();
    UID(QString sUID);
    UID(quint8 UID1,
        quint8 UID2,
        quint8 UID3,
        quint8 UID4,
        quint8 UID5,
        quint8 UID6);
    UID(QByteArray bUID);

    static QString BroadcastUID(void);
    static QString DefaultUID(void);
    void SetBroadcast(void);
    void SetDefault(void);
    QString toString(void);
    QByteArray toQByteArray(void);
    void fromQByteArray(QByteArray _bUID);
    bool isValid(void);
    bool isBroadcast(void);
private:
    QString sUID;
    QByteArray bUID;
    bool _isValid;
};

class DeviceInfo{
public:
    DeviceInfo();
    quint16 DMXAddr;
    UID UID;
    quint8 MaxLevel;
    quint8 MinLevel;
    quint8 Sensor;
    quint8 SEQAddr;
    quint8 DeviceType;
    QString strDeviceType;
    quint8 FWVersion;
    QString strFWVersion;
    uint16_t SensorValue;
    uint16_t rawSensorValue;
    uint8_t EEprom[10];
    QString strEEprom;
    QString GetDeviceTypeName(uint8_t DevType);
    QString GetFirmwareName(uint8_t FWVersion);
    virtual void UserSetting_Handle(void);

    typedef enum DEVICE_TYPE
    {
        LIGHT_RGB = 1,
        LIGHT_RGBW = 2,
        LIGHT_RGBWA = 3,
        DC_PUMP = 4,
        AC_PUMP = 5,
        CAPERJET = 6,
        MINILEAPJET = 7,
        YTL_NOZZLE,
        VARIABLE_PATTERN_JET,
        PROPORTIONAL_SWITCH,
        SPLITTER,
        SSR,
        WIND_READER,
        WIND_DMX_CONVERTER,
        DEVICE_TOTAL
    }DEVICE_TYPE;


    QString DEVICE_NAME[DEVICE_TOTAL] = {
        "",
        "LumiFons RGB",
        "LumiFons RGBW",
        "LumiFons RGBWA",
        "ECOFICIENT Pump",
        "PROFICIENT Pump",
        "CAPERJET",
        "Mini Leap",
        "ANIMATRONIC",
        "Variable Pattern Jet",
        "Proportional Switch",
        "Splitter",
        "SSR",
        "Weather Station",
        "DMX converter"
    };
};

class DMXRDM : public QPlainTextEdit
{
    Q_OBJECT
public:
    //constant definition
    static const int FrameSize = 50;
    static const int ResponeTimeout = 100;
    QByteArray FrameHeader;
public:
    DMXRDM();
    QByteArray RxFrame;
    QByteArray TxFrame;
    UID GetUID();
    void SetUID(UID newUID);
    void SetUID(QString newUID);
    void SetUID(QByteArray newUID);
    void SetUID(quint8 newUID1, quint8 newUID2, quint8 newUID3, quint8 newUID4, quint8 newUID5, quint8 newUID6);

public:
    void searchDevice(void);
    void writeDMXID(int addr, bool *ok = 0);
    void writeUID(QString newUID, bool *ok = 0);
    void writeEEprom(QString newEEprom, bool *ok = 0);
    void setTestMode(quint8 mode, bool *ok = 0);
    void setOpenGate(bool *ok = 0);
    uint8_t Firmware_Update(void);
    uint8_t SubDrvFirmware_Update(uint8_t subDrv_Addr);
    void GetDeviceInfo(void);
    DeviceInfo GetDeviceInfo(UID devUID, bool *ok = 0);
    QByteArray ReadInternalMemory(uint16_t addr, uint8_t byteToread);
    void WriteInternalMemory(uint16_t addr, QByteArray data, bool *ok = 0);
    void SetThreshold(quint8 Max, quint8 Min, bool *ok = 0);
    void ResetDevice(void);
    void StopAll(void);

    void delay_ms(quint32 ms);
    QString discoveryProcess(QString lstUID);
    void BreakDetected(void);

    quint16 Make16(quint8 HighByte, quint8 LowByte);
    static quint8 Ascci2Byte(QString num);
    static QString Byte2Ascci(quint8 num);
    quint8 HighByte(quint16 num);
    quint8 LowByte(quint16 num);

    void SetAdministratorUser(QString password);
    bool CheckTimeLimitation(QString password);
    bool isAdministratorUser(void);
    QByteArray tr1Array(void);
    QByteArray tr2Array(void);
    QByteArray tr3Array(void);
    QByteArray tr4Array(void);

signals:
    void showMessage(const QString message);
    void displayDMXAddr(quint16 DMXAddr);
    void displaySEQAddr(quint16 SEQAddr);
    void displayUID(QString dispUID);
    void displayThreshold(QString Max, QString Min);
    void sendBreak(void);
    void sendFrame(const QByteArray &data);
    void setBaudrate(quint32 br);
    void ClosePort(void);
    void DiscFoundDevice(QString FoundUID);
    void DiscScannedDevice(QString ScannedUID);
    void SetUser(bool isAdministrator);

private:
    bool breakDetected = false;
    const int RetryTimes = 5;
    const int RetryDelay = 100;

    int DMXID;
    UID DevUID;
    DeviceInfo deviceInfo;
    QString _errorString;
    //RDM structure
    struct RDMFrame{
        //6 bytes of device ID and controler ID
        QByteArray DevUID;
        QByteArray CtrlUID;
        unsigned int len;
        unsigned int frameCnt;
        unsigned int cmd;
        QByteArray parameter;
        unsigned int parameterCnt;
        unsigned int pl_len;
        unsigned char chksum;
    };
    typedef struct RDMFrame RDMFRAME;

    typedef enum RDM_CMD
    {
        cmd_Ping = 0x00,
        cmd_AskDevType = 0x01,
        cmd_AskSlots = 0x02,
        cmd_AskSensors = 0x03,
        cmd_AskValSensor = 0x04,
        cmd_AskDMXSlot = 0x05,
        cmd_SetDMXSlot = 0x06,
        cmd_SetMode = 0x07,
        cmd_AskUID = 0x08,
        cmd_SetUID = 0x09,
        cmd_Disc = 0xFF,
        cmd_AskThreshold = 0x0A,
        cmd_SetThreshold = 0x0B,
        cmd_RstDev = 0x0C,
        cmd_GetFwVersion = 0x0D,
        cmd_GetSEQAddress = 0x0E,
        cmd_ReadMemory = 0x10,
        cmd_WriteMemory = 0x11,
        cmd_OpenGate = 0x12,
        cmd_ReadInternalMemory = 0x13,
        cmd_WriteInternalMemory = 0x14
    }RDM_CMD;

    RDMFRAME RxFrameStruct;
    RDMFRAME TxFrameStruct;


    void BufferInit(void);
    void MakeTxFrame(void);
    void WaitRespone(void);
    void WaitBreak(void);

    quint8 ProcessRxFrame(void);
    quint8 DiscoveryDevice(UID discUID);
    bool UserAdministrator;
    bool isRunning;
    QDate ConvertedFromCustomString(QString str);
    QString ConvertedFromEncrypt(QString str);
    QProcess process;
private slots:
    quint8 ReadRxFrame(void);
};

extern DMXRDM *dmxrdm;
#endif // DMXRDM_H
