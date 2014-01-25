#include "leg.h"

Leg::Leg(double length, double duration, QString type, QString code, QList<LegLoc *> *list, QObject *parent) :
    length(length), duration(duration), type(type), code(code), legs(list), QObject(parent)
{
    vehicles["1"] = "BUS";
    vehicles["2"] = "TRAM";
    vehicles["3"] = "BUS";
    vehicles["4"] = "BUS";
    vehicles["5"] = "BUS";
    vehicles["6"] = "METRO";
    vehicles["7"] = "FERRY";
    vehicles["8"] = "BUS";
    vehicles["12"] = "TRAIN";
    vehicles["21"] = "BUS";
    vehicles["22"] = "NIGHTBUS";
    vehicles["23"] = "BUS";
    vehicles["24"] = "BUS";
    vehicles["25"] = "NIGHTBUS";
    vehicles["36"] = "BUS";
    vehicles["39"] = "BUS";
}

Leg::Leg(){

}

QString Leg::typeofleg(){
    qDebug() << "Type: " << type << vehicles[type];
    if (type == "walk"){
        return "walk";
    }
    return vehicles[type];
}

QString Leg::vehicle()
{
    if (type == "walk"){
        if (length > 1000){
            QString k,m;
            k.setNum((long)length/1000);
            m.setNum((((long)length % 1000)/100));
            return k + ","+m+" km";
        }
        else {
            QString tmpstr;
            tmpstr.setNum(length);
            return tmpstr+" m";
        }
    }
    if (typeofleg() == "TRAIN"){
        return code.mid(4,1);
    }
    if (typeofleg() == "METRO"){
        return QString("Metro");
    }
    QString numcode = code.mid(1,3);
    numcode.setNum(numcode.toInt());
    QString charcode = code.mid(4,1);
    return numcode+charcode;
}

QString Leg::startLoc()
{
    return legs->first()->name;
}

QString Leg::stopLoc()
{
    return legs->last()->name;
}

QString Leg::startTime()
{
    return legs->first()->dep.toString("HH:mm");
}

QString Leg::stopTime()
{
    return legs->last()->dep.toString("HH:mm");
}

QDeclarativeListProperty<LegLoc> Leg::getlegs()
{
    return QDeclarativeListProperty<LegLoc>(this,*legs);
}
