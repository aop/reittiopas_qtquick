// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.0
import com.nokia.symbian 1.1

import "reittiopashelpers.js" as JS

Page {
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
         }

    BusyIndicator {
        id: fullPageBusy
        running: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        height: 140
        width: 140
        visible: true
    }
    ListView {
        id: routeListView
        height: parent.height
        width: parent.width
        delegate: routeListDelegateComponent
        header: listHeader
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



    function loadRoutes(){
        routeListView.model = reittiopas.routes//reittiopas.loadRoutes();
        console.debug(reittiopas.routes)
    }
    function statusChangedF() {
         if (status === PageStatus.Activating){
             console.debug("Status was activating");

             //routeListView.model = testRoute
             loadRoutes();
             fullPageBusy.visible = false
             fullPageBusy.running = false
         }
     }

    Connections {
        target: reittiopas
        onGotRoutes: loadRoutes()
    }

    Component {
        id: routeListDelegateComponent
        Item {
            property int margintopbottom: 15
            id: routeListDelegate
            width: parent.parent.width
            height: 145
            MouseArea {
                id: routeListMouseArea
                anchors.fill: parent
                onPressed: listViewRect.color = "#2b8adc";
                onReleased: listViewRect.color = "black";
                onCanceled: listViewRect.color = "black";
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("RoutePage.qml"),{routeIndex: index})
                }
            }

            Rectangle {
                id: listViewRect
                anchors.fill: parent
                smooth: true
                radius: 5
                color: "black" //routeListDelegate.selected ? "navy" : "black"; //root.platformStyle.itemSelectedBackgroundColor : root.platformStyle.itemBackgroundColor
            }
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: margintopbottom
                id: duration
                text: walklength + " - " +wholeduration
                color: "white"
            }
            Column {
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.topMargin: margintopbottom
                Text {
                    text: "<b>"+leavewalk+"</b>"
                    color: "white"
                }
                Text {
                    text: "("+leavevehicle+")"
                    color: "white"
                }
            }
            Text {
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: margintopbottom
                id: arrtimetext
                text: "<b>"+arrTime+"</b>"
                color: "white"
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom //separator.top
                anchors.bottomMargin: 5
                Repeater {
                    id: routeIcons
                    //orientation: ListView.Horizontal
                    delegate: routeImagesDelegate
                    model: routelegs
                }
            }
            /*Rectangle {
                id: separator
                width: parent.width
                height: 2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                color: "navy";
                smooth: true
                radius: 5
            }*/
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
