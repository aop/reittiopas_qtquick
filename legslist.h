#ifndef LEGSLIST_H
#define LEGSLIST_H

#include <QAbstractListModel>
#include "leg.h"

class LegsList : public QAbstractListModel
{
    Q_OBJECT
public:
    enum EntryRoles {
        VehicleType = Qt::UserRole + 1,
        VehicleId
    };

    explicit LegsList(QObject *parent = 0);
    explicit LegsList(QList<Leg*> *l,QObject *parent=0);
    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<Leg*> *list;
    void setRoles();
    QHash<QString,QString> vehicles;
    
signals:
    
public slots:
    
};

#endif // LEGSLIST_H
