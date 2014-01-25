#include "dbmanager.h"

DBManager::DBManager(QObject *parent) :
    QObject(parent)
{
    if(this->openDB()){
        bool created = this->createTables();
        if(!created){
            qDebug() << this->lastError();
        }
        qDebug() << created;
    } else {
        qDebug() << "Failed to open db";
    }

}

DBManager::~DBManager()
{
    db.close();
}

bool DBManager::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("reittiopasforsymbian.sqlite");
    return db.open();
}

void DBManager::closeDB()
{
    return db.close();
}

QSqlError DBManager::lastError(){
    return db.lastError();
}

QList<AddressContainer*> DBManager::getAddresses(QString startswith)
{
   bool ret = false;
    QList<AddressContainer*> retList;
    QSqlQuery query;
    if(startswith.isEmpty()){
        query = QSqlQuery(QString("select * from places"));
    } else {
        query = QSqlQuery(QString("select * from places where name like '"+startswith+"%'"));
    }
    retList = this->addressQuery(query);
    return retList;
}

QList<AddressContainer*> DBManager::addressQuery(QSqlQuery query){
    QList<AddressContainer*> retList;
    while (query.next()){
        QString locType,name,city,nickName;
        double lon, lat;
        name = query.value(1).toString();
        nickName = query.value(2).toString();
        locType = query.value(4).toString();
        city = query.value(6).toString();
        lon = query.value(7).toDouble();
        lat = query.value(8).toDouble();
        AddressContainer *tmp = new AddressContainer(locType,name,city,lon,lat,0,nickName);
        retList.append(tmp);
    }
    qDebug() << db.lastError();
    return retList;
}

AddressContainer *DBManager::getExactAddress(QString name)
{
    QSqlQuery q(QString("select * from places where name='"+name+"'"));
    QList<AddressContainer*> l = this->addressQuery(q);
    if(l.size() == 0){
        return 0;
    } else {
        return l.at(0);
    }
}

bool DBManager::removeAddress(QString name)
{
    bool ret = false;
    if(db.isOpen()){
        QSqlQuery query;
        ret = query.exec(QString("DELETE FROM places WHERE name='"+name+"'"));
    }
    return ret;
}

int DBManager::insertAddress(AddressContainer *addr)
{
    int newId = -1;
    bool ret = false;
    if (db.isOpen()){
        QSqlQuery query;
        ret = query.exec(QString("insert into places values(NULL,'%1','%2','%3','%4','%5','%6','%7','%8')")
                         .arg(addr->address).arg(addr->nickName).arg("false").arg(addr->locType).arg(addr->locTypeId).arg(addr->city).arg(addr->getLon()).arg(addr->getLat()));
        if (ret) {
            newId = query.lastInsertId().toInt();
        }
    }
    return newId;
}



bool DBManager::createTables()
{
    bool ret = false;
    if (db.isOpen()){
        QSqlQuery testQuery("SELECT name FROM sqlite_master WHERE type='table' AND name='places';");
        if(!testQuery.next()){
            QSqlQuery query;
            ret = query.exec("create table places "
                             "(id integer primary key, "
                             "name varchar(30), "
                             "nickname varchar(30), "
                             "favorite BOOLEAN, "
                             "locType varchar(30), "
                             "locTypeId integer, "
                             "city varchar(20) ,"
                             "lon FLOAT, "
                             "lat FLOAT,"
                             "UNIQUE (name))");
        }
    }
    return ret;
}

bool DBManager::deleteDB() {
    db.close();
    return QFile::remove("reittiopasforsymbian.sqlite");
}
