import QtQuick 1.1
import "."

Rectangle {
    width: windowWidth
    height: windowHeight / 2.4
    color: "transparent"

    Rectangle {
        id: locker
        anchors.fill: parent
        opacity: 0.7
        color: "black"
    }

    function lock(lock) {
        locker.visible = lock
    }

    Component.onCompleted: {
        lock(true)
    }
}

