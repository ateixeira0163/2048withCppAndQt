import QtQuick 2.4

Item {
    width: 270 //(widthWindow - 20)
    height: 380 //(heightWindow - 20)
    property alias x4Button: x4Button
    property alias quitButton: quitButton

    Rectangle {
        id: optionsRect
        width: 270
        height: 380

        anchors.fill: parent
        color: "#bbffa9"

        Text {
            id: textOptions
            color: "#044e08"

            text: "Options"
            font.bold: true
            font.family: "Arial"
            font.pointSize: 19
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
        }

        Rectangle {
            id: quitRectangle
            x: 232
            width: 30
            height: 30
            color: "#73d216"
            radius: 5
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            Text {
                id: text1
                color: "#044e08"
                text: qsTr("X")
                font.weight: Font.ExtraBold
                font.bold: true
                font.family: "Verdana"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 22
            }

            MouseArea {
                id: quitButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }

        Text {
            id: textSize
            y: 190
            color: "#044e08"
            text: qsTr("Size")
            anchors.left: parent.left
            anchors.leftMargin: 10
            font.family: "Verdana"
            fontSizeMode: Text.FixedSize
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 22
        }

        Rectangle {
            id: x4ButtonRect
            y: 226
            width: 120 //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.left: parent.left
            anchors.leftMargin: 10

            Text {
                id: x4Text
                width: 80
                height: 40
                color: "#044e08"
                text: qsTr("4x4")
                font.bold: true
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                font.pixelSize: 19
            }

            MouseArea {
                id: x4Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }

        Rectangle {
            id: x5ButtonRect
            x: -5
            y: 226
            width: 120 //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.right: parent.right
            anchors.rightMargin: 10
            Text {
                id: x5Text
                width: 80
                height: 40
                color: "#044e08"
                text: qsTr("5x5")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                anchors.fill: parent
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: x5Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }

        Rectangle {
            id: x6ButtonRect
            x: 8
            y: 277
            width: 120 //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.leftMargin: 10
            Text {
                id: x6Text
                width: 80
                height: 40
                color: "#044e08"
                text: qsTr("6x6")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                anchors.fill: parent
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: x6Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
            anchors.left: parent.left
        }

        Rectangle {
            id: x10ButtonRect
            x: 9
            y: 277
            width: 120 //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.right: parent.right
            anchors.rightMargin: 10
            Text {
                id: x10Text
                width: 80
                height: 40
                color: "#044e08"
                text: qsTr("10x10")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                anchors.fill: parent
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: x10Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }
    }
}
