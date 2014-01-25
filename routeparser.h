#ifndef ROUTEPARSER_H
#define ROUTEPARSER_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QtXml/QtXml>

#include "route.h"

class RouteParser : public QObject
{
    Q_OBJECT
public:
    explicit RouteParser(QObject *parent = 0);
    
signals:
    void routesParsed(QList<Route*> *list);
    
public slots:
    void parseResponse(QNetworkReply* r);
    
};

#endif // ROUTEPARSER_H
