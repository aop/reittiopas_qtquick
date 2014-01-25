/****************************************************************************
** Meta object code from reading C++ file 'addressparser.h'
**
** Created: Sat 10. Mar 08:42:01 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addressparser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addressparser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddressContainer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_AddressContainer[] = {
    "AddressContainer\0"
};

const QMetaObject AddressContainer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AddressContainer,
      qt_meta_data_AddressContainer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddressContainer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddressContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddressContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddressContainer))
        return static_cast<void*>(const_cast< AddressContainer*>(this));
    return QObject::qt_metacast(_clname);
}

int AddressContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_addressParser[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x05,
      77,   67,   14,   14, 0x05,
     132,  127,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     153,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_addressParser[] = {
    "addressParser\0\0addr,type\0"
    "parsedResponse(AddressContainer*,QString)\0"
    "list,type\0multipleChoises(QList<AddressContainer*>,QString)\0"
    "type\0parsedEmpty(QString)\0"
    "parseResponse(QNetworkReply*)\0"
};

const QMetaObject addressParser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_addressParser,
      qt_meta_data_addressParser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &addressParser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *addressParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *addressParser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addressParser))
        return static_cast<void*>(const_cast< addressParser*>(this));
    return QObject::qt_metacast(_clname);
}

int addressParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: parsedResponse((*reinterpret_cast< AddressContainer*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: multipleChoises((*reinterpret_cast< QList<AddressContainer*>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: parsedEmpty((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: parseResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void addressParser::parsedResponse(AddressContainer * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void addressParser::multipleChoises(QList<AddressContainer*> _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void addressParser::parsedEmpty(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
static const uint qt_meta_data_AddressList[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      24,   17,   13,   12, 0x02,
      66,   55,   46,   12, 0x02,
     108,  102,   88,   12, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_AddressList[] = {
    "AddressList\0\0int\0parent\0rowCount(QModelIndex)\0"
    "QVariant\0index,role\0data(QModelIndex,int)\0"
    "Qt::ItemFlags\0index\0flags(QModelIndex)\0"
};

const QMetaObject AddressList::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_AddressList,
      qt_meta_data_AddressList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddressList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddressList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddressList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddressList))
        return static_cast<void*>(const_cast< AddressList*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int AddressList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = rowCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { QVariant _r = data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 2: { Qt::ItemFlags _r = flags((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::ItemFlags*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
