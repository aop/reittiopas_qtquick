#ifndef REITTIOPAS_H
#define REITTIOPAS_H

#include <QObject>
#include <QString>
#include <QtXml/QtXml>
#include <QtNetwork/QtNetwork>
#include <QDeclarativeListProperty>
#include <QDeclarativeItem>

#include "addressparser.h"
//#include "addresstypewrapper.h"
#include "routeparser.h"
//#include "routeslist.h"
//#include "legslist.h"
#include "dbmanager.h"

class Reittiopas: public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QDeclarativeListProperty<Route> routes READ routes)
    //Q_PROPERTY(QDeclarativeListProperty<Leg> legs READ legs)
    Q_PROPERTY(QString fromName READ getFromName NOTIFY fromNameChanged)
    Q_PROPERTY(QString toName READ getToName NOTIFY toNameChanged)

public:
    explicit Reittiopas(QObject *parent = 0);
    Q_INVOKABLE AddressList *getPossibleList(QString);
    Q_INVOKABLE QList<AddressContainer *> getPossibleListFrom();
    //Q_INVOKABLE RoutesList *loadRoutes();
    Q_INVOKABLE Route* testloadRoutes();
    QDeclarativeListProperty<Route> routes();
    Q_INVOKABLE QDeclarativeListProperty<Leg> legs(int idx);
    QString fromName,toName;
    QString getFromName();
    QString getToName();
    Q_INVOKABLE QStringList getMatchingNames(QString type,QString startswith);
    Q_INVOKABLE bool deleteAddress(QString address);
    Q_INVOKABLE void timeshiftRouteQuery(int minutes);

private:
    bool usingLocation;
    bool usingToFromDB, usingFromFromDB;
    bool ongoingLocationRequest, ongoingRouteRequest;
    bool ongoingReverseGeocodeRequest;
    bool ongoingMultipleDialog;
    QString pendingMultipleDialog;
    double fromLon, fromLat, toLon, toLat;
    QList<AddressContainer *> fromlist;
    QList<AddressContainer *> tolist;
    AddressContainer * currentFrom;
    AddressContainer* currentTo;
    int selectedFrom, selectedTo;
    QList<Route*> *routesList;
    bool haveRoutes,depart;
    QString currentLocation,requestTime;
    DBManager db;

public slots:
    void reverseGeocodeQuery(double lon, double lat); // To find address from geocode (for example from GPS coordinates)
    void addressQuery(QString address, QString type); // To find geocode from address
    void routeQuery(QString fromAddress, QString toAddress, bool departBool=true, QString time=QTime::currentTime().toString("HHmm")); // starts the whole system with two addresses
    //void parsedGeocodeFromAddress(double lon, double lat, QString type); // Should be called when geocode is found from address.
    void parsedGeocodeFromAddress(AddressContainer* addr, QString type);
    void multipleChoicesForLocation(QList<AddressContainer *> list,QString type); // Address query provided multiple responses
    void multipleChoicesSelected(int idx, QString type); // When user selects an address
    void multipleChoicesRejected(); // When user presses outside dialog
    void routesParsed(QList<Route*> *listOfRoutes);
    void cancelLocation();
    void parsedGeocodeEmpty(QString);
    void useValueFromDb(QString type, QString searchAddress);

private slots:
    void parseReverseGeocodeRequest(QNetworkReply *reply);
    void routeQueryPrivate(double fromLon, double fromLat, double toLon, double toLat, bool timeShift=false);

signals:
    void gotAddress(QString address);
    void gotMyAddress();
    void multipleChoicesForLocationSignal(QString typeofsignal);
    void gotRoutes();
    void queryingRoutes();
    void queryingShiftRoutes();
    void parsedGeocodeEmptySignal(QString type);
    void reverseGeocodeError();
    void fromNameChanged(QString name);
    void toNameChanged(QString name);
};

#endif // REITTIOPAS_H
