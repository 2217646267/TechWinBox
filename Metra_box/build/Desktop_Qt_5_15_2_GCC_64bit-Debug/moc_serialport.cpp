/****************************************************************************
** Meta object code from reading C++ file 'serialport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serialport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPort_t {
    QByteArrayData data[25];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPort_t qt_meta_stringdata_SerialPort = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SerialPort"
QT_MOC_LITERAL(1, 11, 9), // "connected"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "portName"
QT_MOC_LITERAL(4, 31, 5), // "error"
QT_MOC_LITERAL(5, 37, 9), // "errorType"
QT_MOC_LITERAL(6, 47, 11), // "errorString"
QT_MOC_LITERAL(7, 59, 12), // "disconnected"
QT_MOC_LITERAL(8, 72, 4), // "read"
QT_MOC_LITERAL(9, 77, 4), // "data"
QT_MOC_LITERAL(10, 82, 6), // "status"
QT_MOC_LITERAL(11, 89, 3), // "msg"
QT_MOC_LITERAL(12, 93, 4), // "open"
QT_MOC_LITERAL(13, 98, 8), // "baudRate"
QT_MOC_LITERAL(14, 107, 5), // "close"
QT_MOC_LITERAL(15, 113, 8), // "readData"
QT_MOC_LITERAL(16, 122, 11), // "handleError"
QT_MOC_LITERAL(17, 134, 9), // "writeData"
QT_MOC_LITERAL(18, 144, 6), // "direct"
QT_MOC_LITERAL(19, 151, 3), // "str"
QT_MOC_LITERAL(20, 155, 11), // "const char*"
QT_MOC_LITERAL(21, 167, 5), // "xdata"
QT_MOC_LITERAL(22, 173, 3), // "len"
QT_MOC_LITERAL(23, 177, 11), // "onReadyRead"
QT_MOC_LITERAL(24, 189, 12) // "onSendTmrout"

    },
    "SerialPort\0connected\0\0portName\0error\0"
    "errorType\0errorString\0disconnected\0"
    "read\0data\0status\0msg\0open\0baudRate\0"
    "close\0readData\0handleError\0writeData\0"
    "direct\0str\0const char*\0xdata\0len\0"
    "onReadyRead\0onSendTmrout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    3,  102,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    1,  110,    2, 0x06 /* Public */,
      10,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,  116,    2, 0x0a /* Public */,
      12,    1,  121,    2, 0x2a /* Public | MethodCloned */,
      12,    0,  124,    2, 0x2a /* Public | MethodCloned */,
      14,    0,  125,    2, 0x0a /* Public */,
      15,    0,  126,    2, 0x0a /* Public */,
      16,    0,  127,    2, 0x0a /* Public */,
      17,    2,  128,    2, 0x0a /* Public */,
      17,    1,  133,    2, 0x2a /* Public | MethodCloned */,
      17,    1,  136,    2, 0x0a /* Public */,
      17,    2,  139,    2, 0x0a /* Public */,
      23,    0,  144,    2, 0x08 /* Private */,
      24,    0,  145,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    3,   13,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::QByteArray,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    9,   18,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Int,   21,   22,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->disconnected(); break;
        case 3: _t->read((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->status((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { bool _r = _t->open((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->open((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->open();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->close(); break;
        case 9: { QByteArray _r = _t->readData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->handleError(); break;
        case 11: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 13: _t->writeData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->writeData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->onReadyRead(); break;
        case 16: _t->onSendTmrout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialPort::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)(QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::disconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::read)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SerialPort::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort::status)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SerialPort.data,
    qt_meta_data_SerialPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPort.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void SerialPort::connected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPort::error(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialPort::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SerialPort::read(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialPort::status(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
