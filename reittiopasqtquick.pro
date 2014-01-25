# Add more folders to ship with the application, here
folder_01.source = qml/reittiopas_qtquick
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0x2005e973

VERSION = 1.3.0

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

ICON = launch_icon_reittiopas_converted.svg

# Allow network access on Symbian
symbian: {
    TARGET.CAPABILITY += NetworkServices Location



    my_deployment.pkg_prerules += vendorinfo
    my_deployment.pkg_prerules += \
        "; Dependency to Symbian Qt Quick components" \
        "(0x200346de), 1, 1, 0, {\"Qt Quick components\"}"

    DEPLOYMENT += my_deployment

    DEPLOYMENT.display_name += Reittiopas for Symbian
    DEPLOYMENT.installer_header = 0x2002CCCF

    vendorinfo += "%{\"Nordic code\"}" ":\"Nordic code\""
}
TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
 CONFIG += mobility
 MOBILITY += location

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# Add dependency to Symbian components

# FOR SYMBIAN 3 UNCOMMENT
#CONFIG += qt-components

DEFINES += QMLJSDEBUGGER

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    gps.cpp \
    reittiopas.cpp \
    addressparser.cpp \
    #addresstypewrapper.cpp \
    routeparser.cpp \
    legloc.cpp \
    leg.cpp \
    route.cpp \
    #routeslist.cpp \
    #legslist.cpp
    dbmanager.cpp \
    s60main.cpp

QT += xml network sql

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    #img/location.jpg \
    #qml/reittiopas_qtquick/reittiopashelpers.js
    launch_icon_reittiopas.svg \
    qml/reittiopas_qtquick/mains60.qml

HEADERS += \
    gps.h \
    reittiopas.h \
    addressparser.h \
    #addresstypewrapper.h \
    routeparser.h \
    legloc.h \
    leg.h \
    route.h \
    #routeslist.h \
    #legslist.h
    dbmanager.h \
    s60main.h

