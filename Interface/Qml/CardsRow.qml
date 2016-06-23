import QtQuick 1.1
import "."

MouseArea {
    width: parent.width
    height: parent.height / 3

    id: mouseArea
    onPressed: {
        hightligt.visible = true
    }
    onReleased: {
        hightligt.visible = false
    }

    Rectangle {
        id: hightligt
        anchors.fill: parent
        color: "transparent"
        border.color: "yellow"
        border.width: 10
        visible: false
    }
}

