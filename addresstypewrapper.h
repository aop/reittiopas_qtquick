#ifndef SIGNALTYPEWRAPPER_H
#define SIGNALTYPEWRAPPER_H

#include <QObject>

class addressTypeWrapper : public QObject
{
    Q_OBJECT
    Q_ENUMS(addressQueryType)
public:
    enum addressQueryType{
        FROMADDRESS,
        TOADDRESS
    };

    explicit addressTypeWrapper(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // SIGNALTYPEWRAPPER_H
