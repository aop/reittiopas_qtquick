import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
//import QtQuick 1.1

Item {
    property string textName
    property alias text: fromField.text
    property alias activeFocus: fromField.activeFocus
    property bool errorHighlight: false
    height: 90
    id: addressFieldRoot

    Text {
        id: fromText
        color: "white"
        height: 32
        text: textName
        font.pixelSize: 25
        anchors.left: parent.left
        anchors.leftMargin: 10
    }
    Rectangle {
        id: wrapperRect
        color: "white"
        radius: 15
        height: 58
        width: parent.width
        anchors.top: fromText.bottom
        anchors.left: parent.left
        states: [
            /*State {
                name: "NORMAL"
                when:
                PropertyChanges {
                    target: wrapperRect
                    border.color: "red"
                    border.width: 3
                }
            },*/
            State {
                name: "ERROR"
                when: errorHighlight == true
                PropertyChanges {
                    target: wrapperRect
                    border.color: "red"
                    border.width: 3
                }
            }
        ]
        onStateChanged: console.debug("State changed")
        TextInput {
            function gotAddress(address){
                fromField.text = address
                indicator1.visible = false
                locationButton.haveLocation = true
            }
            id: fromField
            width: wrapperRect.width - 4
            height: wrapperRect.height - 4
            focus: false
            font.pixelSize: Math.round(height * (4/7))
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
    //                smooth: true
            Connections {
                target: reittiopas
                onGotAddress: fromField.gotAddress(address)
            }

        }
        Image {
            id: clearTo
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 5
            height: 35
            width: 35
            source: "qrc:/img/remove_plain.svg"
            MouseArea {
                id: clearToArea
                anchors.fill: parent
                onClicked: text = ""
            }
        }
    }
}
