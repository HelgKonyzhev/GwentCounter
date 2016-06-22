import QtQuick 1.0
import "./"

Item {
    id: mainWindow
    width: windowWidth
    height: windowHeight

    function getImagePath(image) {
        return "../Images/" + resolution + "/" + image + "/"
    }

    Image {
        id: background
        source: getImagePath("Field.jpg")
        anchors.fill: parent
    }

    MainMenu {
        id: mainMenu
        visible: true
    }

    function showMainMenu() {
        mainMenu.visible = true
    }

    function hideMainMenu() {
        mainMenu.visible = false
    }

    Component.onCompleted: {
        windowContext.showMainMenuSignal.connect(showMainMenu)
        windowContext.hideMainMenuSignal.connect(hideMainMenu)
    }
}
