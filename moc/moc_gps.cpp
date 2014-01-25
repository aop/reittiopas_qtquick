/****************************************************************************
** Meta object code from reading C++ file 'gps.h'
**
** Created: Sat 10. Mar 08:41:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gps.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gps.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GPS[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    5,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,    4,    4,    4, 0x0a,
      79,    4,   74,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GPS[] = {
    "GPS\0\0lon,lat\0gotPosition(double,double)\0"
    "positionUpdated(QGeoPositionInfo)\0"
    "bool\0startPositioning()\0"
};

const QMetaObject GPS::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GPS,
      qt_meta_data_GPS, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPS))
        return static_cast<void*>(const_cast< GPS*>(this));
    return QObject::qt_metacast(_clname);
}

int GPS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gotPosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: positionUpdated((*reinterpret_cast< QGeoPositionInfo(*)>(_a[1]))); break;
        case 2: { bool _r = startPositioning();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GPS::gotPosition(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
