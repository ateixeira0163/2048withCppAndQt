#include "gameboard.h"

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
    createTiles();
    refreshRef();
    tiles[0][0]->setNumber();

    qDebug() << "Object GameBoard created";
    tileChanged();
}

GameBoard::~GameBoard()
{
    deleteTiles();
    qDebug() << "Objects destroyed";
}

void GameBoard::moveRight()
{
    verifyRight2();
    createNewTile();
    tileChanged();
}

void GameBoard::moveLeft()
{  
    verifyLeft();
    createNewTile();
    tileChanged();
}

void GameBoard::moveUp()
{
    verifyUp();
    createNewTile();
    tileChanged();
}

void GameBoard::moveDown()
{
    verifyDown();
    createNewTile();
    tileChanged();
}

void GameBoard::verifyRight()
{
    Tile* temp[3];

    bool randomVal = false;

    for (int j = 0; j < 4; j++){              //line loop
            for (int i = 3; i > 0; i--){          //column loop
                if ((*matrixNb[i][j] == 0) && (*matrixNb[i-1][j] != 0)){
                    temp[0] = tiles[i][j];
                    //move line
                    for (int k = i; k > 0; k--){
                        tiles[k][j] = tiles[k-1][j];
                    }
                    tiles[0][j] = temp[0];
                    //True = call random function after 'for' loops
                    randomVal = true;
                    refreshRef();
                }
            if (((i == 3)||(i == 2)) && (*matrixNb[i][j] == 0) && (*matrixNb[i-1][j] == 0) && (*matrixNb[i-2][j] != 0)){
                qDebug() << "Case 2, i: " << i << "j: " << j;
                temp[0] = tiles[i][j];
                temp[1] = tiles[i-1][j];
                for (int k = i; k > 1; k--){
                    tiles[k][j] = tiles[k-2][j];
                }
                tiles[0][j] = temp[1];
                tiles[1][j] = temp[0];
                randomVal = true;
                refreshRef();
            }
            if ((i == 3) && (*matrixNb[i][j] == 0) && (*matrixNb[i-1][j] == 0) && (*matrixNb[i-2][j] == 0) && (*matrixNb[i-3][j] != 0)){
                qDebug() << "Case 3, i: " << i << "j: " << j;
                temp[0] = tiles[i][j];       //in case we make bigger grids...
                temp[1] = tiles[i-1][j];
                temp[2] = tiles[i-2][j];
                for (int k = i; k > 2; k--){
                    tiles[k][j] = tiles[k-3][j];
                }
                tiles[0][j] = temp[2];
                tiles[1][j] = temp[1];
                tiles[2][j] = temp[0];
                randomVal = true;
                refreshRef();
            }
            if ((*matrixNb[i][j] == *matrixNb[i-1][j]) && *matrixNb[i][j] != 0){
                qDebug() << "Case 4, i: " << i << "j: " << j;
                temp[0] = tiles[i][j];
                //move line
                for (int k = i; k > 0; k--){
                    tiles[k][j] = tiles[k-1][j];
                }
                tiles[0][j] = temp[0];
                //change values
                tiles[i][j]->multNumber();
                tiles[0][j]->resetTile();
                //True = call random function after 'for' loops
                randomVal = true;
                refreshRef();
                printInfo();
            }
        }
    }

    if (randomVal) {
        //chamar funcao aparecimento_tile_aleatorio
    }

}

