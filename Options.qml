import QtQuick 2.4
import QtQuick.Window 2.0

OptionsForm {
    id: optionsWindow
    width: (widthWindow - 20)
    height: (heightWindow - 20)
    property int textTypeInt: 0
    property bool optionsButtons: true

    normalButton.onClicked: {
        gameModeBool = false
        console.log(gameModeBool)
    }

    practiceButton.onClicked: {
        gameModeBool = true
        console.log(gameModeBool)
    }

    fontTypeButton.onWheel: {
        if (wheel.angleDelta.y < 0){ //Roll down
            if (textTypeInt > 0){
                textTypeInt--
            }
        }
        else {                      // Roll up
            if (textTypeInt < 4){
                textTypeInt++
            }
        }
        switch(textTypeInt) {
        case 0:
            textType = "Verdana";
            break;
        case 1:
            textType = "Arial";
            break;
        case 2:
            textType = "Times New Roman";
            break;
        case 3:
            textType = "Tahoma";
            break;
        case 4:
            textType = "Courier";
            break
        }
    }

    fontSizeButton.onWheel: {
        if (wheel.angleDelta.y < 0){
            if (tileTextSize > 10){
                tileTextSize--
            }
        }
        else {
            if (tileTextSize < 50){
                tileTextSize++
            }
        }
    }

    classicButton.onClicked: {
        gameBoard.defineSetOfColors(1)
    }

    greenButton.onClicked: {
        gameBoard.defineSetOfColors(0)
    }

    brazilButton.onClicked: {
        gameBoard.defineSetOfColors(2)
    }

    franceButton.onClicked: {
        gameBoard.defineSetOfColors(3)
    }

    x4Button.onClicked: {
        heightWindow = 400;
        widthWindow = 290;
    }

    quitButton{
        onClicked: {optionsWindow.destroy();
                    mainButtons = true;}
    }

    infoButton.onClicked: {
                optionsButtons = false;
                var componentInfo = Qt.createComponent("Info.qml");
                console.log("Component Status:", componentInfo.status, componentInfo.errorString());
                var windowInfo = componentInfo.createObject(optionsWindow, {"x": 5, "y": 5});
        }

}
