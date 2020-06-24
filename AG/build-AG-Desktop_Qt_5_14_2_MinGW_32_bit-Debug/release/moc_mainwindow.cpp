/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AG/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[50];
    char stringdata0[715];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "showLoadingDialog"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "hideLoadingDialog"
QT_MOC_LITERAL(4, 48, 10), // "setUserlev"
QT_MOC_LITERAL(5, 59, 14), // "openSerialPort"
QT_MOC_LITERAL(6, 74, 15), // "closeSerialPort"
QT_MOC_LITERAL(7, 90, 5), // "about"
QT_MOC_LITERAL(8, 96, 10), // "writeBreak"
QT_MOC_LITERAL(9, 107, 9), // "writeData"
QT_MOC_LITERAL(10, 117, 4), // "data"
QT_MOC_LITERAL(11, 122, 13), // "writeData_RGB"
QT_MOC_LITERAL(12, 136, 18), // "writeDataBreak_RGB"
QT_MOC_LITERAL(13, 155, 6), // "_break"
QT_MOC_LITERAL(14, 162, 12), // "readData_RGB"
QT_MOC_LITERAL(15, 175, 8), // "readData"
QT_MOC_LITERAL(16, 184, 12), // "_setBaudrate"
QT_MOC_LITERAL(17, 197, 2), // "br"
QT_MOC_LITERAL(18, 200, 11), // "handleError"
QT_MOC_LITERAL(19, 212, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(20, 241, 5), // "error"
QT_MOC_LITERAL(21, 247, 24), // "AdministratorTick_Handle"
QT_MOC_LITERAL(22, 272, 13), // "_searchDevice"
QT_MOC_LITERAL(23, 286, 11), // "_writeDMXID"
QT_MOC_LITERAL(24, 298, 11), // "_writeSEQID"
QT_MOC_LITERAL(25, 310, 9), // "_writeUID"
QT_MOC_LITERAL(26, 320, 12), // "_setTestMode"
QT_MOC_LITERAL(27, 333, 18), // "_showDMXRDMMessage"
QT_MOC_LITERAL(28, 352, 7), // "message"
QT_MOC_LITERAL(29, 360, 18), // "_DisplayDMXAddress"
QT_MOC_LITERAL(30, 379, 6), // "DMXAdd"
QT_MOC_LITERAL(31, 386, 18), // "_DisplayUIDAddress"
QT_MOC_LITERAL(32, 405, 3), // "UID"
QT_MOC_LITERAL(33, 409, 18), // "_DisplaySEQAddress"
QT_MOC_LITERAL(34, 428, 6), // "SEQAdd"
QT_MOC_LITERAL(35, 435, 17), // "_DisplayThreshold"
QT_MOC_LITERAL(36, 453, 3), // "Max"
QT_MOC_LITERAL(37, 457, 3), // "Min"
QT_MOC_LITERAL(38, 461, 15), // "_BtnDMX_Clicked"
QT_MOC_LITERAL(39, 477, 26), // "_BtnFirmwareUpdate_Clicked"
QT_MOC_LITERAL(40, 504, 10), // "_DMXStream"
QT_MOC_LITERAL(41, 515, 23), // "on_BtnSearchDev_clicked"
QT_MOC_LITERAL(42, 539, 25), // "on_BtnWrThreshold_clicked"
QT_MOC_LITERAL(43, 565, 22), // "on_BtnWriteUID_clicked"
QT_MOC_LITERAL(44, 588, 29), // "on_BtnDeviceDiscovery_clicked"
QT_MOC_LITERAL(45, 618, 13), // "on_ActionUser"
QT_MOC_LITERAL(46, 632, 7), // "setUser"
QT_MOC_LITERAL(47, 640, 19), // "isAdministratorUser"
QT_MOC_LITERAL(48, 660, 30), // "on_DeviceTypeSelection_clicked"
QT_MOC_LITERAL(49, 691, 23) // "on_BtnReadDMXID_clicked"

    },
    "MainWindow\0showLoadingDialog\0\0"
    "hideLoadingDialog\0setUserlev\0"
    "openSerialPort\0closeSerialPort\0about\0"
    "writeBreak\0writeData\0data\0writeData_RGB\0"
    "writeDataBreak_RGB\0_break\0readData_RGB\0"
    "readData\0_setBaudrate\0br\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "AdministratorTick_Handle\0_searchDevice\0"
    "_writeDMXID\0_writeSEQID\0_writeUID\0"
    "_setTestMode\0_showDMXRDMMessage\0message\0"
    "_DisplayDMXAddress\0DMXAdd\0_DisplayUIDAddress\0"
    "UID\0_DisplaySEQAddress\0SEQAdd\0"
    "_DisplayThreshold\0Max\0Min\0_BtnDMX_Clicked\0"
    "_BtnFirmwareUpdate_Clicked\0_DMXStream\0"
    "on_BtnSearchDev_clicked\0"
    "on_BtnWrThreshold_clicked\0"
    "on_BtnWriteUID_clicked\0"
    "on_BtnDeviceDiscovery_clicked\0"
    "on_ActionUser\0setUser\0isAdministratorUser\0"
    "on_DeviceTypeSelection_clicked\0"
    "on_BtnReadDMXID_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  194,    2, 0x06 /* Public */,
       3,    0,  195,    2, 0x06 /* Public */,
       4,    0,  196,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  197,    2, 0x08 /* Private */,
       6,    0,  198,    2, 0x08 /* Private */,
       7,    0,  199,    2, 0x08 /* Private */,
       8,    0,  200,    2, 0x08 /* Private */,
       9,    1,  201,    2, 0x08 /* Private */,
      11,    1,  204,    2, 0x08 /* Private */,
      12,    2,  207,    2, 0x08 /* Private */,
      14,    0,  212,    2, 0x08 /* Private */,
      15,    0,  213,    2, 0x08 /* Private */,
      16,    1,  214,    2, 0x08 /* Private */,
      18,    1,  217,    2, 0x08 /* Private */,
      21,    0,  220,    2, 0x08 /* Private */,
      22,    0,  221,    2, 0x08 /* Private */,
      23,    0,  222,    2, 0x08 /* Private */,
      24,    0,  223,    2, 0x08 /* Private */,
      25,    0,  224,    2, 0x08 /* Private */,
      26,    0,  225,    2, 0x08 /* Private */,
      27,    1,  226,    2, 0x08 /* Private */,
      29,    1,  229,    2, 0x08 /* Private */,
      31,    1,  232,    2, 0x08 /* Private */,
      33,    1,  235,    2, 0x08 /* Private */,
      35,    2,  238,    2, 0x08 /* Private */,
      38,    0,  243,    2, 0x08 /* Private */,
      39,    0,  244,    2, 0x08 /* Private */,
      40,    0,  245,    2, 0x08 /* Private */,
      41,    0,  246,    2, 0x08 /* Private */,
      42,    0,  247,    2, 0x08 /* Private */,
      43,    0,  248,    2, 0x08 /* Private */,
      44,    0,  249,    2, 0x08 /* Private */,
      45,    0,  250,    2, 0x08 /* Private */,
      46,    1,  251,    2, 0x08 /* Private */,
      48,    0,  254,    2, 0x08 /* Private */,
      49,    0,  255,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,   10,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::UShort,   30,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::UShort,   34,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   36,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLoadingDialog(); break;
        case 1: _t->hideLoadingDialog(); break;
        case 2: _t->setUserlev(); break;
        case 3: _t->openSerialPort(); break;
        case 4: _t->closeSerialPort(); break;
        case 5: _t->about(); break;
        case 6: _t->writeBreak(); break;
        case 7: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->writeData_RGB((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 9: _t->writeDataBreak_RGB((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->readData_RGB(); break;
        case 11: _t->readData(); break;
        case 12: _t->_setBaudrate((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 13: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 14: _t->AdministratorTick_Handle(); break;
        case 15: _t->_searchDevice(); break;
        case 16: _t->_writeDMXID(); break;
        case 17: _t->_writeSEQID(); break;
        case 18: _t->_writeUID(); break;
        case 19: _t->_setTestMode(); break;
        case 20: _t->_showDMXRDMMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->_DisplayDMXAddress((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 22: _t->_DisplayUIDAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->_DisplaySEQAddress((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 24: _t->_DisplayThreshold((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 25: _t->_BtnDMX_Clicked(); break;
        case 26: _t->_BtnFirmwareUpdate_Clicked(); break;
        case 27: _t->_DMXStream(); break;
        case 28: _t->on_BtnSearchDev_clicked(); break;
        case 29: _t->on_BtnWrThreshold_clicked(); break;
        case 30: _t->on_BtnWriteUID_clicked(); break;
        case 31: _t->on_BtnDeviceDiscovery_clicked(); break;
        case 32: _t->on_ActionUser(); break;
        case 33: _t->setUser((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_DeviceTypeSelection_clicked(); break;
        case 35: _t->on_BtnReadDMXID_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showLoadingDialog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hideLoadingDialog)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setUserlev)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Authen"))
        return static_cast< Authen*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::showLoadingDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::hideLoadingDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::setUserlev()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
