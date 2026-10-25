import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 480
    height: 320
    visible: true
    title: qsTr("Template Qt")

    TodoView {
        anchors.centerIn: parent
    }
}
