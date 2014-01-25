#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QSqlQuery>

#include "addressparser.h"

class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager(QObject *parent = 0);
    ~DBManager();
    bool openDB();
    void closeDB();
    QSqlError lastError();
    QList<AddressContainer *> getAddresses(QString startswith=QString());
    int insertAddress(AddressContainer *addr);
    bool deleteDB();
    QList<AddressContainer*> addressQuery(QSqlQuery query);
    AddressContainer * getExactAddress(QString name);
    bool removeAddress(QString name);

private:
    QSqlDatabase db;
    bool createTables();
    
signals:
    
public slots:
    
};

#endif // DBMANAGER_H
