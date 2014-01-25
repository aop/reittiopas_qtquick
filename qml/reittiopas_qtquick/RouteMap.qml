// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1
import QtMobility.location 1.2
import "reittiopashelpers.js" as JS

Page {
    tools: ToolBarLayout {
             ToolButton { iconSource: "toolbar-back"; onClicked: pageStack.pop() }
         }

    property int routeIndex;
    onStatusChanged: {
           if(status == Component.Ready) {
               var routeLegsSize = reittiopas.routes[routeIndex].routelegs.length;
               for(var j = 0;j< routeLegsSize;i++){
                   var NewRouteLeg = Qt.createQmlObject('import QtMobility.location 1.2; MapPolyline {
                        id: routeline'+String(j)+'
                         border {color: "'+JS.getColorForVehicle()+'"; width: 4}}',map);
                   map.addMapObject(NewRouteLeg);


                   var size = reittiopas.routes[routeIndex].routelegs[0].routelegs.length;
                   for(var i = 0;i < size;i++){
                       console.debug("Creating new object for route");
                       var lon = reittiopas.routes[routeIndex].routelegs[0].routelegs[i].lon;
                       var lat = reittiopas.routes[routeIndex].routelegs[0].routelegs[i].lat;
                       console.debug(lon);
                       console.debug(lat);
                       var newObject = Qt.createQmlObject('import QtMobility.location 1.2; Coordinate {longitude: '+lon+'; latitude: '+lat+'}',
                            routeline);
                       routeline.addCoordinate(newObject);
                   }
               }
            }
        }

    Map {
        id: map
        plugin : Plugin {name : "nokia"}
        anchors.fill: parent
        size.width: parent.width
        size.height: parent.height
        zoomLevel: 12
        center: Coordinate {
            latitude: reittiopas.routes[routeIndex].routelegs[0].routelegs[0].lat
            longitude: reittiopas.routes[routeIndex].routelegs[0].routelegs[0].lon
        }
        MapPolyline {
            id: routeline
            border {color: "red"; width: 4}
        }

    }
    Component {

    }

        PinchArea {
              id: pincharea

              property double __oldZoom

              anchors.fill: parent

              function calcZoomDelta(zoom, percent) {
                 return zoom + Math.log(percent)/Math.log(2)
              }

              onPinchStarted: {
                 __oldZoom = map.zoomLevel
              }

              onPinchUpdated: {
                 map.zoomLevel = calcZoomDelta(__oldZoom, pinch.scale)
              }

              onPinchFinished: {
                 map.zoomLevel = calcZoomDelta(__oldZoom, pinch.scale)
              }
           }
        MouseArea {
              id: mousearea

              property bool __isPanning: false
              property int __lastX: -1
              property int __lastY: -1

              anchors.fill : parent

              onPressed: {
                 __isPanning = true
                 __lastX = mouse.x
                 __lastY = mouse.y
              }

              onReleased: {
                 __isPanning = false
              }

              onPositionChanged: {
                 if (__isPanning) {
                    var dx = mouse.x - __lastX
                    var dy = mouse.y - __lastY
                    map.pan(-dx, -dy)
                    __lastX = mouse.x
                    __lastY = mouse.y
                 }
              }

        }

}
