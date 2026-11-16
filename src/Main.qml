import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 480
    height: 320
    visible: true
    title: Qt.application.name

    GreetingView {
        anchors.centerIn: parent
    }
}
