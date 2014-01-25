#include "routeslist.h"

RoutesList::RoutesList(QObject *parent) :
    QAbstractListModel(parent)
{

}

RoutesList::RoutesList(QList<Route *> l, QObject *parent)
    : list(l)
{
    setRoles();
}

void RoutesList::setRoles(){
    QHash<int,QByteArray> roles;
    roles[LeaveWalkRole] = "leavewalk";
    roles[LeaveVehicleRole] = "leavevehicle";
    roles[WholeLength] = "wholeLength";
    roles[WholeDuration] = "wholeDuration";
    roles[ArrTime] = "arrTime";
    roles[Lines] = "lines";
    roles[Legs] = "legs";

    setRoleNames(roles);
}

int RoutesList::rowCount(const QModelIndex &parent) const
{
    return list.size();
}

Qt::ItemFlags RoutesList::flags(const QModelIndex &index) const
{
    return (Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

QVariant RoutesList::data(const QModelIndex &index, int role) const
{
    qDebug() << "Data fetched. Role: " << role;
    if(index.row() < 0 || index.row() >= list.size())
      return QVariant();
    Route * tmp = list.at(index.row());
    switch (role){
    case WholeLength:
    {
        long tmpLength = tmp->m_length;
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
    case WholeDuration:
    {
        QString h,m;
        h.setNum(tmp->m_duration_hour);
        m.setNum(tmp->m_duration_mins);
        return h+"h "+m+" min";
    }
    case LeaveWalkRole:
    {
        Leg * tmpLeg = tmp->getLegAt(0);
        QTime tmpTime = tmpLeg->legs->at(0)->dep.time();
        return tmpTime.toString("HH:mm");
    }
    case LeaveVehicleRole:
    {
        if (tmp->legs->size() > 1){
            Leg *tmpLeg = tmp->getLegAt(1);
            if (tmpLeg->legs->size() > 0){
                return tmpLeg->legs->at(0)->dep.toString("HH:mm");
            }

        }
        return QVariant();
    }
    case ArrTime:
    {
        if(tmp->legs->size() == 0){
            return QVariant();
        }
        Leg *tmpLeg = tmp->legs->at(tmp->legs->size()-1);
        if(tmpLeg->legs->size() == 0){
            return QVariant();
        }
        return tmpLeg->legs->at(tmpLeg->legs->size()-1)->arr.toString("HH:mm");
    }
    /*case Legs:
        qDebug() << "Fetching legs";
        if(tmp->legs->size() == 0){
            return QVariant();
        }
        return LegsList(tmp->legs);*/
    default:
        return QVariant();
    }

    return QVariant();

}

