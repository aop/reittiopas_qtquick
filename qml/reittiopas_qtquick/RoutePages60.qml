import QtQuick 1.0

import "reittiopashelpers.js" as JS

Flickable {

    property int left_margin: 5
    property int right_margin: 5

    id: mainFlickable
    flickableDirection: Flickable.VerticalFlick
    //anchors.bottomMargin: toolBarLayout.height
    //boundsBehavior: Flickable.StopAtBounds
    contentHeight: 650
    width: 360
    height: 740
    Rectangle {
        id: mainRect
        color: "black"
        anchors.fill: parent

        property int routeIndex;
    /*
    tools: ToolBarLayout {
             ToolButton { iconSource: "toolbar-back"; onClicked: pageStack.pop() }
             ToolButton {
                 text: "-15 min"
                 onClicked: {
                     reittiopas.timeshiftRouteQuery(-15);
                 }
             }
             ToolButton {
                 text: "+15min"
                 onClicked: {
                     reittiopas.timeshiftRouteQuery(15);
                 }
             }
         }*/
    ListView {
        id: routeListView
        height: parent.height
        width: parent.width
        delegate: routeListDelegateComponent
        header: listHeader
    }
    Rectangle {
        id: footer
        height: 70
        width: parent.width
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#6f6f6f";
            }
            GradientStop {
                position: 1.00;
                color: "#000000";
            }
        }
        anchors.bottom: parent.bottom
        Rectangle {
            id: backButton
            height: 50
            width: 50
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            color: "black"
            border.color: "white"
            border.width: 2
            radius: 8

            Image{
                source: "qrc:/img/links.svg"
                height: parent.height - 4
                width: parent.width -4
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    cppRoot.setPage("routeList");
                }

                onPressed: toAnimation.start()
                onReleased: backAnimation.start()
                onExited: backAnimation.start()
            }
        ColorAnimation {id: toAnimation; target: backButton; property: "color"; to: "#2b8adc"; duration: 20 }
        ColorAnimation {id: backAnimation; target: backButton; property: "color"; to: "black"; duration: 200 }
        }
    }

    Component {
        id: listHeader
        Rectangle {
            height: 50
            Text {
                id: title
                anchors.top: parent.top
                anchors.left: parent.left
                height: 20
                text: "<b>Routes:</b> "
                color: "white"
            }
            Text {
                id: titleRoute
                height: 30
                anchors.left: parent.left
                anchors.top: title.bottom
                text: reittiopas.fromName+" -> "+reittiopas.toName
                color: "white"
            }

            Rectangle {
                color: "gray"
                width: parent.width -4
                anchors.top: titleRoute.bottom
                anchors.topMargin: 2
                height: 2
                radius: 1
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }



    function loadRoute(){
        routeListView.model = reittiopas.routes[mainRect.routeIndex].routelegs//reittiopas.loadRoutes();
        console.debug(reittiopas.routes)
    }
    /*function statusChangedF() {
         if (status === PageStatus.Activating){
             console.debug("Status was activating");

             //routeListView.model = testRoute
             loadRoutes();
             fullPageBusy.visible = false
             fullPageBusy.running = false
         }
     }*/

    Connections {
        target: cppRoot
        onShowRouteQML:
        {
            mainRect.loadRoute(num)
            mainRect.routeIndex = num;
            console.debug("showing route "+String(num))
        }
    }

    Component {
        id: routeListDelegateComponent
        Item {
            property int margintopbottom: 15
            id: routeListDelegate
            width: parent.parent.width
            height: 130
            Rectangle {
                id: listViewRect
                anchors.fill: parent
                smooth: true
                radius: 5
                color: "black" //routeListDelegate.selected ? "navy" : "black"; //root.platformStyle.itemSelectedBackgroundColor : root.platformStyle.itemBackgroundColor
            }
            Text {
                id: startTimeText
                anchors.left: parent.left
                anchors.bottom: startText.top
                color: "white"
                text: startTime
            }
            Text {
                id: startText
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                color: "white"
                text: startLoc
            }
            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 5
                anchors.top: parent.top
                Image {
                    id: vehicleImg
                    height: 40
                    width: type == "walk" ? 27 : 40
                    source: JS.getImageForVehicle(type)
                }
                Text {
                    anchors.horizontalCenter: vehicleImg.horizontalCenter
                    id: vehicleText
                    text: qsTr(vehicle)
                    font.pointSize: 5
                    color: "white"
                }
            }
            Text {
                id: stopTimeTxt
                anchors.right: parent.right
                anchors.bottom: stopText.top
                color: "white"
                text: stopTime
            }
            Text {
                id: stopText
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                color: "white"
                text: stopLoc
            }
            MouseArea {
                id: routeListMouseArea
                anchors.fill: parent
                onPressed: listViewRect.color = "#2b8adc";
                onReleased: listViewRect.color = "black";
                onCanceled: listViewRect.color = "black";
                /*onClicked: {
                    pageStack.push(Qt.resolvedUrl("RouteMap.qml"),{routeIndex: index})
                }*/
            }
        }
    }


    Component {
        id: routeImagesDelegate
        Item {
            height: 60
            width: type == "walk" ? 40 : 50
            anchors.bottomMargin: routeListDelegate.margintopbottom
            Column {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    id: vehicleImg
                    anchors.horizontalCenter: parent.horizontalCenter
                    height: 40
                    width: type == "walk" ? 27 : 40
                    source: JS.getImageForVehicle(type)
                }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    id: vehicleText
                    text: qsTr(vehicle)
                    font.pointSize: 5
                    color: "white"
                }
            }
        }
    }

    }
}
