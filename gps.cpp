#include "gps.h"

GPS::GPS(QObject *parent) :
    QObject(parent), updatesOn(false), lon(0),lat(0)
{
    //QGeoPositionInfoSource *soure;
    source = QGeoPositionInfoSource::createDefaultSource(this);
    source->setPreferredPositioningMethods(QGeoPositionInfoSource::NonSatellitePositioningMethods);
}

GPS::~GPS(){
    delete source;
}

bool GPS::startPositioning(){
    if (source) {
        connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(positionUpdated(QGeoPositionInfo)));
        source->requestUpdate();
        updatesOn = true;
        qDebug() << "Requesting GPS update";
        return true;
    } else {
        return false;
    }
}


void GPS::positionUpdated(QGeoPositionInfo pos)
{
    qDebug() << "Got position!" << pos.coordinate();
    QGeoCoordinate coord = pos.coordinate();
    lon = coord.longitude();
    lat = coord.latitude();
    emit gotPosition(lon,lat);
}

double GPS::getLon(){
    return lon;
}

double GPS::getLat(){
    return lat;
}
