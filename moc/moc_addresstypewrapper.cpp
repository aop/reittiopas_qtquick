/****************************************************************************
** Meta object code from reading C++ file 'addresstypewrapper.h'
**
** Created: Sat 18. Feb 21:35:21 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addresstypewrapper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addresstypewrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addressTypeWrapper[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
      19, 0x0,    2,   18,

 // enum data: key, value
      36, uint(addressTypeWrapper::FROMADDRESS),
      48, uint(addressTypeWrapper::TOADDRESS),

       0        // eod
};

static const char qt_meta_stringdata_addressTypeWrapper[] = {
    "addressTypeWrapper\0addressQueryType\0"
    "FROMADDRESS\0TOADDRESS\0"
};

const QMetaObject addressTypeWrapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_addressTypeWrapper,
      qt_meta_data_addressTypeWrapper, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &addressTypeWrapper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *addressTypeWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *addressTypeWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addressTypeWrapper))
        return static_cast<void*>(const_cast< addressTypeWrapper*>(this));
    return QObject::qt_metacast(_clname);
}

int addressTypeWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
