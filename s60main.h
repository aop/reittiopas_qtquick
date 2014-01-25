#ifndef S60MAIN_H
#define S60MAIN_H

#include <QWidget>
#include <QtDeclarative>
#include <QList>

class S60Main : public QWidget
{
    Q_OBJECT
public:
    explicit S60Main(QWidget *parent = 0);
    void setContextProperty(const QString name, QObject * w);
    void setQML();
    QList<QDeclarativeView*> subWidgets;
    QDeclarativeView *routesView;
    QDeclarativeView *mainView;
    QDeclarativeView *addressDialog;
    QDeclarativeView *routePage;
    QStackedLayout *layout;

private:

    
signals:
    void quitSignal();
    void showRouteQML(int num);
    
public slots:
    void setPage(QString page);
    void multipleChoisesForLocation(QString typeofsignal);
    void queryingRoutes();
    void showRoute(int num);

private slots:
    void quit();
    
};

#endif // S60MAIN_H
