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

    Field {
        id: field
        visible: false
    }

    MainMenu {
        id: mainMenu
        visible: true
    }

    function showMainMenu(show) {
        mainMenu.visible = show
    }

    function showField(show) {
        field.visible = show
    }

    Component.onCompleted: {
        windowContext.showMainMenuSignal.connect(showMainMenu)
        windowContext.showFieldSignal.connect(showField)
    }
}
