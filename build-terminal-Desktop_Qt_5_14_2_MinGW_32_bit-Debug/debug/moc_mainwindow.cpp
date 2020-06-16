/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../V2.7/mainwindow.h"
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
    QByteArrayData data[44];
    char stringdata0[627];
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
QT_MOC_LITERAL(4, 48, 14), // "openSerialPort"
QT_MOC_LITERAL(5, 63, 15), // "closeSerialPort"
QT_MOC_LITERAL(6, 79, 5), // "about"
QT_MOC_LITERAL(7, 85, 10), // "writeBreak"
QT_MOC_LITERAL(8, 96, 9), // "writeData"
QT_MOC_LITERAL(9, 106, 4), // "data"
QT_MOC_LITERAL(10, 111, 8), // "readData"
QT_MOC_LITERAL(11, 120, 12), // "_setBaudrate"
QT_MOC_LITERAL(12, 133, 2), // "br"
QT_MOC_LITERAL(13, 136, 11), // "handleError"
QT_MOC_LITERAL(14, 148, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(15, 177, 5), // "error"
QT_MOC_LITERAL(16, 183, 24), // "AdministratorTick_Handle"
QT_MOC_LITERAL(17, 208, 13), // "_searchDevice"
QT_MOC_LITERAL(18, 222, 11), // "_writeDMXID"
QT_MOC_LITERAL(19, 234, 11), // "_writeSEQID"
QT_MOC_LITERAL(20, 246, 9), // "_writeUID"
QT_MOC_LITERAL(21, 256, 12), // "_setTestMode"
QT_MOC_LITERAL(22, 269, 18), // "_showDMXRDMMessage"
QT_MOC_LITERAL(23, 288, 7), // "message"
QT_MOC_LITERAL(24, 296, 18), // "_DisplayDMXAddress"
QT_MOC_LITERAL(25, 315, 6), // "DMXAdd"
QT_MOC_LITERAL(26, 322, 18), // "_DisplayUIDAddress"
QT_MOC_LITERAL(27, 341, 3), // "UID"
QT_MOC_LITERAL(28, 345, 18), // "_DisplaySEQAddress"
QT_MOC_LITERAL(29, 364, 6), // "SEQAdd"
QT_MOC_LITERAL(30, 371, 17), // "_DisplayThreshold"
QT_MOC_LITERAL(31, 389, 3), // "Max"
QT_MOC_LITERAL(32, 393, 3), // "Min"
QT_MOC_LITERAL(33, 397, 15), // "_BtnDMX_Clicked"
QT_MOC_LITERAL(34, 413, 26), // "_BtnFirmwareUpdate_Clicked"
QT_MOC_LITERAL(35, 440, 10), // "_DMXStream"
QT_MOC_LITERAL(36, 451, 23), // "on_BtnSearchDev_clicked"
QT_MOC_LITERAL(37, 475, 25), // "on_BtnWrThreshold_clicked"
QT_MOC_LITERAL(38, 501, 22), // "on_BtnWriteUID_clicked"
QT_MOC_LITERAL(39, 524, 29), // "on_BtnDeviceDiscovery_clicked"
QT_MOC_LITERAL(40, 554, 13), // "on_ActionUser"
QT_MOC_LITERAL(41, 568, 7), // "setUser"
QT_MOC_LITERAL(42, 576, 19), // "isAdministratorUser"
QT_MOC_LITERAL(43, 596, 30) // "on_DeviceTypeSelection_clicked"

    },
    "MainWindow\0showLoadingDialog\0\0"
    "hideLoadingDialog\0openSerialPort\0"
    "closeSerialPort\0about\0writeBreak\0"
    "writeData\0data\0readData\0_setBaudrate\0"
    "br\0handleError\0QSerialPort::SerialPortError\0"
    "error\0AdministratorTick_Handle\0"
    "_searchDevice\0_writeDMXID\0_writeSEQID\0"
    "_writeUID\0_setTestMode\0_showDMXRDMMessage\0"
    "message\0_DisplayDMXAddress\0DMXAdd\0"
    "_DisplayUIDAddress\0UID\0_DisplaySEQAddress\0"
    "SEQAdd\0_DisplayThreshold\0Max\0Min\0"
    "_BtnDMX_Clicked\0_BtnFirmwareUpdate_Clicked\0"
    "_DMXStream\0on_BtnSearchDev_clicked\0"
    "on_BtnWrThreshold_clicked\0"
    "on_BtnWriteUID_clicked\0"
    "on_BtnDeviceDiscovery_clicked\0"
    "on_ActionUser\0setUser\0isAdministratorUser\0"
    "on_DeviceTypeSelection_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  169,    2, 0x06 /* Public */,
       3,    0,  170,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  171,    2, 0x08 /* Private */,
       5,    0,  172,    2, 0x08 /* Private */,
       6,    0,  173,    2, 0x08 /* Private */,
       7,    0,  174,    2, 0x08 /* Private */,
       8,    1,  175,    2, 0x08 /* Private */,
      10,    0,  178,    2, 0x08 /* Private */,
      11,    1,  179,    2, 0x08 /* Private */,
      13,    1,  182,    2, 0x08 /* Private */,
      16,    0,  185,    2, 0x08 /* Private */,
      17,    0,  186,    2, 0x08 /* Private */,
      18,    0,  187,    2, 0x08 /* Private */,
      19,    0,  188,    2, 0x08 /* Private */,
      20,    0,  189,    2, 0x08 /* Private */,
      21,    0,  190,    2, 0x08 /* Private */,
      22,    1,  191,    2, 0x08 /* Private */,
      24,    1,  194,    2, 0x08 /* Private */,
      26,    1,  197,    2, 0x08 /* Private */,
      28,    1,  200,    2, 0x08 /* Private */,
      30,    2,  203,    2, 0x08 /* Private */,
      33,    0,  208,    2, 0x08 /* Private */,
      34,    0,  209,    2, 0x08 /* Private */,
      35,    0,  210,    2, 0x08 /* Private */,
      36,    0,  211,    2, 0x08 /* Private */,
      37,    0,  212,    2, 0x08 /* Private */,
      38,    0,  213,    2, 0x08 /* Private */,
      39,    0,  214,    2, 0x08 /* Private */,
      40,    0,  215,    2, 0x08 /* Private */,
      41,    1,  216,    2, 0x08 /* Private */,
      43,    0,  219,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::UShort,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::UShort,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   31,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   42,
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
        case 2: _t->openSerialPort(); break;
        case 3: _t->closeSerialPort(); break;
        case 4: _t->about(); break;
        case 5: _t->writeBreak(); break;
        case 6: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->readData(); break;
        case 8: _t->_setBaudrate((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 9: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 10: _t->AdministratorTick_Handle(); break;
        case 11: _t->_searchDevice(); break;
        case 12: _t->_writeDMXID(); break;
        case 13: _t->_writeSEQID(); break;
        case 14: _t->_writeUID(); break;
        case 15: _t->_setTestMode(); break;
        case 16: _t->_showDMXRDMMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->_DisplayDMXAddress((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 18: _t->_DisplayUIDAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->_DisplaySEQAddress((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 20: _t->_DisplayThreshold((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: _t->_BtnDMX_Clicked(); break;
        case 22: _t->_BtnFirmwareUpdate_Clicked(); break;
        case 23: _t->_DMXStream(); break;
        case 24: _t->on_BtnSearchDev_clicked(); break;
        case 25: _t->on_BtnWrThreshold_clicked(); break;
        case 26: _t->on_BtnWriteUID_clicked(); break;
        case 27: _t->on_BtnDeviceDiscovery_clicked(); break;
        case 28: _t->on_ActionUser(); break;
        case 29: _t->setUser((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_DeviceTypeSelection_clicked(); break;
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 31;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
