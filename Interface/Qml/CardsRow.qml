import QtQuick 1.1
import "."

MouseArea {
    width: parent.width
    height: parent.height / 3

    property int rowId: 0

    id: mouseArea

    onPressed: {
        hightligt.visible = true
    }
    onReleased: {
        hightligt.visible = false
    }
    onClicked: {
        windowContext.selectedRow(rowId)
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

