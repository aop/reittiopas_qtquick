#ifndef LEG_H
#define LEG_H

#include <QObject>
#include "legloc.h"
#include <QDebug>
#include <QDeclarativeListProperty>

class Leg : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString type READ typeofleg)
    Q_PROPERTY(QString vehicle READ vehicle)
    Q_PROPERTY(QString startTime READ startTime)
    Q_PROPERTY(QString stopTime READ stopTime)
    Q_PROPERTY(QString startLoc READ startLoc)
    Q_PROPERTY(QString stopLoc READ stopLoc)
    Q_PROPERTY(QDeclarativeListProperty<LegLoc> routelegs READ getlegs)

public:
    explicit Leg(double length, double duration,QString type, QString code, QList<LegLoc*> *list = new QList<LegLoc*>(), QObject *parent = 0);
    explicit Leg();
    double length, duration;
    QString type,code;
    QList<LegLoc*> *legs;

    QString typeofleg(); //{ qDebug() << "Type: " << type; return type;}
    QString vehicle();
    QString startLoc();
    QString stopLoc();
    QString startTime();
    QString stopTime();
    QDeclarativeListProperty<LegLoc> getlegs();

    ~Leg(){
        delete legs;
    }
private:
    QHash<QString,QString> vehicles;


    
signals:
    
public slots:
    
};

#endif // LEG_H
