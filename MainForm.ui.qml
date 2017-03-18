import QtQuick 2.6

Rectangle {
    id: gameWindow
    width: 290
    height: (60*numberOfTiles + 160)
    color: gameBoard.colorOptionsQml
    property alias optionsButton: optionsButton
    property alias newGameButton: newGameButton
    property alias undoButton: undoButton
    property alias rectangleTiles: rectangleTiles

    Rectangle {
        id: optionsButtonRect
        x: 170
        y: 17
        width: 100
        height: 40
        color: gameBoard.colorOptionsQml
        radius: 5

        Text {
            id: textOptions
            color: gameBoard.colorOptionsQml
            text: qsTr("Options")
            font.bold: false
            fontSizeMode: Text.HorizontalFit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 19
        }

        MouseArea {
            id: optionsButton
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            visible: a
        }
    }

    Text {
        id: title2048
        color: gameBoard.colorOptionsQml
        text: qsTr("2048")
        font.bold: true
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 29
    }

    Rectangle {
        id: newGameButtonRect
        x: 170
        width: 100
        height: 40
        anchors.bottom: rectangleTiles.top
        anchors.bottomMargin: 30
        color: gameBoard.colorOptionsQml
        radius: 5

        Text {
            id: textNewGame
            color: gameBoard.colorOptionsQml
            text: qsTr("New Game")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 19
        }

        MouseArea {
            id: newGameButton
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            visible: a
        }
    }

    Text {
        id: undoText
        color: "#ff7e00"
        text: qsTr("Undo")
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.bottom: rectangleTiles.top
        anchors.bottomMargin: 5
        anchors.right: rectangleTiles.right
        anchors.rightMargin: 5
        font.pixelSize: 15

        MouseArea {
            id: undoButton
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            visible: a
        }
    }

    Rectangle {
        id: rectangleTiles
        y: 80
        width: (60*numberOfTiles + 10)
        height: (60*numberOfTiles + 10)
        color: gameBoard.colorOptionsQml //"#007615"
        radius: 15
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        Repeater {
            model: numberOfTiles*numberOfTiles
            Rectangle {
                x: gameBoard.posX
                y: gameBoard.posY
                Behavior on x { PropertyAnimation { duration: 100}}
                Behavior on y { PropertyAnimation { duration: 100}}
                width: 50
                height: 50
                color: gameBoard.tileColor
                radius: 5
                z: 1
                focus: true

                Text {
                    color: gameBoard.tileTextColor
                    text: gameBoard.tileNb
                    z: 2
                    fontSizeMode: Text.FixedSize
                    textFormat: Text.AutoText
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 24
                }
            }
        }

        Grid {
            x: 10
            y: 10
            rows: numberOfTiles
            columns: numberOfTiles
            spacing: 10

            Repeater {
                model: numberOfTiles*numberOfTiles
                Rectangle {
                    width: 50
                    height: 50
                    color: gameBoard.colorOptionsQml //"#054c0b"
                    radius: 5
                }
            }
        }

        Keys.onPressed: {
            switch (event.key) {
            case Qt.Key_Right:
                console.log("KeyRight pressed");
                gameBoard.moveRight();
                break;
            case Qt.Key_Left:
                console.log("KeyLeft pressed");
                gameBoard.moveLeft();
                break;
            case Qt.Key_Up:
                console.log("KeyUp pressed");
                gameBoard.moveUp();
                break;
            case Qt.Key_Down:
                console.log("KeyDown pressed");
                gameBoard.moveDown();
                break;
            }
        }
    }
}
