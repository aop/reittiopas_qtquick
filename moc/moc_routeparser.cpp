/****************************************************************************
** Meta object code from reading C++ file 'routeparser.h'
**
** Created: Sat 10. Mar 08:42:04 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../routeparser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'routeparser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RouteParser[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   47,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RouteParser[] = {
    "RouteParser\0\0list\0routesParsed(QList<Route*>*)\0"
    "r\0parseResponse(QNetworkReply*)\0"
};

const QMetaObject RouteParser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RouteParser,
      qt_meta_data_RouteParser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RouteParser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RouteParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RouteParser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RouteParser))
        return static_cast<void*>(const_cast< RouteParser*>(this));
    return QObject::qt_metacast(_clname);
}

int RouteParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: routesParsed((*reinterpret_cast< QList<Route*>*(*)>(_a[1]))); break;
        case 1: parseResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RouteParser::routesParsed(QList<Route*> * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
