import QtQuick 2.0
import QtQuick.Window 2.2

Window {
    visible: true

    width: 540
    height: 960

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("ASDASD")
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    flags: "FramelessWindowHint"

    Image {
        id: background
        source: "../Images540x960/Field.jpg"
        fillMode: Image.Stretch
    }

//    Card {
//        id: c
//        width: 80
//        height: 130
//    }

    SelectCardMenu {
    }
}

