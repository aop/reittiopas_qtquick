/****************************************************************************
** Meta object code from reading C++ file 'route.h'
**
** Created: Sat 10. Mar 08:42:08 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../route.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'route.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Route[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       8,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      14,    6, 0x0a095001,
      24,    6, 0x0a095001,
      37,    6, 0x0a095001,
      48,    6, 0x0a095001,
      62,    6, 0x0a095001,
      70,    6, 0x0a095001,
      79,    6, 0x0a095001,
     117,   87, 0x00095009,

       0        // eod
};

static const char qt_meta_stringdata_Route[] = {
    "Route\0QString\0leavewalk\0leavevehicle\0"
    "walklength\0wholeduration\0arrTime\0"
    "startLoc\0stopLoc\0QDeclarativeListProperty<Leg>\0"
    "routelegs\0"
};

const QMetaObject Route::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Route,
      qt_meta_data_Route, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Route::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Route::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Route::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Route))
        return static_cast<void*>(const_cast< Route*>(this));
    return QObject::qt_metacast(_clname);
}

int Route::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = leavewalk(); break;
        case 1: *reinterpret_cast< QString*>(_v) = leavevehicle(); break;
        case 2: *reinterpret_cast< QString*>(_v) = walklength(); break;
        case 3: *reinterpret_cast< QString*>(_v) = wholeduration(); break;
        case 4: *reinterpret_cast< QString*>(_v) = arrTime(); break;
        case 5: *reinterpret_cast< QString*>(_v) = startLoc(); break;
        case 6: *reinterpret_cast< QString*>(_v) = stopLoc(); break;
        case 7: *reinterpret_cast< QDeclarativeListProperty<Leg>*>(_v) = getlegs(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
