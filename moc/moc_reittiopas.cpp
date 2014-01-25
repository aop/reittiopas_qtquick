/****************************************************************************
** Meta object code from reading C++ file 'reittiopas.h'
**
** Created: Sat 24. Mar 15:07:34 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../reittiopas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reittiopas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Reittiopas[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       3,  179, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x05,
      40,   11,   11,   11, 0x05,
      68,   55,   11,   11, 0x05,
     110,   11,   11,   11, 0x05,
     122,   11,   11,   11, 0x05,
     139,   11,   11,   11, 0x05,
     166,  161,   11,   11, 0x05,
     200,   11,   11,   11, 0x05,
     222,   11,   11,   11, 0x05,
     240,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     264,  256,   11,   11, 0x0a,
     312,  299,   11,   11, 0x0a,
     380,  342,   11,   11, 0x0a,
     454,  421,   11,   11, 0x2a,
     509,  487,   11,   11, 0x2a,
     547,  537,   11,   11, 0x0a,
     609,  599,   11,   11, 0x0a,
     679,  670,   11,   11, 0x0a,
     716,   11,   11,   11, 0x0a,
     755,  742,   11,   11, 0x0a,
     784,   11,   11,   11, 0x0a,
     801,   11,   11,   11, 0x0a,
     848,  829,   11,   11, 0x0a,
     886,  880,   11,   11, 0x08,
     967,  929,   11,   11, 0x08,
    1047, 1019,   11,   11, 0x28,

 // methods: signature, parameters, type, tag, flags
    1107,   11, 1094,   11, 0x02,
    1157,   11, 1132,   11, 0x02,
    1186,   11, 1179,   11, 0x02,
    1237, 1233, 1203,   11, 0x02,
    1275, 1259, 1247,   11, 0x02,
    1314,   12, 1309,   11, 0x02,
    1345, 1337,   11,   11, 0x02,

 // properties: name, type, flags
    1402, 1370, 0x00095009,
    1417, 1409, 0x0a495001,
    1426, 1409, 0x0a495001,

 // properties: notify_signal_id
       0,
       8,
       9,

       0        // eod
};

static const char qt_meta_stringdata_Reittiopas[] = {
    "Reittiopas\0\0address\0gotAddress(QString)\0"
    "gotMyAddress()\0typeofsignal\0"
    "multipleChoicesForLocationSignal(QString)\0"
    "gotRoutes()\0queryingRoutes()\0"
    "queryingShiftRoutes()\0type\0"
    "parsedGeocodeEmptySignal(QString)\0"
    "reverseGeocodeError()\0fromNameChanged()\0"
    "toNameChanged()\0lon,lat\0"
    "reverseGeocodeQuery(double,double)\0"
    "address,type\0addressQuery(QString,QString)\0"
    "fromAddress,toAddress,departBool,time\0"
    "routeQuery(QString,QString,bool,QString)\0"
    "fromAddress,toAddress,departBool\0"
    "routeQuery(QString,QString,bool)\0"
    "fromAddress,toAddress\0routeQuery(QString,QString)\0"
    "addr,type\0parsedGeocodeFromAddress(AddressContainer*,QString)\0"
    "list,type\0"
    "multipleChoicesForLocation(QList<AddressContainer*>,QString)\0"
    "idx,type\0multipleChoicesSelected(int,QString)\0"
    "multipleChoicesRejected()\0listOfRoutes\0"
    "routesParsed(QList<Route*>*)\0"
    "cancelLocation()\0parsedGeocodeEmpty(QString)\0"
    "type,searchAddress\0useValueFromDb(QString,QString)\0"
    "reply\0parseReverseGeocodeRequest(QNetworkReply*)\0"
    "fromLon,fromLat,toLon,toLat,timeShift\0"
    "routeQueryPrivate(double,double,double,double,bool)\0"
    "fromLon,fromLat,toLon,toLat\0"
    "routeQueryPrivate(double,double,double,double)\0"
    "AddressList*\0getPossibleList(QString)\0"
    "QList<AddressContainer*>\0getPossibleListFrom()\0"
    "Route*\0testloadRoutes()\0"
    "QDeclarativeListProperty<Leg>\0idx\0"
    "legs(int)\0QStringList\0type,startswith\0"
    "getMatchingNames(QString,QString)\0"
    "bool\0deleteAddress(QString)\0minutes\0"
    "timeshiftRouteQuery(int)\0"
    "QDeclarativeListProperty<Route>\0routes\0"
    "QString\0fromName\0toName\0"
};

const QMetaObject Reittiopas::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_Reittiopas,
      qt_meta_data_Reittiopas, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Reittiopas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Reittiopas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Reittiopas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Reittiopas))
        return static_cast<void*>(const_cast< Reittiopas*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int Reittiopas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gotAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: gotMyAddress(); break;
        case 2: multipleChoicesForLocationSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: gotRoutes(); break;
        case 4: queryingRoutes(); break;
        case 5: queryingShiftRoutes(); break;
        case 6: parsedGeocodeEmptySignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: reverseGeocodeError(); break;
        case 8: fromNameChanged(); break;
        case 9: toNameChanged(); break;
        case 10: reverseGeocodeQuery((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 11: addressQuery((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: routeQuery((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 13: routeQuery((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 14: routeQuery((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: parsedGeocodeFromAddress((*reinterpret_cast< AddressContainer*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: multipleChoicesForLocation((*reinterpret_cast< QList<AddressContainer*>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: multipleChoicesSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 18: multipleChoicesRejected(); break;
        case 19: routesParsed((*reinterpret_cast< QList<Route*>*(*)>(_a[1]))); break;
        case 20: cancelLocation(); break;
        case 21: parsedGeocodeEmpty((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: useValueFromDb((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 23: parseReverseGeocodeRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 24: routeQueryPrivate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 25: routeQueryPrivate((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 26: { AddressList* _r = getPossibleList((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< AddressList**>(_a[0]) = _r; }  break;
        case 27: { QList<AddressContainer*> _r = getPossibleListFrom();
            if (_a[0]) *reinterpret_cast< QList<AddressContainer*>*>(_a[0]) = _r; }  break;
        case 28: { Route* _r = testloadRoutes();
            if (_a[0]) *reinterpret_cast< Route**>(_a[0]) = _r; }  break;
        case 29: { QDeclarativeListProperty<Leg> _r = legs((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDeclarativeListProperty<Leg>*>(_a[0]) = _r; }  break;
        case 30: { QStringList _r = getMatchingNames((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 31: { bool _r = deleteAddress((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 32: timeshiftRouteQuery((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 33;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeListProperty<Route>*>(_v) = routes(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getFromName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getToName(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Reittiopas::gotAddress(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Reittiopas::gotMyAddress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Reittiopas::multipleChoicesForLocationSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Reittiopas::gotRoutes()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Reittiopas::queryingRoutes()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Reittiopas::queryingShiftRoutes()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Reittiopas::parsedGeocodeEmptySignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Reittiopas::reverseGeocodeError()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Reittiopas::fromNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Reittiopas::toNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
