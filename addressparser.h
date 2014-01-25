#ifndef ADDRESSPARSER_H
#define ADDRESSPARSER_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QtXml/QtXml>
#include "addresstypewrapper.h"

class AddressContainer : public QObject
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole+1,
        DialogRole,
    };

public:
    explicit AddressContainer(QString loc, QString address, QString city, double lon, double lat, int locTypeId= 0, QString nickName = QString(), QObject *parent= 0);
    explicit AddressContainer();
    //AddressContainer(QObject *parent=0);
    //AddressContainer(const AddressContainer &a);
    QVariant data(int role) const;
    //QHash<int, QByteArray> roleNames() const;
    void setAddress(QString);
    void setLon(double);
    void setLan(double);

    QString getAddress() const;
    double getLon();
    double getLat();
    QString address, name, matchedName, lang, city, nickName,locType;
    double lon, lat;
    int locTypeId;

private:


};


class addressParser : public QObject
{
    Q_OBJECT
public:

    explicit addressParser(QString, QObject *parent = 0);
    QList<AddressContainer *> addressList;


private:
    QString type;

signals:
    //void parsedResponse(double lon, double lat, QString type);
    void parsedResponse(AddressContainer* addr, QString type);
    void multipleChoises(QList<AddressContainer *> list,QString type);
    void parsedEmpty(QString type);
    
public slots:
    void parseResponse(QNetworkReply*);

};

class AddressList: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AddressList(QList<AddressContainer *> initList=QList<AddressContainer *>(), QObject *parent=0);

    Q_INVOKABLE int rowCount(const QModelIndex &parent) const;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<AddressContainer *> m_list;

};


#endif // ADDRESSPARSER_H
