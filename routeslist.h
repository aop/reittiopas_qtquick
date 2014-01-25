#ifndef ROUTESLIST_H
#define ROUTESLIST_H

#include <QAbstractListModel>
#include "route.h"
#include "legslist.h"

class RoutesList : public QAbstractListModel
{

    Q_OBJECT
public:
    enum EntryRoles {
        LeaveWalkRole = Qt::UserRole + 1,
        LeaveVehicleRole = Qt::UserRole + 2,
        WholeLength,
        WholeDuration,
        ArrTime,
        Lines,
        Legs
      };


    explicit RoutesList(QObject *parent = 0);
    explicit RoutesList(QList<Route*> l, QObject *parent = 0);
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<Route*> list;
    void setRoles();

signals:
    
public slots:
    
};

#endif // ROUTESLIST_H
