/****************************************************************************
** Meta object code from reading C++ file 'leg.h'
**
** Created: Sat 10. Mar 08:42:02 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../leg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'leg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Leg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      12,    4, 0x0a095001,
      17,    4, 0x0a095001,
      25,    4, 0x0a095001,
      35,    4, 0x0a095001,
      44,    4, 0x0a095001,
      53,    4, 0x0a095001,
      94,   61, 0x00095009,

       0        // eod
};

static const char qt_meta_stringdata_Leg[] = {
    "Leg\0QString\0type\0vehicle\0startTime\0"
    "stopTime\0startLoc\0stopLoc\0"
    "QDeclarativeListProperty<LegLoc>\0"
    "routelegs\0"
};

const QMetaObject Leg::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Leg,
      qt_meta_data_Leg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Leg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Leg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Leg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Leg))
        return static_cast<void*>(const_cast< Leg*>(this));
    return QObject::qt_metacast(_clname);
}

int Leg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = typeofleg(); break;
        case 1: *reinterpret_cast< QString*>(_v) = vehicle(); break;
        case 2: *reinterpret_cast< QString*>(_v) = startTime(); break;
        case 3: *reinterpret_cast< QString*>(_v) = stopTime(); break;
        case 4: *reinterpret_cast< QString*>(_v) = startLoc(); break;
        case 5: *reinterpret_cast< QString*>(_v) = stopLoc(); break;
        case 6: *reinterpret_cast< QDeclarativeListProperty<LegLoc>*>(_v) = getlegs(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
