import QtQuick 2.0
import RelaysEmulator 1.0

Item {
    property QtObject relaysEmulator: RelaysEmulator {
    }
    property string hardwareId
    property bool status: false

    onHardwareIdChanged: relaysEmulator.hardwareId = hardwareId
    onStatusChanged: relaysEmulator.status = status
    Connections {
        target: relaysEmulator
        onStatusChanged: status = relaysEmulator.status
    }
    Rectangle {
        width: 50
        height: width
        color: "transparent"
        Text {
            anchors.centerIn: parent
            text: "⏻"
            color: status ? "yellow" : "black"
            font {
                pixelSize: 50
                bold: true
            }
        }
    }
}
