#ifndef GPS_H
#define GPS_H


#include <QObject>
#include <QGeoPositionInfo>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>
#include <QDebug>
#include <QString>

QTM_USE_NAMESPACE

class GPS : public QObject
{
    Q_OBJECT
public:
    explicit GPS(QObject *parent = 0);
    ~GPS();

    double getLon();
    double getLat();

   // void startUpdates();

private:
    QGeoPositionInfoSource *source;
    bool updatesOn;
    double lon;
    double lat;

signals:
    void gotPosition(double lon, double lat);
public slots:
    void positionUpdated(QGeoPositionInfo);
    bool startPositioning();
};

#endif // GPS_H
