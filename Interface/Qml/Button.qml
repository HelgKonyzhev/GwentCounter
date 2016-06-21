import QtQuick 1.1

Item {
    id: button
    property string imageSource: ""
    property string labelText: ""
    property string labelTextColor: ""
    property int labelFontSize: 50

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

    Rectangle {
        color: "green"
        opacity: 0.5
        anchors.fill: parent
    }

    signal clicked

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Component.onCompleted: {
        mouseArea.clicked.connect(clicked)
    }
}

