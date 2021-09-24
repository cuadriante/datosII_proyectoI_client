//
// Created by cuadriante on 22/9/21.
//

#include "../Headers/GameLoop.h"

extern GameWindow * gameWindow;

GameLoop::GameLoop(QGraphicsItem *parent) {


}


void GameLoop::loop() {
    //qDebug()  << ".";
    Command *c = client->getNextCommand();
    if (c != NULL){
        int action = c->getAction();
        if (action == c->ACTION_CREATE_BLOCK) {
            int x = c->getPosX();
            int y = c->getPosY();

            gameWindow->addBlock(x, y, c->getType());
        }
        if (action == c->ACTION_MOVE_BALL) {
            int x = c->getPosX();
            int y = c->getPosY();
            gameWindow->getBall()->setX(x);
            gameWindow->getBall()->setY(y);
        }
    }

}
GameLoop::~GameLoop() {

}

void GameLoop::receiveClient(Client *client) {
    this->client = client;

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(loop()));
    timer->start(50);

}
