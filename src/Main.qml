import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 480
    height: 320
    visible: true
    title: qsTr("github.com/tomaschochola/template-qt")

    TodoView {
        anchors.centerIn: parent
    }
}
