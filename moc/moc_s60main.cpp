/****************************************************************************
** Meta object code from reading C++ file 's60main.h'
**
** Created: Sat 24. Mar 15:07:36 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../s60main.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's60main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_S60Main[] = {

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

 // slots: signature, parameters, type, tag, flags
      14,    9,    8,    8, 0x0a,
      44,   31,    8,    8, 0x0a,
      80,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_S60Main[] = {
    "S60Main\0\0page\0setPage(QString)\0"
    "typeofsignal\0multipleChoisesForLocation(QString)\0"
    "queryingRoutes()\0"
};

const QMetaObject S60Main::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_S60Main,
      qt_meta_data_S60Main, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &S60Main::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *S60Main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *S60Main::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_S60Main))
        return static_cast<void*>(const_cast< S60Main*>(this));
    return QWidget::qt_metacast(_clname);
}

int S60Main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: multipleChoisesForLocation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: queryingRoutes(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
