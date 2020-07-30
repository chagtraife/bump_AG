/****************************************************************************
** Meta object code from reading C++ file 'thresholdmanagersetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AG/thresholdmanagersetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thresholdmanagersetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThresholdManagerSetting_t {
    QByteArrayData data[5];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThresholdManagerSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThresholdManagerSetting_t qt_meta_stringdata_ThresholdManagerSetting = {
    {
QT_MOC_LITERAL(0, 0, 23), // "ThresholdManagerSetting"
QT_MOC_LITERAL(1, 24, 27), // "ShowThresholdManagerSetting"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 20), // "on_btnSetMin_clicked"
QT_MOC_LITERAL(4, 74, 20) // "on_btnSetMax_clicked"

    },
    "ThresholdManagerSetting\0"
    "ShowThresholdManagerSetting\0\0"
    "on_btnSetMin_clicked\0on_btnSetMax_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThresholdManagerSetting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ThresholdManagerSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThresholdManagerSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowThresholdManagerSetting(); break;
        case 1: _t->on_btnSetMin_clicked(); break;
        case 2: _t->on_btnSetMax_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ThresholdManagerSetting::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ThresholdManagerSetting.data,
    qt_meta_data_ThresholdManagerSetting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThresholdManagerSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThresholdManagerSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThresholdManagerSetting.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Authen"))
        return static_cast< Authen*>(this);
    return QDialog::qt_metacast(_clname);
}

int ThresholdManagerSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
