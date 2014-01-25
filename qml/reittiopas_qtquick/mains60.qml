import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
//import QtQuick 1.1

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
        color: "black"
        anchors.fill: parent
        Text {
            id: titletext
            text: "Reittiopas for Symbian"
            color: "white"
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.horizontalCenter: parent.horizontalCenter
        }
        AddressField {
            id: fromField
            anchors.top: titletext.bottom
            width: parent.width
            anchors.topMargin: 20
            textName: "From:"
            onTextChanged: {
                if (fromField.text.length > 0){
                    fromAutoComplete.fetchedModel = reittiopas.getMatchingNames("FROM",fromField.text)
                } else {
                    fromAutoComplete.fetchedModel = []
                }
                console.debug("fromfield activeFocus: " +(fromField.activeFocus))
                errorHighlight = false
            }
        }
        /*
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
        }*/
        Rectangle{
            id: arrowsWrapper
            height: arrows.height + 6
            width: arrows.width + 8
            radius: 20
            anchors.left: parent.left
            anchors.leftMargin: mainFlickable.left_margin
            anchors.top: fromField.bottom
            anchors.topMargin: 5
            color: "black"
            Image {
                id: arrows
                source: "qrc:/arrows.svg"
                height: 45
                width: 45
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        //var toTemp = new String;
                       // stretchArrows.start();
                        console.debug(fromField.text)
                        var toTemp = toField.text;
                        toField.text = fromField.text;
                        fromField.text = toTemp;
                    }
                    onPressed: toAnimation.start()
                    onReleased: backAnimation.start()
                    onExited: backAnimation.start()
                }
                //ColorAnimation on color {duration: 4000; onCompleted: backAnimation.start()}
                ColorAnimation {id: toAnimation; target: arrowsWrapper; property: "color"; to: "#2b8adc"; duration: 20 }
                ColorAnimation {id: backAnimation; target: arrowsWrapper; property: "color"; to: "black"; duration: 200 }
            }
        }
        AddressField {
            id: toField
            anchors.top: arrowsWrapper.bottom

            width: parent.width
            textName: "To:"
            onTextChanged: {
                if (toField.text.length > 0){
                    toAutoComplete.fetchedModel = reittiopas.getMatchingNames("TO",toField.text)
                } else {
                    toAutoComplete.fetchedModel = []
                }
                console.debug("tofield activeFocus: " +(toField.activeFocus))
                errorHighlight = false
            }
        }
        Rectangle {
            id: searchButton
            width: parent.width
            height: 70
            anchors.top: toField.bottom
            anchors.topMargin: 5
            color: "#202020"
            radius: 25
            //gradient: normalButton
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                //verticalAlignment: parent.verticalCenter
                text: "Search"
                color: "white"
                font.pixelSize: 35
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    reittiopas.routeQuery(fromField.text,toField.text);
                    setLoadingOn();
                    //cppRoot.setPage("routeList");
                }
                onPressed: toAnimationSearch.start()
                onReleased: backAnimationSearch.start()
                onExited: backAnimationSearch.start()
            }
            ColorAnimation {id: toAnimationSearch; target: searchButton; property: "color"; to: "#2b8adc"; duration: 20 }
            ColorAnimation {id: backAnimationSearch; target: searchButton; property: "color"; to: "#202020";duration: 200 }
            Gradient {
                id: normalButton
                GradientStop { position: 1.0; color: "#101010"}
                GradientStop { position: 0.0; color: "#202020"}
            }
            Gradient {
                id: pressedButton
                GradientStop { position: 1.0; color: "#2b8adc" }
                GradientStop { position: 0.0; color: "#2b8afc" }
            }
        }
        Text {
            id: loadingText
            text: ""
            anchors.top: searchButton.bottom
            anchors.topMargin: 30
            anchors.horizontalCenter: parent.horizontalCenter
            color: "grey"
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
    Connections {
        target: reittiopas
        onParsedGeocodeEmptySignal: mainFlickable.emptyGeocode(type)
        onGotRoutes: setLoadingOff();
        onFromNameChanged: fromField.text = name;
        onToNameChanged: toField.text = name;
    }
    function emptyGeocode(type){
        if (type == "TO"){
            toField.errorHighlight = true;
        } else if (type == "FROM"){
            fromField.errorHighlight = true;
        }
        setLoadingOff();
    }
    function setLoadingOn(){
        loadingText.text = "Loading...";
    }
    function setLoadingOff(){
        loadingText.text = "";
    }

    /*

    BusyIndicator {
        id: indicator1
        running: true
        anchors.bottom: locationButton.top
        anchors.horizontalCenter: locationButton.horizontalCenter
        height: 70
        width: 70
        visible: false
    }*/
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
                    Qt.quit();
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
/*
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
}*/

