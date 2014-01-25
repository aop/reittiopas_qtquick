import QtQuick 1.0
import com.nokia.symbian 1.1
import com.nokia.extras 1.1


Page {
    id: mainPage
    Flickable {

        property int left_margin: 5
        property int right_margin: 5

        id: mainFlickable
        anchors.fill: parent
        flickableDirection: Flickable.VerticalFlick
        //anchors.bottomMargin: toolBarLayout.height
        boundsBehavior: Flickable.StopAtBounds
        contentHeight: 550
        Text {
            id: titletext
            text: "Reittiopas for Symbian"
            color: "white"
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.horizontalCenter: parent.horizontalCenter
        }

        TextField {
            function gotAddress(address){
                fromField.text = address
                indicator1.visible = false
                locationButton.haveLocation = true
            }
            id: fromField
            width: parent.width - 70 - mainFlickable.left_margin - mainFlickable.right_margin
            height: 70
            placeholderText: "From"
            focus: false
            anchors.top: titletext.bottom
            anchors.topMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: mainFlickable.left_margin
            anchors.rightMargin: mainFlickable.right_margin
            Connections {
                target: reittiopas
                onGotAddress: fromField.gotAddress(address)
            }
            onTextChanged: {
                if (fromField.text.length > 0){
                    fromAutoComplete.fetchedModel = reittiopas.getMatchingNames("FROM",fromField.text)
                } else {
                    fromAutoComplete.fetchedModel = []
                }

                errorHighlight = false
            }
            Image {
                id: clearFrom
                anchors.right: parent.right
                source: "qrc:/img/remove_plain.svg"
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 5
                height: 35
                width: 35
                MouseArea {
                    id: clearFromArea
                    anchors.fill: parent
                    onClicked: {
                        if (!fromField.readOnly){
                            fromField.text = ""
                        }
                    }
                }
            }
        }

        Button {
            id: arrows
            iconSource: "qrc:/arrows.svg"
            height: 50
            width: 50
            anchors.left: parent.left
            anchors.leftMargin: mainFlickable.left_margin
            anchors.top: fromField.bottom
            onClicked: {
                //var toTemp = new String;
               // stretchArrows.start();
                var toTemp = toField.text;
                toField.text = fromField.text;
                fromField.text = toTemp;
            }
            PropertyAnimation {
                id: stretchArrows
                target: arrows
                properties: "opacity"
                onCompleted: unstretchArrows.start()
                to: "60"
                duration: 40
                //easing: Easing.InQuart
            }
            PropertyAnimation {
                id: unstretchArrows
                target: arrows
                properties: "height"
                to: "50"
                duration: 40
                //easing: Easing.InQuart
            }
        }
        Row {
            id: timeExtra
            anchors.top: fromField.bottom
            anchors.left: arrows.right
            anchors.leftMargin: 20
            anchors.bottom: toField.top
            spacing: 8
            Switch {
                id: toFromSwitch
            }
            Text {
                color: "white"
                text: toFromSwitch.checked ? "Arrive" : "Depart"
                width: 70
                font.pixelSize: 25
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                color: "white"
                text: "at"
                font.pixelSize: 25
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle {
                id: timeDisplay
                anchors.verticalCenter: parent.verticalCenter
                border.color: "grey"
                border.width: 2
                color: "black"
                height: timeText.height +4
                width: timeText.width +8
                radius: 10
                Text {
                    id: timeText
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: Qt.formatDateTime(new Date(),"hh:mm")
                    color: "white"
                    font.pixelSize: 27
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        tDialog.hour = parseInt(timeText.text.substring(0,2));
                        tDialog.minute = parseInt(timeText.text.substring(3));
                        tDialog.open()
                        console.debug(parseInt(timeText.text.substring(3)))
                    }
                    onPressed: toAnimation.start()
                    onReleased: backAnimation.start()
                    onExited: backAnimation.start()
                }
                //ColorAnimation on color {duration: 4000; onCompleted: backAnimation.start()}
                ColorAnimation {id: toAnimation; target: timeDisplay; property: "color"; to: "#2b8adc"; duration: 20 }
                ColorAnimation {id: backAnimation; target: timeDisplay; property: "color"; to: "black"; duration: 200 }
            }

        }
        TimePickerDialog {
            id: tDialog
            titleText: "Time:"
            acceptButtonText: "Ok"
            rejectButtonText: "Cancel"
            fields: DateTime.Hours | DateTime.Minutes;
            onAccepted: timeText.text = hour + ":" + (minute < 10 ? "0" + minute : minute)
        }

        TextField {
            id: toField
            width: parent.width - mainFlickable.left_margin - mainFlickable.right_margin
            height: 70
            placeholderText: "To"
            focus: false
            anchors.top: arrows.bottom
            anchors.left: parent.left
            anchors.leftMargin: mainFlickable.left_margin
            anchors.rightMargin: mainFlickable.right_margin
            onTextChanged: {
                if (toField.text.length > 0){
                    toAutoComplete.fetchedModel = reittiopas.getMatchingNames("TO",toField.text)
                } else toAutoComplete.fetchedModel = []
                errorHighlight = false;
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
                    onClicked: toField.text = ""
                }
            }
        }
        Connections {
            target: reittiopas
            onParsedGeocodeEmptySignal: mainFlickable.emptyGeocode(type)
        }
        function emptyGeocode(type){
            if (type == "TO"){
                toField.errorHighlight = true;
            } else if (type == "FROM"){
                fromField.errorHighlight = true;
            }
        }

        Button {
            property bool usingLocation: false;
            property bool haveLocation: false;


            id: locationButton
            height: 70
            width: 70
            iconSource:  "qrc:/img/location.jpg"
            anchors.left: fromField.right
            anchors.verticalCenter: fromField.verticalCenter
            onClicked: locationClicked()
        }
        /*ToolButton {
            id: showMore
            anchors.top: toField.bottom
            anchors.left: parent.left
            iconSource: "toolbar-add"
            onClicked: moreRect.height = 300
        }*/



        Button {
            id: haeButton
            anchors.top: toField.bottom
            anchors.topMargin: 5
            width: parent.width
            height: 100
            text: "Search"
            onClicked: reittiopas.routeQuery(fromField.text,toField.text, toFromSwitch.checked, timeText.text)
        }

        BusyIndicator {
            id: indicator1
            running: true
            anchors.bottom: locationButton.top
            anchors.horizontalCenter: locationButton.horizontalCenter
            height: 70
            width: 70
            visible: false
        }
        ListView {
            property variant fetchedModel

            id: fromAutoComplete
            width: fromField.width
            anchors.top: fromField.bottom
            anchors.horizontalCenter: fromField.horizontalCenter
            anchors.leftMargin: 5
            clip: true

            height: fromField.activeFocus ? count > 0 ? count >= 10 ? 300 : count * 30 : 0 : 0 //  ListView.
            model: fetchedModel
            delegate: Rectangle{
                id:fromAutoCompleteRect
                width: parent.width
                height: 30
                color: "white"
                radius: 4
                Text {
                    anchors.fill: parent
                    anchors.leftMargin: 5
                    text: modelData
                }

                //ListView.onAdd: NumberAnimation { target: fromAutoCompleteRect; property: "height"; duration: 5000; to:50; easing.type: Easing.InOutQuad }
                //ListView.onRemove: NumberAnimation { target: fromAutoCompleteRect; property: "height"; duration: 2500; to:50; easing.type: Easing.InOutQuad }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        fromField.text = modelData
                        fromAutoComplete.fetchedModel = []
                    }
                onPressed: fromAutoCompleteRect.color = "#2b8adc";
                onReleased: fromAutoCompleteRect.color = "white";
                onCanceled: fromAutoCompleteRect.color = "white";
                }
                Image {
                    id: deleteAddress
                    source: "qrc:/img/remove_plain.svg"
                    height: 25
                    width: 25
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            reittiopas.deleteAddress(modelData)
                            fromAutoComplete.fetchedModel = reittiopas.getMatchingNames("FROM",fromField.text)
                        }
                    }
                }
            }
            //onModelChanged: NumberAnimation { target: fromAutoComplete.delegate; property: "height"; duration: 5000; easing.type: Easing.InOutQuad }
            //onModelChanged: NumberAnimation { target: fromAutoCompleteRect; property: "height"; duration: 5000; to:50; easing.type: Easing.InOutQuad }
        }
        ListView {
            property variant fetchedModel

            id: toAutoComplete
            width: toField.width
            anchors.top: toField.bottom
            anchors.horizontalCenter: toField.horizontalCenter
            height: toField.activeFocus ? count > 0 ? count >= 10 ? 300 : count * 30 : 0 : 0
            clip: true
            model: fetchedModel
            delegate: Rectangle{
                id:toAutoCompleteRect
                width: parent.width
                height: 30
                color: "white"
                radius: 4
                Text {
                    anchors.fill: parent
                    anchors.leftMargin: 5
                    text: modelData
                }

                //ListView.onAdd: NumberAnimation { target: fromAutoCompleteRect; property: "height"; duration: 5000; to:50; easing.type: Easing.InOutQuad }
                //ListView.onRemove: NumberAnimation { target: fromAutoCompleteRect; property: "height"; duration: 2500; to:50; easing.type: Easing.InOutQuad }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        toField.text = modelData
                        toAutoComplete.fetchedModel = []
                    }
                    onPressed: toAutoCompleteRect.color = "#2b8adc";
                    onReleased: toAutoCompleteRect.color = "white";
                    onCanceled: toAutoCompleteRect.color = "white";
                }
                Image {
                    id: deleteAddressTo
                    source: "qrc:/img/remove_plain.svg"
                    height: 25
                    width: 25
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            reittiopas.deleteAddress(modelData)
                            toAutoComplete.fetchedModel = reittiopas.getMatchingNames("TO",toField.text)
                        }
                    }
                }
            }
            //onModelChanged: NumberAnimation { target: fromAutoComplete.delegate; property: "height"; duration: 5000; easing.type: Easing.InOutQuad }
            //onModelChanged: NumberAnimation { target: fromAutoCompleteRect; property: "height"; duration: 5000; to:50; easing.type: Easing.InOutQuad }

        }
    }
    function locationClicked() {
        if (locationButton.usingLocation == false){
            gps.startPositioning()
            indicator1.visible = true
            fromField.text = "Locating..."
            fromField.readOnly = true;
            locationButton.iconSource = "qrc:/img/location_cancel.png"
            locationButton.usingLocation = true
            return;
        }
        if (locationButton.usingLocation == true ) {
            locationButton.iconSource = "qrc:/img/location.jpg"
            fromField.readOnly = false;
            if (locationButton.haveLocation == false) {
                fromField.text = "";
            }
            locationButton.usingLocation = false
            indicator1.visible = false;
            reittiopas.cancelLocation();
        }
    }

    SelectionDialog {
        property string type;
        property bool itemSelected;
        function showPlaceDialog(typeofsignal){
            console.log("Multiple dialogs called "+new String(typeofsignal))
            placeDialog.model = reittiopas.getPossibleList(typeofsignal) // testModel
            console.log ( reittiopas.getPossibleList(typeofsignal));
            type = typeofsignal;
            if (type == "TO"){
                placeDialog.titleText = "To:"
            }
            if (type == "FROM"){
                placeDialog.titleText = "From:"
            }

           // var list = reittiopas.getPossibleListTo()
            //console.log(list.rowCount())
            itemSelected = false;
            placeDialog.open()
        }
        Connections {
            target: reittiopas
            onMultipleChoicesForLocationSignal: placeDialog.showPlaceDialog(typeofsignal) //type)
        }
        id: placeDialog
        height: 300
        onAccepted: {
            placeDialog.close();
            itemSelected = true;


            //reittiopas.multipleChoicesSelected(selectedIndex,type);
        }
        onRejected: {
            reittiopas.multipleChoicesRejected();
        }

        onStatusChanged: statusFunction(status)

        function statusFunction(status) {
            if (status === DialogStatus.Closed && itemSelected){
                if(type == "TO"){
                    toField.text = selectedIndex.valueOf
                } else if (type == "FROM"){
                    fromField.text = selectedIndex.valueOf
                }
                reittiopas.multipleChoicesSelected(selectedIndex,type);
            }
        }

        //delegate: addressDelegate
    }
    QueryDialog {
        id: errorDialog
        message: "Error fetching address!\n"
        titleText: "Error!"
        rejectButtonText: "Ok"
        icon: "qrc:/img/location_cancel.png"

        Connections {
            target: reittiopas
            onReverseGeocodeError: {
                indicator1.visible = false;
                fromField.text = "";
                locationButton.iconSource = "qrc:/img/location.jpg"
                locationButton.usingLocation = false
                fromField.readOnly = false;
                errorDialog.open()
            }
        }
    }
}
