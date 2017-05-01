import QtQuick 2.5
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

Window{
    width: 512
    height: 512
    title: "Map"
    visible: true

//    PositionSource {
//        active: true
//        nmeaSource: "qrc:/log.nmea"
//        onPositionChanged: {
//            map.center = position.coordinate;
//            console.log(position.coordinate);
//        }
//    }

    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin { name: "osm" }
        center: QtPositioning.coordinate(-27.4723,153.0354) // Brisbane
        zoomLevel: 10

        MapQuickItem {
            id: marker
            coordinate: QtPositioning.coordinate(-27.4723,153.0354) // Brisbane
            sourceItem: Image {
                id: mkrimg
                source: "qrc:/Images/marker.png"
            }
            anchorPoint.x: mkrimg.width/2
            anchorPoint.y: mkrimg.height
        }
    }

//    GeocodeModel {
//        plugin: map.plugin
//        query: "Sandakerveien 116, Oslo"
//        onLocationsChanged: {
//            console.log(Position.coordinate)
//            if( count )
//                marker.coordinate = get(0).coordinate;
//        }
//        Component.onCompleted: update()
//    }

}
