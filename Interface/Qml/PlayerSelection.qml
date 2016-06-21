import QtQuick 1.1

Item {
    width: windowWidth
    height: windowHeight / 3

    property string labelText: ""

    Text {
        text: labelText
        font.pixelSize: 50
        font.bold: true
        color: "white"
        anchors.centerIn: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}

