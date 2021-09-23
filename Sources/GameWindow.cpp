//
// Created by cuadriante on 6/9/21.
//


#include "../Headers/GameWindow.h"
#include "../Headers/PlayerBar.h"
#include "../Headers/Client.h"
#include "../Headers/Block.h"
#include "../Headers/Ball.h"


GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    //initialization
    scene = new QGraphicsScene(0,0,600,600);
    setScene(scene);

}

void GameWindow::start() {
    //create player bar
    PlayerBar * playerBar = new PlayerBar();
    playerBar->setPos(300,550);
    scene->addItem(playerBar);
    playerBar->setFlag(QGraphicsItem::ItemIsFocusable);
    playerBar->setFocus();

    // create initial ball
    Ball* ball = new Ball();
    ball->setPos(200,500);
    scene->addItem(ball);


//    Client client(this);
//    if (client.start()) {
//        client.play();
//    }





}
void GameWindow::addBlock(int x, int y) {
    Block * block = new Block();
    block->setPos(x,y);
    scene->addItem(block);
}
