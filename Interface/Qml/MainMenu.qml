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
            labelText: "Player1:<br>Geralt"
        }

        PlayerSelection {
            id: player2Selection
            labelText: "Player2:<br>Pissed farmer"
        }

        Button {
            id: startButton
            width: windowWidth
            height: windowHeight / 3

            labelText: "START"
            labelTextColor: "white"
        }
    }

    function gameStarted() {
        console.log("LET THE BATTLE BEGINS!!!")
    }

    Component.onCompleted: {
        startButton.clicked.connect(gameStarted)
    }
}

