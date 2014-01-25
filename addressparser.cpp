#include "addressparser.h"

addressParser::addressParser(QString type, QObject *parent) :
    QObject(parent), type(type)
{
}

void addressParser::parseResponse(QNetworkReply *r) {
    QByteArray ar = r->readAll();
    QDomDocument doc("addressParsing");
    doc.setContent(ar);
    QDomElement root = doc.documentElement(); //<response>
    QDomNode n = root.firstChild(); // First <node>

    while(!n.isNull()){ // For every <node> - nextSibling at end of loop
      QDomElement e = n.toElement();
      if(!e.isNull() && e.tagName() == "node"){
          QDomElement locTypeElement = e.firstChildElement("locType");
          QString locType = "";
          if(!locTypeElement.isNull()){
              locType = e.firstChildElement("locType").text();
          }
          QDomElement name = e.firstChildElement("name");
          QString address = "";
          if(!name.isNull()){
              address = name.text();
          }
          QDomElement cityElement = e.firstChildElement("city");
          QString city = "";
          if(!cityElement.isNull()){
              city = cityElement.text();
          }
          QDomElement coordsElement = e.firstChildElement("coords");
          double lon, lat = 0;
          if(!coordsElement.isNull()){
              QString coords = coordsElement.text();
              QStringList coordsList = coords.split(",");
              lon = coordsList[0].toDouble();
              lat = coordsList[1].toDouble();
          }
          AddressContainer *container = new AddressContainer(locType, address, city, lon, lat);
          addressList.append(container);
      }
      n = n.nextSibling();
    }
    if (addressList.length() > 1){
        emit multipleChoises(addressList,type);
    } else if (addressList.length() == 1){
        //emit parsedResponse(addressList[0]->getLon(),addressList[0]->getLat(),type);
        emit parsedResponse(addressList[0],type);
    } else if (addressList.length() == 0){
        emit parsedEmpty(type);
    }
    return;
}

/*AddressContainer::AddressContainer(QObject *parent):
    lon(0), lat(0), address("")
{

}*/

/*
AddressContainer::AddressContainer(const AddressContainer &a):
    lon(a.getLon()), lat(a.getLat()), address(a.getAddress())
{
}*/

AddressContainer::AddressContainer(QString loc, QString address, QString city, double lon, double lat,int locTypeId,QString nickName, QObject *parent):
    address(address), locType(loc), locTypeId(locTypeId), city(city), lon(lon), lat(lat), nickName(nickName)
{
}

AddressContainer::AddressContainer()
{
}

QVariant AddressContainer::data(int role) const
{
    switch(role) {
    case NameRole:
        return address;
    case DialogRole:
        return address+"("+locType+")";
        //return r;
    default:
        return QVariant();
    }

}

double AddressContainer::getLon()
{
    return lon;
}

double AddressContainer::getLat()
{
    return lat;
}

QString AddressContainer::getAddress() const
{
    return address;
}

/*QHash<int, QByteArray> AddressContainer::roleNames() const
{
    QHash<int, QByteArray> names;
    names[NameRole] = "name";
    names[DialogRole] = "dialogname";
    return names;
}
*/


QVariant AddressList::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
      return QVariant();
    return m_list.at(index.row())->getAddress();

}

Qt::ItemFlags AddressList::flags(const QModelIndex &index) const
{
    return (Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

int AddressList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

AddressList::AddressList(QList<AddressContainer *> initList, QObject *parent):
    m_list(initList)
{
    QHash<int, QByteArray> roleNames;
    roleNames.insert(Qt::DisplayRole,"name");
    setRoleNames(roleNames);
}
