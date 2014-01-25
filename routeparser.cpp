#include "routeparser.h"

RouteParser::RouteParser(QObject *parent) :
    QObject(parent)
{
}

void RouteParser::parseResponse(QNetworkReply *r)
{
    qDebug() << "Parsing routeRequest";
    if(r->error() != 0){
        qDebug() << r->errorString();
        return;
    }
    QByteArray ar = r->readAll();
    QDomDocument doc("routeParsing");
    if(!doc.setContent(ar)){
        qDebug() << "Parsing failed!";
        return;
    }
 /*   qDebug() << "Document: ";
    qDebug() << doc.toString();*/
    QDomElement root = doc.documentElement(); //<response>
    QDomNode n = root.firstChild(); // First <node>(1)

    QList<Route*> * routes = new QList<Route*>();

    while(!n.isNull()){ // For every <node>(1) - nextSibling at end of loop
      QDomElement e = n.toElement();
      QDomNode m = e.firstChild(); // <node>(2)
      while(!m.isNull()) { // For every <node>(2) - actual route
          QDomElement f = m.toElement();
          qDebug() << "Parsing..";
          QDomElement lenElement = f.firstChildElement("length");
          QString len = "";
          if(!lenElement.isNull()){
              len = lenElement.text();
          }
          QDomElement durElement = f.firstChildElement("duration");
          QString dur = "";
          if(!durElement.isNull()){
              dur = durElement.text();
          }
          QDomElement legElement = f.firstChildElement("legs");
          QDomNode legNode = legElement.firstChild(); // Leg
          QList<Leg*> *legList = new QList<Leg*>();
          while(!legNode.isNull()){
              QDomElement legLenElement = legNode.firstChildElement("length");
              QString legLen;
              if(!legLenElement.isNull()){
                  legLen = legLenElement.text();
              }
              QDomElement legDurElement = legNode.firstChildElement("duration");
              QString legDur;
              if(!legDurElement.isNull()){
                  legDur = legDurElement.text();
              }
              QDomElement legTypeElement = legNode.firstChildElement("type");
              QString legType;
              if(!legTypeElement.isNull()){
                  legType = legTypeElement.text();
              }
              QDomElement legCodeElement = legNode.firstChildElement("code");
              QString legCode;
              if(!legCodeElement.isNull()){
                  legCode = legCodeElement.text();
              }
              QDomElement locElement = legNode.firstChildElement("locs");
              QList<LegLoc*> *legLocs = new QList<LegLoc*>;
              QDomNode locNode = locElement.firstChild();
              while(!locNode.isNull()){
                  QDomElement locCoordElement = locNode.firstChildElement("coord");
                  QString locCoord;
                  if(!locCoordElement.isNull()){
                      locCoord = locCoordElement.text();
                  }
                  QDomElement locarrTimeElement = locNode.firstChildElement("arrTime");
                  QString arrTime;
                  if(!locarrTimeElement.isNull()){
                      arrTime = locarrTimeElement.text();
                  }
                  QDomElement locdepTimeElement = locNode.firstChildElement("depTime");
                  QString depTime;
                  if(!locdepTimeElement.isNull()){
                      depTime = locdepTimeElement.text();
                  }
                  QDomElement locNameElement = locNode.firstChildElement("name");
                  QString locName;
                  if(!locNameElement.isNull()){
                      locName = locNameElement.text();
                  }
                  QDomElement locCodeElement = locNode.firstChildElement("code");
                  QString locCode;
                  if(!locCodeElement.isNull()){
                      locCode = locCodeElement.text();
                  }
                  QDomElement locAddressElement = locNode.firstChildElement("stopAddress");
                  QString locAddress;
                  if(!locAddressElement.isNull()){
                      locAddress = locAddressElement.text();
                  }

                  LegLoc * thisLegLoc = new LegLoc(locCoord,arrTime,depTime,locName,locCode.toInt(),0,locAddress);
                  legLocs->append(thisLegLoc);

                  locNode = locNode.nextSibling();
              }

              Leg *thisLeg = new Leg(legLen.toDouble(),legDur.toDouble(),legType,legCode,legLocs);
              legList->append(thisLeg);

              legNode = legNode.nextSibling();
          }

          Route *route = new Route(len.toDouble(),dur,legList);
          qDebug() << len;
          routes->append(route);
          m = m.nextSibling();
      }
      n = n.nextSibling();

    }
    emit routesParsed(routes);
    return;
}

