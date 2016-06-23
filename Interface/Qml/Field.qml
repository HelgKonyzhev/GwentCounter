import QtQuick 1.1
import "."

Rectangle {
    width: windowWidth
    height: windowHeight
    opacity: 1

    Image {
        id: background
        source: getImagePath("Field.jpg")
        anchors.fill: parent
    }


    PlayerField {
        id: player1Field
        anchors.top: parent.top
        signal selectedRowSignal(int rowId)
        Item {
            id: player1Rows
            anchors.fill: parent
            Column {
                anchors.fill: parent
                CardsRow {
                    onClicked: {
                        player1Field.selectedRowSignal(windowContext.getSageRowId())
                    }
                }
                CardsRow {
                    onClicked: {
                        player1Field.selectedRowSignal(windowContext.getRangedRowId())
                    }
                }
                CardsRow {
                    onClicked: {
                        player1Field.selectedRowSignal(windowContext.getMeleeRowId())
                    }
                }
            }
        }
        function lockRows(lock) {
            player1Rows.visible = !lock
        }
    }

    PlayerField {
        id: player2Field
        anchors.bottom: parent.bottom
        signal selectedRowSignal(int rowId)
        Item {
            id: player2Rows
            anchors.fill: parent
            Column {
                anchors.fill: parent
                CardsRow {
                    onClicked: {
                        player2Field.selectedRowSignal(windowContext.getMeleeRowId())
                    }
                }
                CardsRow {
                    onClicked: {
                        player2Field.selectedRowSignal(windowContext.getRangedRowId())
                    }
                }
                CardsRow {
                    onClicked: {
                        player2Field.selectedRowSignal(windowContext.getSageRowId())
                    }
                }
            }
        }
        function lockRows(lock) {
            player2Rows.visible = !lock
        }
    }

    CardsRow {
        id: weatherFiled
        width: windowWidth
        anchors.top: player1Field.bottom
        anchors.bottom: player2Field.top
    }

    function lockPlayerFiled(player, lock) {
        player.lock(lock)
        player.lockRows(lock)
    }

    function player1Turn() {
        lockPlayerFiled(player1Field, false)
        lockPlayerFiled(player2Field, true)
    }

    function player2Turn() {
        lockPlayerFiled(player1Field, true)
        lockPlayerFiled(player2Field, false)
    }

    Component.onCompleted: {
        windowContext.player1TurnSignal.connect(player1Turn)
        windowContext.player2TurnSignal.connect(player2Turn)
        player1Field.selectedRowSignal.connect(windowContext.player1SelectedRowSlot)
        player2Field.selectedRowSignal.connect(windowContext.player2SelectedRowSlot)
        weatherFiled.clicked.connect(windowContext.selectedWeatherSlot)
    }
}

