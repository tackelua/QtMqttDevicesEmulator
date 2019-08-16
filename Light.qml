import QtQuick 2.0
import LightEmulator 1.0

Item {
    property QtObject lighEmulator: LightEmulator {
    }
    property string hardwareId

    onHardwareIdChanged: lighEmulator.hardwareId = hardwareId

    Rectangle {
        width: 50
        height: width
        color: "transparent"
        Text {
            anchors.centerIn: parent
            text: "💡"
            color: lighEmulator.status ? "yellow" : "black"
            font {
                pixelSize: 50
                bold: true
            }
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
        }
    }
}
