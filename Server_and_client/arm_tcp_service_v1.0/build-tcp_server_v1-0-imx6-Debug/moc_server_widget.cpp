/****************************************************************************
** Meta object code from reading C++ file 'server_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcp_server_v1-0/server_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Server_Widget_t {
    QByteArrayData data[8];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_Widget_t qt_meta_stringdata_Server_Widget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Server_Widget"
QT_MOC_LITERAL(1, 14, 10), // "Value_Init"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "Server_start"
QT_MOC_LITERAL(4, 39, 9), // "netconfig"
QT_MOC_LITERAL(5, 49, 4), // "exit"
QT_MOC_LITERAL(6, 54, 7), // "offline"
QT_MOC_LITERAL(7, 62, 7) // "process"

    },
    "Server_Widget\0Value_Init\0\0Server_start\0"
    "netconfig\0exit\0offline\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Server_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server_Widget *_t = static_cast<Server_Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Value_Init(); break;
        case 1: _t->Server_start(); break;
        case 2: _t->netconfig(); break;
        case 3: _t->exit(); break;
        case 4: _t->offline(); break;
        case 5: _t->process(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Server_Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Server_Widget.data,
      qt_meta_data_Server_Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Server_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Server_Widget.stringdata0))
        return static_cast<void*>(const_cast< Server_Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Server_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
