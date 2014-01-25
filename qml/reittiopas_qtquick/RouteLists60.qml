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

        //Component.onCompleted: { //LOADED TOO FAST
        //    routeList.model = reittiopas.routes[routeIndex].routelegs
        //    console.debug("LOADING ROUTE: "+reittiopas.routes[routeIndex].routelegs)
        //}
        function loadRoutes(){
            routeList.model = reittiopas.routes//reittiopas.loadRoutes();
            loadingText.text = ""
            console.debug("Loading routes:" + reittiopas.routes)
        }
        Connections {
            target: reittiopas
            onGotRoutes: mainRect.loadRoutes()
        }
        Component {
            id: listHeader
            Rectangle {
                height: 50
                /*Text {
                    id: title
                    anchors.top: parent.top
                    anchors.left: parent.left
                    height: 20
                    text: "<b>Route "+new String(parseInt(mainRect.routeIndex)+1)+":</b> "
                    color: "white"
                }*/
                Text {
                    id: titleRoute
                    height: 30
                    anchors.left: parent.left
                    //anchors.top: title.bottom
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
        Text {
            id: loadingText
            text: "Loading.."
            anchors.top: parent.top
            anchors.topMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter
            color: "grey"
        }

        ListView {
            id: routeList
            anchors.fill: parent
            delegate: routeListDelegateComponent
            header: listHeader
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
                        cppRoot.setPage("routePage");
                        cppRoot.showRoute(index);
                        loadingText.text = "Loading..."
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
                        cppRoot.setPage("main");
                    }

                    onPressed: toAnimationLeft.start()
                    onReleased: backAnimationLeft.start()
                    onExited: backAnimationLeft.start()
                }
            ColorAnimation {id: toAnimationLeft; target: backButton; property: "color"; to: "#2b8adc"; duration: 20 }
            ColorAnimation {id: backAnimationLeft; target: backButton; property: "color"; to: "black"; duration: 200 }
            }
        }

    }

}
