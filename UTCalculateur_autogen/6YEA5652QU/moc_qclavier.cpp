/****************************************************************************
** Meta object code from reading C++ file 'qclavier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/qclavier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qclavier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QClavier_t {
    QByteArrayData data[10];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QClavier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QClavier_t qt_meta_stringdata_QClavier = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QClavier"
QT_MOC_LITERAL(1, 9, 12), // "digitClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "addTextClicked"
QT_MOC_LITERAL(4, 38, 13), // "deleteClicked"
QT_MOC_LITERAL(5, 52, 21), // "simpleOperatorClicked"
QT_MOC_LITERAL(6, 74, 20), // "unaryOperatorClicked"
QT_MOC_LITERAL(7, 95, 12), // "enterClicked"
QT_MOC_LITERAL(8, 108, 23), // "calculerOperateurSimple"
QT_MOC_LITERAL(9, 132, 2) // "op"

    },
    "QClavier\0digitClicked\0\0addTextClicked\0"
    "deleteClicked\0simpleOperatorClicked\0"
    "unaryOperatorClicked\0enterClicked\0"
    "calculerOperateurSimple\0op"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QClavier[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    9,

       0        // eod
};

void QClavier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QClavier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->digitClicked(); break;
        case 1: _t->addTextClicked(); break;
        case 2: _t->deleteClicked(); break;
        case 3: _t->simpleOperatorClicked(); break;
        case 4: _t->unaryOperatorClicked(); break;
        case 5: _t->enterClicked(); break;
        case 6: { bool _r = _t->calculerOperateurSimple((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QClavier::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QClavier.data,
    qt_meta_data_QClavier,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QClavier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QClavier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QClavier.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QClavier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
