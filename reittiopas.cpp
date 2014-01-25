#include "reittiopas.h"

Reittiopas::Reittiopas(QObject *parent)
    : usingLocation(false), ongoingLocationRequest(false), ongoingRouteRequest(false), fromLon(0), fromLat(0), toLon(0), toLat(0), haveRoutes(false), ongoingMultipleDialog(false), pendingMultipleDialog(""),ongoingReverseGeocodeRequest(false), usingToFromDB(false), usingFromFromDB(false), currentFrom(0), currentTo(0),depart(false),requestTime(QString())
{
}

 AddressList * Reittiopas::getPossibleList(QString typeofRoute)
{
     AddressList *al = 0;
     if (typeofRoute == "TO"){
        al = new AddressList(tolist);
        qDebug() << "Returning tolist len:" <<tolist.size();
     } else if (typeofRoute == "FROM") {
         al = new AddressList(fromlist);
         qDebug() << "Returning fromlist len:" <<tolist.size();
     }
     return al;
    /*if (type == "FROM"){
      return fromlist;
        return QDeclarativeListProperty<AddressContainer>(this,fromlist);
    } else if (type == "TO"){
        return tolist;
        //return QDeclarativeListProperty<AddressContainer>(this,tolist);;
    /
    QList<AddressContainer *> tmp;
    return tmp;
    return QDeclarativeListProperty<AddressContainer>(this,tmp);*/
}


void Reittiopas::reverseGeocodeQuery(double lon, double lat){
    if(ongoingReverseGeocodeRequest){
        return;
    }
    fromLon = lon;
    fromLat = lat;
    qDebug() << "Querying for reverseGeocode";
    ongoingReverseGeocodeRequest = true;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(parseReverseGeocodeRequest(QNetworkReply*)));
    QNetworkReply *addressQueryReply;
    QString slon,slat;
    slon.sprintf("%.2f", lon);
    slat.sprintf("%.2f", lat);
    addressQueryReply = manager->get(QNetworkRequest(QUrl("http://api.reittiopas.fi/hsl/prod/?user=oskari.petas&pass=pby8w9g5&request=reverse_geocode&coordinate="+slon+","+slat+"&epsg_in=4326&epsg_out=4326&format=xml")));
}

void Reittiopas::parseReverseGeocodeRequest(QNetworkReply *r)
{
    qDebug() << "Parsing address";
    QDomDocument doc("reverseGeocode");
    QByteArray ar = r->readAll();
    doc.setContent(ar);
    qDebug() << ar;
    QDomElement root = doc.documentElement();
    QDomNode n = root.firstChild();
    bool error = false;
    if (n.isNull()){
        error = true;
    }
    while(!n.isNull()){
      QDomElement e = n.toElement();
      if(!e.isNull() && e.tagName() == "node"){
          if(e.firstChildElement("locType").isNull()){
              qDebug() << "Api didn't return a locType";
              error = true;
          }
          QDomElement name = e.firstChildElement("name");
          if(!name.isNull()){
            emit gotAddress(name.text());
            //currentLocation = name.text();
          } else {
              error = true;
          }
          QDomElement coords = e.firstChildElement("coords");
          if(!coords.isNull()){
              QString coordString(coords.text());
              QStringList l = coordString.split(",");
              fromLon = l.at(0).toInt();
              fromLat = l.at(1).toInt();
          } else {
              error = true;
          }
      } else {
          error = true;
      }
      n = n.nextSibling();
    }
    usingLocation = true;
    ongoingReverseGeocodeRequest = false;
    if (error){
        qDebug() << "Emitting reverseGeocodeError";
        emit reverseGeocodeError();
    }
    return;
}


void Reittiopas::addressQuery(QString address, QString type){
    /*if(haveLocation || ongoingLocationRequest){
        return;
    }*/
    if (type == "TO"){
        qDebug() << "Querying for toaddress";
    } else if (type == "FROM"){
        qDebug() << "Querying for fromaddress";
    }
    ongoingLocationRequest = true;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    addressParser *ap = new addressParser(type);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
             ap, SLOT(parseResponse(QNetworkReply*)));
    connect(ap,SIGNAL(multipleChoises(QList<AddressContainer*>,QString)),
            this,SLOT(multipleChoicesForLocation(QList<AddressContainer*>,QString)));
    connect(ap,SIGNAL(parsedResponse(AddressContainer*,QString)),
            this,SLOT(parsedGeocodeFromAddress(AddressContainer*,QString)));
    connect(ap,SIGNAL(parsedEmpty(QString)),
            this,SLOT(parsedGeocodeEmpty(QString)));
    QNetworkReply *addressQueryReply;
    addressQueryReply = manager->get(QNetworkRequest(QUrl("http://api.reittiopas.fi/hsl/prod/?user=oskari.petas&pass=pby8w9g5&request=geocode&key="+address+"&disable_unique_stop_names=0&epsg_in=4326&epsg_out=4326&format=xml")));
}

