#include "legslist.h"
#include <QDebug>

LegsList::LegsList(QObject *parent) :
    QAbstractListModel(parent)
{
}

LegsList::LegsList(QList<Leg *> *l, QObject *parent)
    : list(l)
{
    setRoles();
}

int LegsList::rowCount(const QModelIndex &parent) const
{
    return list->size();
}

QVariant LegsList::data(const QModelIndex &index, int role) const
{
    qDebug() << "Legdata fetched";
    if(index.row() < 0 || index.row() >= list->size())
      return QVariant();
    Leg *tmp = list->at(index.row());
    switch (role){
    case VehicleType:
        return vehicles[tmp->type];
    default:
        return QVariant();
    }
}

void LegsList::setRoles()
{
    QHash<int,QByteArray> roles;
    roles[VehicleType] = "type";
    roles[VehicleId] = "id";
    setRoleNames(roles);

    vehicles["1"] = "BUS";
    vehicles["2"] = "TRAM";
    vehicles["3"] = "BUS";
    vehicles["4"] = "BUS";
    vehicles["5"] = "BUS";
}

Qt::ItemFlags LegsList::flags(const QModelIndex &index) const
{
    return (Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}
