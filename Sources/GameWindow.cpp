//
// Created by cuadriante on 6/9/21.
//


#include "../Headers/GameWindow.h"



GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    //initialization
    scene = new QGraphicsScene(0,0,600,600);
    setScene(scene);

}

void GameWindow::start() {
    //create player bar
    playerBar = new PlayerBar();
    playerBar->setPos(300,550);
    scene->addItem(playerBar);
    playerBar->setFlag(QGraphicsItem::ItemIsFocusable);
    playerBar->setFocus();

    // create initial pBall
    ball = new Ball();
    ball->setPos(0, 700);
    scene->addItem(ball);


    Client* client = new Client();
    if (client->connectSocket()) {
        GameLoop * gameLoop = new GameLoop();
        scene->addItem(gameLoop);
        gameLoop->receiveClient(client);
        //client.getNextCommand();
    } else {
        cout << "Could not connect to server." << endl;
        exit;
    }
}





void GameWindow::addBlock(int x, int y, int type) {
    Block * block = new Block();
    block->setType(type);
    block->setPos(x,y);
    blocklist.push_back(block);
    scene->addItem(block);
}

Ball *GameWindow::getBall() const {
    return ball;
}

const vector<Block *> &GameWindow::getBlocklist() const {
    return blocklist;
}

void GameWindow::setBlocklist(const vector<Block *> &blocklist) {
    GameWindow::blocklist = blocklist;
}