void Reittiopas::timeshiftRouteQuery(int minutes){
    QTime tmpTime = QTime::fromString(requestTime,"hhmm");
    tmpTime = tmpTime.addSecs(minutes*60);
    requestTime = tmpTime.toString("HHmm");
    this->routeQueryPrivate(currentFrom->lon,currentFrom->lat,currentTo->lon,currentTo->lat,true);
}

void Reittiopas::routeQuery(QString fromAddress, QString toAddress, bool departBool, QString time){
    qDebug() << "Doing routeQuery";
    fromName = fromAddress;
    emit fromNameChanged(fromAddress);
    toName = toAddress;
    emit toNameChanged(toAddress);
    depart = departBool;
    requestTime = time.left(2) + time.right(2);

    fromLon = fromLat = toLon = toLat = 0;
    currentFrom = currentTo = 0;
    addressQuery(fromAddress,QString("FROM"));
    addressQuery(toAddress,QString("TO"));
    /*
      TRYING TO TRICK WITH CACHING COORDS SO WOULDNT DISPLAY DIALOG FOR KNOWN PLACES
    if (!usingFromFromDB){
        fromLon = fromLat = 0;
        addressQuery(fromAddress,QString("FROM"));
    }
    if (!usingToFromDB) {
        toLon = toLat = 0;
        addressQuery(toAddress,QString("TO"));
    }
    */
}

void Reittiopas::parsedGeocodeFromAddress(AddressContainer * addr,QString type)//double lon, double lat, QString type)
{
    if (type == "TO"){
        //on = addr->lon;
        //toLat = addr->lat;
        currentTo = addr;
        emit toNameChanged(addr->address);
        qDebug() << "toNameChanged signal: "<< toName;
    } else if (type == "FROM") {
        //fromLon = addr->lon;
        //fromLat = addr->lat;
        currentFrom = addr;
        emit fromNameChanged(addr->address);
    }
    bool haveTo, haveFrom;
    haveTo = haveFrom = false;
    if (currentTo != 0){//toLon != 0 && toLat != 0){
        haveTo = true;
        qDebug() << "Have to coords";
    }
    if (currentFrom != 0){//fromLon != 0 && fromLat != 0){
        haveFrom = true;
        qDebug() << "Have from coords";
    }
    if (haveTo && haveFrom){
        routeQueryPrivate(currentFrom->lon,currentFrom->lat,currentTo->lon,currentTo->lat);
    }
}

void Reittiopas::routeQueryPrivate(double fromLon, double fromLat, double toLon, double toLat,bool timeShift){
    qDebug() << "Performing actual routeQuery";
    if (timeShift){
        emit queryingShiftRoutes();
    } else {
        emit queryingRoutes();
    }
    db.insertAddress(currentTo);
    db.insertAddress(currentFrom);
    ongoingRouteRequest = true;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    RouteParser *rp = new RouteParser();
    connect(manager, SIGNAL(finished(QNetworkReply*)),
             rp, SLOT(parseResponse(QNetworkReply*)));
    connect(rp,SIGNAL(routesParsed(QList<Route*>*)),
            this,SLOT(routesParsed(QList<Route*>*)));
    QNetworkReply *addressQueryReply;
    QString sFromlon,sFromlat,sTolon,sTolat;
    sFromlon.setNum(fromLon);
    sFromlat.setNum(fromLat);
    sTolon.setNum(toLon);
    sTolat.setNum(toLat);
    QString timetype;
    if (depart){
        timetype = "arrival";
    } else {
        timetype = "departure";
    }
    QUrl url("http://api.reittiopas.fi/hsl/prod/?user=oskari.petas&pass=pby8w9g5&request=route&from="+sFromlon+","+sFromlat+"&to="+sTolon+","+sTolat+"&timetype="+timetype+"&time="+requestTime+"&epsg_in=4326&epsg_out=4326&format=xml");
    qDebug() << url.toString();
    addressQueryReply = manager->get(QNetworkRequest(url));
}

