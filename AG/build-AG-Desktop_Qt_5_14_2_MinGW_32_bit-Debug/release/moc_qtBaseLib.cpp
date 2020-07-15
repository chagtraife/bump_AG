/****************************************************************************
** Meta object code from reading C++ file 'qtBaseLib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AG/qtBaseLib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtBaseLib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DMXRDM_t {
    QByteArrayData data[26];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DMXRDM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DMXRDM_t qt_meta_stringdata_DMXRDM = {
    {
QT_MOC_LITERAL(0, 0, 6), // "DMXRDM"
QT_MOC_LITERAL(1, 7, 11), // "showMessage"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "message"
QT_MOC_LITERAL(4, 28, 14), // "displayDMXAddr"
QT_MOC_LITERAL(5, 43, 7), // "DMXAddr"
QT_MOC_LITERAL(6, 51, 14), // "displaySEQAddr"
QT_MOC_LITERAL(7, 66, 7), // "SEQAddr"
QT_MOC_LITERAL(8, 74, 10), // "displayUID"
QT_MOC_LITERAL(9, 85, 7), // "dispUID"
QT_MOC_LITERAL(10, 93, 16), // "displayThreshold"
QT_MOC_LITERAL(11, 110, 3), // "Max"
QT_MOC_LITERAL(12, 114, 3), // "Min"
QT_MOC_LITERAL(13, 118, 9), // "sendBreak"
QT_MOC_LITERAL(14, 128, 9), // "sendFrame"
QT_MOC_LITERAL(15, 138, 4), // "data"
QT_MOC_LITERAL(16, 143, 11), // "setBaudrate"
QT_MOC_LITERAL(17, 155, 2), // "br"
QT_MOC_LITERAL(18, 158, 9), // "ClosePort"
QT_MOC_LITERAL(19, 168, 15), // "DiscFoundDevice"
QT_MOC_LITERAL(20, 184, 8), // "FoundUID"
QT_MOC_LITERAL(21, 193, 17), // "DiscScannedDevice"
QT_MOC_LITERAL(22, 211, 10), // "ScannedUID"
QT_MOC_LITERAL(23, 222, 7), // "SetUser"
QT_MOC_LITERAL(24, 230, 15), // "isAdministrator"
QT_MOC_LITERAL(25, 246, 11) // "ReadRxFrame"

    },
    "DMXRDM\0showMessage\0\0message\0displayDMXAddr\0"
    "DMXAddr\0displaySEQAddr\0SEQAddr\0"
    "displayUID\0dispUID\0displayThreshold\0"
    "Max\0Min\0sendBreak\0sendFrame\0data\0"
    "setBaudrate\0br\0ClosePort\0DiscFoundDevice\0"
    "FoundUID\0DiscScannedDevice\0ScannedUID\0"
    "SetUser\0isAdministrator\0ReadRxFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DMXRDM[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    1,   85,    2, 0x06 /* Public */,
       8,    1,   88,    2, 0x06 /* Public */,
      10,    2,   91,    2, 0x06 /* Public */,
      13,    0,   96,    2, 0x06 /* Public */,
      14,    1,   97,    2, 0x06 /* Public */,
      16,    1,  100,    2, 0x06 /* Public */,
      18,    0,  103,    2, 0x06 /* Public */,
      19,    1,  104,    2, 0x06 /* Public */,
      21,    1,  107,    2, 0x06 /* Public */,
      23,    1,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::UShort,    5,
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   15,
    QMetaType::Void, QMetaType::UInt,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Bool,   24,

 // slots: parameters
    QMetaType::UChar,

       0        // eod
};

void DMXRDM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DMXRDM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->displayDMXAddr((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 2: _t->displaySEQAddr((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->displayUID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->displayThreshold((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->sendBreak(); break;
        case 6: _t->sendFrame((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->setBaudrate((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 8: _t->ClosePort(); break;
        case 9: _t->DiscFoundDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->DiscScannedDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->SetUser((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: { quint8 _r = _t->ReadRxFrame();
            if (_a[0]) *reinterpret_cast< quint8*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DMXRDM::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::showMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::displayDMXAddr)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::displaySEQAddr)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::displayUID)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::displayThreshold)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::sendBreak)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::sendFrame)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::setBaudrate)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::ClosePort)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::DiscFoundDevice)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::DiscScannedDevice)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (DMXRDM::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXRDM::SetUser)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DMXRDM::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlainTextEdit::staticMetaObject>(),
    qt_meta_stringdata_DMXRDM.data,
    qt_meta_data_DMXRDM,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DMXRDM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DMXRDM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DMXRDM.stringdata0))
        return static_cast<void*>(this);
    return QPlainTextEdit::qt_metacast(_clname);
}

int DMXRDM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void DMXRDM::showMessage(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DMXRDM::displayDMXAddr(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DMXRDM::displaySEQAddr(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DMXRDM::displayUID(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DMXRDM::displayThreshold(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DMXRDM::sendBreak()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DMXRDM::sendFrame(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DMXRDM::setBaudrate(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DMXRDM::ClosePort()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void DMXRDM::DiscFoundDevice(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void DMXRDM::DiscScannedDevice(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void DMXRDM::SetUser(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
