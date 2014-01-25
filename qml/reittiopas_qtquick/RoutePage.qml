// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.0
import com.nokia.symbian 1.1

import "reittiopashelpers.js" as JS

Page {
    tools: toolbarlayout
    ToolBarLayout {
        id: toolbarlayout
        ToolButton { iconSource: "toolbar-back"; onClicked: pageStack.pop() }
        ToolButton { iconSource: "toolbar-previous"; onClicked: pageStack.replace(Qt.resolvedUrl("RoutePage.qml"),{routeIndex: routeIndex-1}); visible: (routeIndex > 0)}
        ToolButton { iconSource: "toolbar-next"; onClicked: pageStack.replace(Qt.resolvedUrl("RoutePage.qml"),{routeIndex: routeIndex+1}); visible: (routeIndex < 2)}
    }

    property int routeIndex;

    onStatusChanged: {
        if(status === Component.Ready){
            routeList.model = reittiopas.routes[routeIndex].routelegs
            console.debug("LOADING ROUTE: "+reittiopas.routes[routeIndex].routelegs)
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
                text: "<b>Route "+new String(parseInt(routeIndex)+1)+":</b> "
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

    ListView {
        id: routeList
        anchors.fill: parent
        delegate: routeDelegate
        header: listHeader
    }
    Component {
        id: routeDelegate
        Item {
            height: 100
            width: parent.parent.width
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
}
