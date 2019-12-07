import QtQuick 2.12
import QtQuick.Window 2.12
import com.app.DigitalBoard 1.0

Window {
    title: qsTr("Digital Board")
    visible: true
    visibility: Window.Maximized

    DigitalBoard {
       anchors.fill: parent
    }
}
