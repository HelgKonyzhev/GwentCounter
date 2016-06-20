import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.XmlListModel 2.0


Rectangle {
    anchors.fill: parent
    color: "black"
    opacity: 0.9

    MouseArea {
        anchors.fill: parent
        onClicked: {
        }
    }

    XmlListModel {

        id: decks
        source: "../Decks/Nilfgaard.xml"
        query: "/Deck/card"
        XmlRole {name: "image"; query: "image/string()"}
        XmlRole {name: "name"; query: "name/string()"}

        Component.onCompleted: {
            for(var i = 0; i < count; i++) {
                cardsListModel.append()
            }
        }
    }

    Component {
        id: delegate
        Item {
            id: delegateItem
            width: parent.width / 3
            height: 300
            Image {
                width: 70 * 2
                height: 130 * 2
                source: image
                smooth: true
                anchors.centerIn: parent
            }
            MouseArea  {
                anchors.fill: parent
                onClicked: {
                    list.currentIndex = index
                }

                onDoubleClicked: {
                    console.log(name + " doubleclicked")
                }
            }
        }

    }
    GridView {
        cellWidth: parent.width / 3
        cellHeight: 300
        id: list
        anchors.fill: parent
        visible: true
        focus: true

        highlight: Rectangle {
            width: parent.width
            color: "blue"
        }

        model: decks
        delegate: delegate
    }
}
