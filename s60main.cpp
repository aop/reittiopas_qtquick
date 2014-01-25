#include "s60main.h"

S60Main::S60Main(QWidget *parent) :
    QWidget(parent), layout(new QStackedLayout)
{
    mainView = new QDeclarativeView;
    routesView = new QDeclarativeView;
    addressDialog = new QDeclarativeView;
    routePage = new QDeclarativeView;
    subWidgets.append(mainView);
    connect((QObject*)mainView->engine(),SIGNAL(quit()),this,SLOT(quit()));
    subWidgets.append(routesView);
    subWidgets.append(addressDialog);
    subWidgets.append(routePage);
    this->setContextProperty("cppRoot",this);
}

void S60Main::setContextProperty(const QString name, QObject *w)
{
    for(int i = 0; i < subWidgets.size();i++){
        subWidgets[i]->rootContext()->setContextProperty(name,w);
    }
}

void S60Main::setQML(){
    mainView->setSource(QUrl("qrc:/qml/reittiopas_qtquick/mains60.qml"));
    routesView->setSource(QUrl("qrc:/qml/reittiopas_qtquick/RouteLists60.qml"));
    addressDialog->setSource(QUrl("qrc:/qml/reittiopas_qtquick/AddressDialog.qml"));
    routePage->setSource(QUrl("qrc:/qml/reittiopas_qtquick/RoutePages60.qml"));

    layout->addWidget(mainView);
    layout->addWidget(routesView);
    layout->addWidget(addressDialog);
    layout->addWidget(routePage);
    this->setLayout(layout);
    this->showFullScreen();
}

void S60Main::setPage(QString page)
{
    qDebug() << "Setting page " << page;
    if (page == QString("main")){
        layout->setCurrentIndex(0);
    }
    else if (page == QString("routeList")){
        layout->setCurrentIndex(1);
    }
    else if (page == QString("addressDialog")){
        layout->setCurrentIndex(2);
    }
    else if (page == QString("routePage")){
        layout->setCurrentIndex(3);
    }
}

void S60Main::multipleChoisesForLocation(QString typeofsignal)
{
    this->setPage(QString("addressDialog"));
}

void S60Main::queryingRoutes()
{
    this->setPage(QString("routeList"));
}

void S60Main::showRoute(int num)
{
    qDebug() << "showRouteSignal";
    emit showRouteQML(num);
}

void S60Main::quit()
{
    emit quitSignal();
}