void GameBoard::verifyRight2()
{
    for (int j = 0; j < 4; j++){
        for (int k = 0; k < 4; k++){ // Pour répéter 4 fois
            for (int i = 2; i >= 0; i--){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i+1][j] == 0){
                        changePlaces(i+1, j, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i+1][j] == *matrixNb[i][j]) && tiles[i+1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        tiles[i+1][j]->resetTile();
                        changePlaces(i+1, j, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::verifyLeft()
{
    for (int j = 0; j < 4; j++){
        for (int k = 0; k < 4; k++){ // Pour répéter 4 fois
            for (int i = 1; i < 4; i++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i-1][j] == 0){
                        changePlaces(i-1, j, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i-1][j] == *matrixNb[i][j]) && tiles[i-1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        tiles[i-1][j]->resetTile();
                        changePlaces(i-1, j, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::verifyUp()
{
    for (int i = 0; i < 4; i++){
        for (int k = 0; k < 4; k++){ // Pour répéter 4 fois
            for (int j = 1; j < 4; j++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i][j-1] == 0){
                        changePlaces(i, j-1, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i][j-1] == *matrixNb[i][j]) && tiles[i][j-1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        tiles[i][j-1]->resetTile();
                        changePlaces(i, j-1, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::verifyDown()
{
    for (int i = 0; i < 4; i++){
        for (int k = 0; k < 4; k++){ // Pour répéter 4 fois
            for (int j = 2; j >= 0; j--){
                if (*matrixNb[i][j] != 0){;
                    if (*matrixNb[i][j+1] == 0){
                        changePlaces(i, j+1, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i][j+1] == *matrixNb[i][j]) && tiles[i][j+1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        tiles[i][j+1]->resetTile();
                        changePlaces(i, j+1, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::createNewTile()
{
    srand(time(NULL)); // initialize the random
    QVector<int> vecRand;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (*matrixNb[i][j] == 0){
                vecRand << i << j; // Vector with all 0's cases
            }
        }
    }

    int randNumber = rand() % 2 + 1;
    int randIndex = rand() % (vecRand.length()/2 - 1);
    tiles[vecRand.at(randIndex)][vecRand.at(randIndex)+1]->setNumber(randNumber*2);
    refreshRef();
}

void GameBoard::newGame()
{
    deleteTiles();
    createTiles();
    refreshRef();
    tiles[0][0]->setNumber();
    tiles[1][0]->setNumber();
    tileChanged();
}

int GameBoard::readPosX()
{
    if (indX == 16){
        indX = 0;
    }
    return tilesQml[indX++]->getPosition(0);
}

int GameBoard::readPosY()
{
    if (indY == 16){
        indY = 0;
    }
    return tilesQml[indY++]->getPosition(1);
}

QString GameBoard::readTileNb()
{
    if (indNb == 16){
        indNb = 0;
    }
    return tilesQml[indNb++]->getNumber();
}

QString GameBoard::readTileColor()
{
    if (indColor == 16){
        indColor = 0;
    }
    return tilesQml[indColor++]->getColor();
}

QString GameBoard::readTileTextColor()
{
    if (indTextColor == 16){
        indTextColor = 0;
    }
    return tilesQml[indTextColor++]->getTextColor();
}

void GameBoard::verifyTiles()
{

    if (tilesQml[0]->getPosition(0) == 190){
        qDebug() << "Ops";
        tilesQml[0]->multNumber();
        tileChanged();
    }
}

void GameBoard::refreshRef()
{
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j]->setPosition(i*60 + 10, j*60 + 10);
            matrixNb[i][j] = tiles[i][j]->getRefNumber();
        }
    }
}

void GameBoard::printInfo()
{
    qDebug() << "matrixNb:";
    for (int j=0; j < 4; j++){
       qDebug() << *matrixNb[0][j] << "," << *matrixNb[1][j] << "," << *matrixNb[2][j] << "," << *matrixNb[3][j];
    }
}

void GameBoard::changePlaces(int i1, int j1, int i2, int j2)
{
    Tile* temp;
    temp = tiles[i1][j1];
    tiles[i1][j1] = tiles[i2][j2];
    tiles[i2][j2] = temp;
}

void GameBoard::createTiles()
{
    for (int i=0; i < 4 ; i++){
        for (int j=0; j < 4; j++){
            tiles[i][j] = new Tile(i*60 + 10, j*60 + 10);
            tilesQml[i + j*4] = tiles[i][j];
        }
    }
}

void GameBoard::deleteTiles()
{
    for (int i=0; i < 4 ; i++){
        for (int j=0; j < 4; j++){
            delete tiles[i][j];
        }
    }
}
