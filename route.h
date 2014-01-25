#ifndef ROUTE_H
#define ROUTE_H

#include <QObject>
#include "leg.h"
#include <QAbstractListModel>
#include <QVariant>
#include <QtNetwork/QtNetwork>
#include <QtXml/QtXml>
#include <QDeclarativeItem>
#include <QList>

class Route : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString leavewalk READ leavewalk)
    Q_PROPERTY(QString leavevehicle READ leavevehicle)
    Q_PROPERTY(QString walklength READ walklength)
    Q_PROPERTY(QString wholeduration READ wholeduration)
    Q_PROPERTY(QString arrTime READ arrTime)
    Q_PROPERTY(QString startLoc READ startLoc)
    Q_PROPERTY(QString stopLoc READ stopLoc)
    Q_PROPERTY(QDeclarativeListProperty<Leg> routelegs READ getlegs)

public:
    explicit Route(double length, QString duration, QList<Leg*>*legs,QObject *parent = 0);
    explicit Route();
    long m_length;
    int m_duration_hour,m_duration_mins;
    QList<Leg*> *legs;
    void addLeg(Leg* leg);
    Leg * getLegAt(int idx);

    QString leavewalk();
    QString leavevehicle();
    QString walklength();
    QString wholeduration();
    QString arrTime();
    QString startLoc();
    QString stopLoc();
    QDeclarativeListProperty<Leg> getlegs();


    //QHash<int, QByteArray> roleNames() const;

signals:
    
public slots:
    
};

#endif // ROUTE_H
