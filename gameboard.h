#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include <QDebug>
#include <QVector>
#include "tile.h"
#include <stdlib.h>
#include <time.h>

class GameBoard : public QObject
{
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = 0);
    ~GameBoard();

    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void newGame();

    Q_PROPERTY(int posX READ readPosX NOTIFY tileChanged)
    int readPosX();
    Q_PROPERTY(int posY READ readPosY NOTIFY tileChanged)
    int readPosY();
    Q_PROPERTY(QString tileNb READ readTileNb NOTIFY tileChanged)
    QString readTileNb();
    Q_PROPERTY(QString tileColor READ readTileColor NOTIFY tileChanged)
    QString readTileColor();
    Q_PROPERTY(QString tileTextColor READ readTileTextColor NOTIFY tileChanged)
    QString readTileTextColor();


signals:
    void tileChanged();

private:
    int indX = 0, indY = 0, indNb = 0, indColor = 0, indTextColor = 0;

    Tile* tiles[4][4];
    Tile* tilesQml[16];
    int* matrixNb[4][4];

    void verifyTiles();
    void refreshRef();
    void printInfo();
    void changePlaces(int i1, int j1, int i2, int j2);

    void createTiles();
    void deleteTiles();

    void verifyRight();
    void verifyRight2();
    void verifyLeft();
    void verifyUp();
    void verifyDown();

    void createNewTile();
};

#endif // GAMEBOARD_H
