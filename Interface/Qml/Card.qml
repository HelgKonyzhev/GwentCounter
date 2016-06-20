import QtQuick 2.0
import QtQuick.Window 2.2

//Component {
//    id: cardDelegate
//    Item {
//        Image {
//            id: image
//            source: "../Images540x960/Нейтральные карты/neit_9.png"
//        }
//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                //            Qt.quit();
//            }
//        }
//    }
//}
Window {
    width: 80
    height: 130
    flags: "FramelessWindowHint"
    visible: true
    Image {
        anchors.fill: parent
        id: image
        source: "../Images540x960/Нейтральные карты/neit_9.png"
    }
}
