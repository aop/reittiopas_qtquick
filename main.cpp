#include <QtGui/QApplication>
#include <QDeclarativeView>
#include <QGraphicsObject>
#include <QDeclarativeContext>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"
#include "gps.h"
#include "reittiopas.h"
#include "route.h"
#include "s60main.h"
//#include "routeslist.h"
//#include "legslist.h"

#ifdef Q_OS_SYMBIAN
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>
#endif

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QDeclarativeView view;
    qmlRegisterType<AddressList>("AddressList",1,0,"AddressList");
    qmlRegisterType<AddressContainer>("AddressContainer",1,0,"AddressContainer");
    qmlRegisterType<Route>("Route",1,0,"Route");
    qmlRegisterType<Leg>("Leg",1,0,"Leg");
    qmlRegisterType<LegLoc>("LegLoc",1,0,"LegLoc");
    //qmlRegisterType<RoutesList>("RoutesList",1,0,"RoutesList");
    //qmlRegisterType<LegsList>("Legslist",1,0,"Legslist");
    GPS gps;
    view.rootContext()->setContextProperty("gps", &gps);
    Reittiopas ropas;
    view.rootContext()->setContextProperty("reittiopas",&ropas);
    QObject::connect(&gps,SIGNAL(gotPosition(double,double)),&ropas,SLOT(reverseGeocodeQuery(double,double)));


    /*QList<LegLoc*> *legloclist = new QList<LegLoc*>;
    LegLoc * newlegloc = new LegLoc("10000002000000","1010","1015","Rummunlyöjänkatu 3",100,100,"Rummunlyöjänkatu 3");
    legloclist->append(newlegloc);
    QList<Leg*> *legs = new QList<Leg*>;
    Leg * newleg= new Leg(30.0,25.0,"BUS","100",legloclist);
    Leg * newleg2= new Leg(30.0,25.0,"BUS","100",legloclist);
    legs->append(newleg);
    legs->append(newleg2);
    Route *r = new Route(20.0,"10",legs);
    QList<Route*> routesList;
    routesList.append(r);
    RoutesList rList(routesList);
    view.rootContext()->setContextProperty("testRoute",&rList);*/

    //
    //  S60 BELOW
    //

        #ifdef Q_OS_SYMBIAN
        CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
        TRAPD(error,
        if (appUi) {
            // Lock application orientation into landscape
            appUi->SetOrientationL(CAknAppUi::EAppUiOrientationPortrait);
        }
        );
        #endif

        S60Main window;
        window.setContextProperty(QString("gps"),&gps);
        window.setContextProperty(QString("reittiopas"),&ropas);
        window.setQML();
        QObject::connect(&ropas,SIGNAL(multipleChoicesForLocationSignal(QString)),&window,SLOT(multipleChoisesForLocation(QString)));
        QObject::connect(&ropas,SIGNAL(queryingRoutes()),&window,SLOT(queryingRoutes()));
        QObject::connect(&window,SIGNAL(quitSignal()),&app,SLOT(quit()));

    //
    //  S60 END
    //

    //
    //  FOR SYMBIAN^3
    //
        //view.setSource(QUrl::fromLocalFile("qml/reittiopas_qtquick/main.qml"));
        //view.show();
    //
    //  END SYMBIAN^3
    //

    return app.exec();
}
