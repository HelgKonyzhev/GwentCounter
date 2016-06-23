import QtQuick 1.1
import "."

Item {
    width: windowWidth
    height: windowHeight / 3

    property string labelText: ""

    Item {
        id: deckSelection
        width: parent.width
        anchors.bottom: parent.bottom
        height: windowHeight / 10

        Button {
            id: backButton
            width: windowWidth / 10
            height: parent.height
            x: width
            labelFontSize: 18
            labelText: "BACK"
            labelTextColor: "white"
            anchors.bottom: parent.bottom
            backgroundColor: "green"
        }

        Button {
            id: nextButton
            width: windowWidth / 10
            height: parent.height
            x: parent.width - width * 2
            labelFontSize: 18
            labelText: "NEXT"
            labelTextColor: "white"
            anchors.bottom: parent.bottom
            backgroundColor: "green"
        }


        Item {
            width: windowWidth
            height: parent.height
            Row {
                height: parent.height
                anchors.centerIn: parent
                Image {
                    width: windowWidth / 10
                    height: parent.height
                    id: deckLogo
                }

                Text {
                    height: parent.height
                    id: deckAlias
                    font.pixelSize: 25
                    color: "white"
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    Text {
        y: 0
        height: deckSelection.y
        width: parent.width
        text: labelText
        font.pixelSize: 50
        font.bold: true
        color: "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    function deckSet(al, logo) {
        deckAlias.text = al
        deckLogo.source = getImagePath(logo)
    }

    signal next()
    signal back()

    Component.onCompleted: {
        backButton.clicked.connect(back)
        nextButton.clicked.connect(next)
    }
}

