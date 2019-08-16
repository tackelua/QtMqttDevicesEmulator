import QtQuick 2.0
import DhtEmulator 1.0

Item {
    property QtObject dhtEmulator: DhtEmulator {
    }
    property string hardwareId
    property bool infoVisible: false
    readonly property int fontSmall: 10
    readonly property int fontHovered: 12
    property int fontSize: fontSmall

    onHardwareIdChanged: dhtEmulator.hardwareId = hardwareId

    Rectangle {
        width: 50
        height: 30
        color: "transparent"
        clip: false

        Rectangle {
            anchors.fill: parent
            radius: 4
            color: "red"
            opacity: .5
        }

        Column {
            anchors.centerIn: parent

            Row {
                Text {
                    text: dhtEmulator.temperature.toFixed(2)
                    font.pixelSize: fontSize
                }
                Text {
                    text: "°C"
                    font.pixelSize: fontSize
                }
            }
            Row {
                Text {
                    text: dhtEmulator.humidity.toFixed(2)
                    font.pixelSize: fontSize
                }
                Text {
                    text: "%"
                    font.pixelSize: fontSize
                }
            }
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                fontSize = fontHovered
            }
            onExited: {
                fontSize = fontSmall
            }
        }
    }
}
