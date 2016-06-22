import QtQuick 1.1
import "."

Rectangle {
    id: mainMenu
    width: windowWidth
    height: windowHeight
    color: "black"
    opacity: 0.9

    Column {
        PlayerSelection {
            id: player1Selection
            labelText: "Player1:<br>Геральт"
        }

        PlayerSelection {
            id: player2Selection
            labelText: "Player2:<br>Завод<br>гвоздей"
        }

        Button {
            id: startButton
            width: windowWidth
            height: windowHeight / 3
            labelText: "START"
            labelTextColor: "white"
            backgroundColor: "yellow"
        }
    }

    function gameStarted() {
        console.log("LET THE BATTLE BEGINS!!!")
    }

    Component.onCompleted: {
        startButton.clicked.connect(gameStarted)
        windowContext.player1SetDeckSignal.connect(player1Selection.deckSet)
        windowContext.player2SetDeckSignal.connect(player2Selection.deckSet)
        player1Selection.next.connect(windowContext.player1SelectNextDeckSlot)
        player2Selection.next.connect(windowContext.player2SelectNextDeckSlot)
        player1Selection.back.connect(windowContext.player1SelectPrevDeckSlot)
        player2Selection.back.connect(windowContext.player2SelectPrevDeckSlot)
    }
}