void Reittiopas::multipleChoicesForLocation(QList<AddressContainer *> list, QString type)
{
    if (type == "FROM"){
        fromlist = list;
        if (!ongoingMultipleDialog){
            ongoingMultipleDialog = true;
            emit multipleChoicesForLocationSignal(QString("FROM"));
        } else {
            qDebug() << "Pending FROM dialog";
            pendingMultipleDialog = "FROM";
        }
    } else if (type == "TO"){
        tolist = list;
        if (!ongoingMultipleDialog){
            ongoingMultipleDialog = true;
            emit multipleChoicesForLocationSignal(QString("TO"));
        } else {
            qDebug() << "Pending TO dialog";
            pendingMultipleDialog = "TO";
        }
    }
}

void Reittiopas::multipleChoicesSelected(int idx, QString type)
{
    AddressContainer *selectedAddress;
    if (type == "TO"){
        selectedTo = idx;
        //toLon = tolist[idx]->getLon();
        //toLat = tolist[idx]->getLat();
        //toName = tolist[idx]->address;
        //currentTo = tolist[idx];
        parsedGeocodeFromAddress(tolist[idx],type);
    } else if (type == "FROM"){
        selectedFrom = idx;
        //fromLon = fromlist[idx]->getLon();
        //fromLat = fromlist[idx]->getLat();
        //fromName = fromlist[idx]->address;
        //currentFrom = fromlist[idx];
        parsedGeocodeFromAddress(fromlist[idx],type);
    }
    ongoingMultipleDialog = false;
    if(pendingMultipleDialog != ""){
        qDebug() << "Opening pended dialog: "+ pendingMultipleDialog;
        multipleChoicesForLocationSignal(pendingMultipleDialog);
        pendingMultipleDialog = "";
    }
}

void Reittiopas::multipleChoicesRejected()
{
    ongoingMultipleDialog = false;
    pendingMultipleDialog = "";
}

void Reittiopas::routesParsed(QList<Route *> *listOfRoutes)
{
    qDebug() << "List of routes loaded";
    haveRoutes = true;
    routesList = listOfRoutes;
    for (int i = 0;i < routesList->size();++i){
        routesList->at(i)->legs->first()->legs->first()->name = fromName;
        routesList->at(i)->legs->last()->legs->last()->name = toName;
    }

    emit gotRoutes();
}

void Reittiopas::cancelLocation()
{
    usingLocation = false;
}

void Reittiopas::parsedGeocodeEmpty(QString type)
{
    qDebug() << "Emitting empty geocode";
    emit parsedGeocodeEmptySignal(type);
}

void Reittiopas::useValueFromDb(QString type, QString searchAddress)
{
    AddressContainer* address =  db.getExactAddress(searchAddress);
    if (type == "TO"){
        toLon = address->lon;
        toLat = address->lat;
        usingToFromDB = true;
    }
    if (type == "FROM"){
        fromLon = address->lon;
        fromLat = address->lat;
        usingFromFromDB = true;
    }
}

QList<AddressContainer *> Reittiopas::getPossibleListFrom()
{
    return fromlist;
}

/*RoutesList* Reittiopas::loadRoutes()
{
    if(!haveRoutes) {
        return new RoutesList();
    }
    return new RoutesList(*routesList);
}*/

Route *Reittiopas::testloadRoutes()
{
    return routesList->at(0);
}

QDeclarativeListProperty<Route> Reittiopas::routes()
{
    qDebug() << "routes loaded";
    return QDeclarativeListProperty<Route>(this, *routesList);
}

QDeclarativeListProperty<Leg> Reittiopas::legs(int idx)
{
    return QDeclarativeListProperty<Leg>(this,*(routesList->at(idx)->legs));
}

QString Reittiopas::getFromName()
{
    qDebug() << "returning fromName: "<<fromName;
    if(!currentFrom){
        return QString();
    }
    return currentFrom->address;
}

QString Reittiopas::getToName()
{
    if(!currentTo){
        return QString();
    }
    return currentTo->address;
}

QStringList Reittiopas::getMatchingNames(QString type, QString startswith)
{
    QList<AddressContainer*> l = db.getAddresses(startswith);
    QStringList retList;
    for(int i = 0;i< l.size();i++){
        retList.append(l.at(i)->address);
    }
    return retList;
}

bool Reittiopas::deleteAddress(QString address)
{
    return db.removeAddress(address);
}
