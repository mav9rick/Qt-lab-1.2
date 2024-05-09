/****************************************************************************
** Meta object code from reading C++ file 'logger.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../logger.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSloggerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSloggerENDCLASS = QtMocHelpers::stringData(
    "logger",
    "createS",
    "",
    "deleteS",
    "starttimerS",
    "stoptimerS",
    "exitS",
    "addfileS",
    "removefileS",
    "readS",
    "userinput",
    "input",
    "changefileS",
    "listS"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSloggerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,
       4,    0,   82,    2, 0x06,    3 /* Public */,
       5,    0,   83,    2, 0x06,    4 /* Public */,
       6,    0,   84,    2, 0x06,    5 /* Public */,
       7,    0,   85,    2, 0x06,    6 /* Public */,
       8,    0,   86,    2, 0x06,    7 /* Public */,
       9,    0,   87,    2, 0x06,    8 /* Public */,
      10,    1,   88,    2, 0x06,    9 /* Public */,
      12,    0,   91,    2, 0x06,   11 /* Public */,
      13,    0,   92,    2, 0x06,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject logger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSloggerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSloggerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSloggerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<logger, std::true_type>,
        // method 'createS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'starttimerS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stoptimerS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exitS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addfileS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removefileS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'userinput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'changefileS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'listS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void logger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<logger *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->createS(); break;
        case 1: _t->deleteS(); break;
        case 2: _t->starttimerS(); break;
        case 3: _t->stoptimerS(); break;
        case 4: _t->exitS(); break;
        case 5: _t->addfileS(); break;
        case 6: _t->removefileS(); break;
        case 7: _t->readS(); break;
        case 8: _t->userinput((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->changefileS(); break;
        case 10: _t->listS(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::createS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::deleteS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::starttimerS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::stoptimerS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::exitS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::addfileS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::removefileS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::readS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (logger::*)(QString );
            if (_t _q_method = &logger::userinput; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::changefileS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (logger::*)();
            if (_t _q_method = &logger::listS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject *logger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *logger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSloggerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int logger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void logger::createS()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void logger::deleteS()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void logger::starttimerS()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void logger::stoptimerS()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void logger::exitS()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void logger::addfileS()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void logger::removefileS()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void logger::readS()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void logger::userinput(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void logger::changefileS()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void logger::listS()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
