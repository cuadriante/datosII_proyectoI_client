//
// Created by cuadriante on 6/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H
#define DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
#include <QDebug>
#include <QKeyEvent>
#include <QApplication>
#include <unistd.h>

#include "Client.h"
#include "../Headers/PlayerBar.h"
#include "../Headers/Block.h"
#include "../Headers/GameLoop.h"
#include "../Headers/Ball.h"

using namespace std;

class GameWindow: public QGraphicsView {
private:
    Ball * ball;
    vector<Block *> blocklist;
    PlayerBar * playerBar;
    QLabel * label;
    int totalPoints = 0;

public:
    //attributes
    QGraphicsScene * scene;
    // constructor
    GameWindow(QWidget* parent=NULL);
    void addBlock(int id, int x, int y, int type);
//    void receiveBlockToAdd(int x, int y);
//
//    void addBlockToScene(Block * block, int x, int y);
    void start();
    Ball *getBall() const;

    const vector<Block *> &getBlocklist() const;

    void setBlocklist(const vector<Block *> &blocklist);

    PlayerBar *getPlayerBar() const;

    void setPlayerBar(PlayerBar *playerBar);

    void setScoreLabel(int score);
};

#endif //DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H
