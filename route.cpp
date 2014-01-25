#include "route.h"

Route::Route(double length, QString duration, QList<Leg*>*legs, QObject *parent) :
    m_length(length), legs(legs)
{
    m_duration_hour = (duration.toLong() / 3600);
    m_duration_mins = ((duration.toLong() % 3600)/60);
}

Route::Route()
{
}

void Route::addLeg(Leg *leg)
{
    legs->append(leg);
}

Leg *Route::getLegAt(int idx)
{
    if (idx+1 > legs->size()){
        return NULL;
    }
    if (idx < 0){
        return NULL;
    }
    return legs->at(idx);
}

QString Route::leavewalk()
{
    Leg * tmpLeg = legs->at(0);
    QTime tmpTime = tmpLeg->legs->at(0)->dep.time();
    return tmpTime.toString("HH:mm");
}

QString Route::leavevehicle()
{
    if (legs->size() > 1){
        Leg *tmpLeg = legs->at(1);
        if (tmpLeg->legs->size() > 0){
            if (tmpLeg->legs->at(0)->dep.toString("HH:mm") == "0"){
                return "";
            }
            return tmpLeg->legs->at(0)->dep.toString("HH:mm");
        }
        return QString();
    }
    return QString();
}

QString Route::walklength()
{
    long tmpLength = 0;
    int i;
    for(i = 0; i < legs->size();++i){
        if (legs->at(i)->typeofleg().compare("walk",Qt::CaseInsensitive) == 0){
            tmpLength += legs->at(i)->length;
        }
    }
    if (tmpLength > 1000){
        QString k,m;
        k.setNum((tmpLength/1000));
        m.setNum(((tmpLength % 1000)/100));
        return k + ","+m+" km";
    }
    else {
        QString tmpstr;
        tmpstr.setNum(tmpLength);
        return tmpstr+" m";
    }
}

QString Route::wholeduration()
{
    QString h,m;
    h.setNum(m_duration_hour);
    m.setNum(m_duration_mins);
    return h+"h "+m+" min";
}

QString Route::arrTime()
{
    if(legs->size() == 0){
        return QString();
    }
    Leg *tmpLeg = legs->at(legs->size()-1);
    if(tmpLeg->legs->size() == 0){
        return QString();
    }
    return tmpLeg->legs->at(tmpLeg->legs->size()-1)->arr.toString("HH:mm");
}

QString Route::startLoc()
{
    return legs->first()->legs->first()->name;
}

QString Route::stopLoc()
{
    return legs->last()->legs->last()->name;
}

QDeclarativeListProperty<Leg> Route::getlegs()
{
    return QDeclarativeListProperty<Leg>(this,*legs);
}
