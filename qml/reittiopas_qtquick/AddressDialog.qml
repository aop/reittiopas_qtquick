import QtQuick 1.0 // to target S60 5th Edition or Maemo 5

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
        property string type;

        id: mainRect
        color: "black"
        anchors.fill: parent
        ListView {
            id: addressList
            delegate: routeListDelegateComponent
            header: listHeader
            //model: reittiopas.getPossibleList(typeofsignal)
            height: parent.height
            width: parent.width
        }
        function showPlaceDialog(typeofsignal){
            console.log("Multiple dialogs called "+new String(typeofsignal))
            addressList.model = reittiopas.getPossibleList(typeofsignal) // testModel
            type = typeofsignal;
        }
        Connections {
            target: reittiopas
            onMultipleChoicesForLocationSignal: mainRect.showPlaceDialog(typeofsignal) //type)
        }
    }

    Component {
        id: listHeader
        Rectangle {
            height: 40
            Text {
                id: title
                anchors.top: parent.top
                anchors.left: parent.left
                height: 25
                text: "Select address  "
                color: "white"
            }
            Text {
                id: titleLocator
                anchors.top: parent.top
                anchors.left: title.right
                height: 25
                text: "<b>"+ (mainRect.type === "TO" ? "to:" : "from:")+"</b>"
                color: "white"
            }
           /* Rectangle {
                color: "gray"
                width: parent.width -4
                anchors.top: titleRoute.bottom
                anchors.topMargin: 2
                height: 2
                radius: 1
                anchors.horizontalCenter: parent.horizontalCenter
            }*/
        }
    }
    Component {
        id: routeListDelegateComponent
        Item {
            property int margintopbottom: 15
            id: routeListDelegate
            width: parent.parent.width
            height: 45
            MouseArea {
                id: routeListMouseArea
                anchors.fill: parent
                onPressed: listViewRect.color = "#2b8adc";
                onReleased: listViewRect.color = "black";
                onCanceled: listViewRect.color = "black";
                onClicked: {
                    cppRoot.setPage("main");
                    reittiopas.multipleChoicesSelected(index,mainRect.type);
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
                text: modelData
                color: "white"
            }
        }
    }
}
