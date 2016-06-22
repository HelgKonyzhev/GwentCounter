import QtQuick 1.1

MouseArea {
    id: button
    property string imageSource: ""
    property string labelText: ""
    property string labelTextColor: ""
    property string backgroundColor: ""
    property int labelFontSize: 50

    Rectangle {
        anchors.fill: parent
        color: backgroundColor
    }

    Image {
        anchors.fill: parent
        source: imageSource
    }

    Text {
        width: parent.width
        height: parent.height
        text: labelText
        font.pixelSize: labelFontSize
        color: labelTextColor
        font.bold: true
        anchors.centerIn: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}

