import QtQuick 2.9
import QtQuick.Controls 2.5
import LightEmulator 1.0

ApplicationWindow {
    id: appId

    visible: true
    width: sodo.implicitWidth
    height: sodo.implicitHeight
    title: qsTr("Dashboard")

    //    color: "transparent"
    Rectangle {
        Image {
            id: sodo
            source: "phongkhach.jpg"
        }
    }

    Rectangle {
        x: 64
        y: 410
        width: 50
        height: 30
        color: "transparent"

        Dht {
            hardwareId: "default"
            clip: false
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            //            onReleased: {
            //                print("Released")
            //                print(parent.x)
            //                print(parent.y)
            //            }
        }
    }

    Rectangle {
        x: 659
        y: 180
        width: 50
        height: 30
        color: "transparent"

        Dht {
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            //            onReleased: {
            //                print("Released")
            //                print(parent.x)
            //                print(parent.y)
            //            }
        }
    }

    Rectangle {
        x: 168
        y: 284
        width: 50
        height: width
        color: "transparent"
        Relays {
            id: relaysId
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                relaysId.status = !relaysId.status
            }
        }
    }

    Rectangle {
        x: 221
        y: 26
        width: 50
        height: width
        color: "transparent"
        Light {
            id: lightId
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                lightId.lighEmulator.status = !lightId.lighEmulator.status
            }
        }
    }

    Rectangle {
        x: 406
        y: 113
        width: 50
        height: width
        color: "transparent"
        Light {
            id: lightId1
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                lightId1.lighEmulator.status = !lightId1.lighEmulator.status
            }
        }
    }

    Rectangle {
        x: 510
        y: 161
        width: 50
        height: width
        color: "transparent"
        Light {
            id: lightId2
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                lightId2.lighEmulator.status = !lightId2.lighEmulator.status
            }
        }
    }

    Rectangle {
        x: 625
        y: 30
        width: 50
        height: width
        color: "transparent"
        Light {
            id: lightId3
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                lightId3.lighEmulator.status = !lightId3.lighEmulator.status
            }
        }
    }

    Rectangle {
        x: 693
        y: 112
        width: 50
        height: width
        color: "transparent"
        Light {
            id: lightId4
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                lightId4.lighEmulator.status = !lightId4.lighEmulator.status
            }
        }
    }

    Rectangle {
        x: 849
        y: 147
        width: 50
        height: width
        color: "transparent"
        Light {
            id: lightId5
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                lightId5.lighEmulator.status = !lightId5.lighEmulator.status
            }
        }
    }

    Rectangle {
        id: light6
        property QtObject deviceDetail
        x: 922
        y: 56
        width: 50
        height: width
        color: "transparent"
        Light {
            id: lightId6
            hardwareId: "default"
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: {
                lightId6.lighEmulator.status = !lightId6.lighEmulator.status
            }
            onReleased: {
                print("Released")
                print(parent.x)
                print(parent.y)
            }
        }
    }
}
