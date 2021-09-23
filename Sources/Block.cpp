//
// Created by cuadriante on 21/9/21.
//

#include "../Headers/Block.h"

extern GameWindow* gameWindow;

Block::Block(QGraphicsItem *parent) {
    setRect(0,0,100,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

}

void Block::addBlockToGameWindow() {
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
    timer->start(50);

}


void Block::draw() {
    //gameWindow->addBlockToScene(this, x(), y());

}

Block::~Block() {

}


