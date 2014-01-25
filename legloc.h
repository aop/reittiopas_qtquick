#ifndef LEGLOC_H
#define LEGLOC_H

#include <QObject>
#include <QStringList>
#include <QDateTime>

class LegLoc : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double lon READ getLon)
    Q_PROPERTY(double lat READ getLat)
public:
    explicit LegLoc(QString coords,QString arrTime, QString depTime, QString name, int code, int shortCode, QString stopAddress, QObject *parent = 0);
    explicit LegLoc();
    double lon,lat;
    QDateTime arr, dep;
    QString name;
    int code, shortCode;
    QString stopAddress;

    double getLon();
    double getLat();

signals:
    
public slots:

private:

    
};

#endif // LEGLOC_H
