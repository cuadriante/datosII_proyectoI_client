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
        switch(action){
            case Command::ACTION_CREATE_BLOCK: {
                int id = c->getId();
                int x = c->getPosX();
                int y = c->getPosY();
                int hitsToBreak = c->getSize();
                gameWindow->addBlock(id, x, y, c->getType(), hitsToBreak);
                break;
            }
            case Command::ACTION_MOVE_BALL: {
                int x = c->getPosX();
                int y = c->getPosY();
                gameWindow->getBall()->setX(x);
                gameWindow->getBall()->setY(y);
                break;
            }
            case Command::ACTION_MOVE_PLAYER: {
                int x = c->getPosX();
                int y = c->getPosY();
                int size = c->getSize();
                PlayerBar * playerBar = gameWindow->getPlayerBar();
                playerBar->setX(x);
                playerBar->setY(y);
                if (gameWindow->getSurpriseLabel()->isVisible()){
                    gameWindow->getSurpriseLabel()->setVisible(false);
                }
                break;
            }
            case Command::ACTION_MOVE_OTHER_PLAYER: {
                int x = c->getPosX();
                int y = c->getPosY();
                int size = c->getSize();
                int id = c->getId();
                while (id >= gameWindow->getOtherPlayers().size()){
                    Block * otherPlayerBar = new Block();
                    otherPlayerBar->setType(0);
                    gameWindow->getOtherPlayers().push_back(otherPlayerBar);
                    gameWindow->scene->addItem(otherPlayerBar);
                }
                Block * otherPlayer = gameWindow->getOtherPlayers().at(id);
                otherPlayer->setRect(x, y, size, 15);
                break;
            }
            case Command::ACTION_DELETE_BLOCK:{
                int id = c->getId();
                Block * block = gameWindow->getBlocklist().at(id);
                block->hide();
                if (block->getType() == Command::BLOCK_TYPE_SURPRISE){
                    gameWindow->setSurpriseLabel();
                }
                break;
            }
            case Command::ACTION_SET_SCORE: {
                if (gameWindow->getSurpriseLabel()->isVisible()){
                    gameWindow->getSurpriseLabel()->setVisible(false);
                }
                int score = c->getSize();
                gameWindow->setScoreLabel(score);
                break;
            }
            case Command::ACTION_SET_DEPTH_LEVEL: {
                int depthLevel = c->getSize();
                gameWindow->setDepthLabel(depthLevel);
                break;
            }
            case Command::ACTION_SET_PLAYER_BAR_SIZE: {
                int newSize = c->getSize();
                gameWindow->getPlayerBar()->setSize(newSize);
                break;
            }
            case Command::ACTION_END_GAME: {
                gameWindow->endGame();
                break;
            }
            case Command::ACTION_WIN_GAME: {
                gameWindow->setWon(true);
                gameWindow->endGame();
            }
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
