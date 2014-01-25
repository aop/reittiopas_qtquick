#include "legloc.h"
#include <QDebug>

LegLoc::LegLoc(QString coords, QString arrTime, QString depTime, QString name, int code, int shortCode, QString stopAddress, QObject *parent)
    : name(name), code(code), shortCode(shortCode), stopAddress(stopAddress)
{
    lon = coords.left(13).toDouble();
    lat = coords.right(coords.size()-13).toDouble();
    arr = QDateTime::fromString(arrTime,"yyyyMMddHHmm");
    dep = QDateTime::fromString(depTime,"yyyyMMddHHmm");

}

LegLoc::LegLoc()
{
}

double LegLoc::getLon()
{
    return lon;
}

double LegLoc::getLat()
{
    return lat;
}
