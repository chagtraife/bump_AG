/****************************************************************************
** Meta object code from reading C++ file 'WindDMXConverter_Setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AG/WindDMXConverter_Setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindDMXConverter_Setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindDMXConverter_Setting_t {
    QByteArrayData data[11];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindDMXConverter_Setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindDMXConverter_Setting_t qt_meta_stringdata_WindDMXConverter_Setting = {
    {
QT_MOC_LITERAL(0, 0, 24), // "WindDMXConverter_Setting"
QT_MOC_LITERAL(1, 25, 19), // "customMenuRequested"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 3), // "pos"
QT_MOC_LITERAL(4, 50, 12), // "on_SelectAll"
QT_MOC_LITERAL(5, 63, 12), // "on_SelectOdd"
QT_MOC_LITERAL(6, 76, 13), // "on_SelectEven"
QT_MOC_LITERAL(7, 90, 14), // "on_ChangeValue"
QT_MOC_LITERAL(8, 105, 21), // "on_Btn_Cancel_clicked"
QT_MOC_LITERAL(9, 127, 26), // "on_Btn_ReadFromDev_clicked"
QT_MOC_LITERAL(10, 154, 25) // "on_Btn_WriteToDev_clicked"

    },
    "WindDMXConverter_Setting\0customMenuRequested\0"
    "\0pos\0on_SelectAll\0on_SelectOdd\0"
    "on_SelectEven\0on_ChangeValue\0"
    "on_Btn_Cancel_clicked\0on_Btn_ReadFromDev_clicked\0"
    "on_Btn_WriteToDev_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindDMXConverter_Setting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WindDMXConverter_Setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindDMXConverter_Setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->customMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->on_SelectAll(); break;
        case 2: _t->on_SelectOdd(); break;
        case 3: _t->on_SelectEven(); break;
        case 4: _t->on_ChangeValue(); break;
        case 5: _t->on_Btn_Cancel_clicked(); break;
        case 6: _t->on_Btn_ReadFromDev_clicked(); break;
        case 7: _t->on_Btn_WriteToDev_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WindDMXConverter_Setting::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_WindDMXConverter_Setting.data,
    qt_meta_data_WindDMXConverter_Setting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindDMXConverter_Setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindDMXConverter_Setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindDMXConverter_Setting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int WindDMXConverter_Setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
