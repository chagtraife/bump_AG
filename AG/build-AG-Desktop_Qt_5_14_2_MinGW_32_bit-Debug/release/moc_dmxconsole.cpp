/****************************************************************************
** Meta object code from reading C++ file 'dmxconsole.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AG/dmxconsole.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dmxconsole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DMXconsole_t {
    QByteArrayData data[16];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DMXconsole_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DMXconsole_t qt_meta_stringdata_DMXconsole = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DMXconsole"
QT_MOC_LITERAL(1, 11, 10), // "DMXTriggle"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "signal_close"
QT_MOC_LITERAL(4, 36, 23), // "BtnDMXStreaming_Clicked"
QT_MOC_LITERAL(5, 60, 7), // "DMXTick"
QT_MOC_LITERAL(6, 68, 16), // "_updateLb_value0"
QT_MOC_LITERAL(7, 85, 3), // "val"
QT_MOC_LITERAL(8, 89, 14), // "_syncDMXBuffer"
QT_MOC_LITERAL(9, 104, 5), // "index"
QT_MOC_LITERAL(10, 110, 22), // "_chk_SelectAll_Changed"
QT_MOC_LITERAL(11, 133, 12), // "FocusChanged"
QT_MOC_LITERAL(12, 146, 3), // "dir"
QT_MOC_LITERAL(13, 150, 10), // "closeEvent"
QT_MOC_LITERAL(14, 161, 12), // "QCloseEvent*"
QT_MOC_LITERAL(15, 174, 5) // "event"

    },
    "DMXconsole\0DMXTriggle\0\0signal_close\0"
    "BtnDMXStreaming_Clicked\0DMXTick\0"
    "_updateLb_value0\0val\0_syncDMXBuffer\0"
    "index\0_chk_SelectAll_Changed\0FocusChanged\0"
    "dir\0closeEvent\0QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DMXconsole[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    1,   70,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void DMXconsole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DMXconsole *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DMXTriggle(); break;
        case 1: _t->signal_close(); break;
        case 2: _t->BtnDMXStreaming_Clicked(); break;
        case 3: _t->DMXTick(); break;
        case 4: _t->_updateLb_value0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->_syncDMXBuffer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->_chk_SelectAll_Changed(); break;
        case 7: _t->FocusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DMXconsole::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXconsole::DMXTriggle)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DMXconsole::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMXconsole::signal_close)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DMXconsole::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DMXconsole.data,
    qt_meta_data_DMXconsole,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DMXconsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DMXconsole::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DMXconsole.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DMXconsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DMXconsole::DMXTriggle()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DMXconsole::signal_close()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
