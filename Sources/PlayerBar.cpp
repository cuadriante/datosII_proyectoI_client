//
// Created by cuadriante on 6/9/21.
//


#include "../Headers/PlayerBar.h"


PlayerBar::PlayerBar(QGraphicsItem *parent) {
    setRect(0, 0, 100, 15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

}

void PlayerBar::keyPressEvent(QKeyEvent *event) {

    int posX = x();
    int posY = y();

    int prevx = posX;
    int prevy = posY;

    if(clientSocket == NULL){
        return;
    }
    if (event->key() == Qt::Key_Left) {
        posX = posX - 10;
        if (posX < 0) {
            posX = 0;
        }

    } else if (event->key() == Qt::Key_Right) {
        posX = posX + 10;
        if (posX > 500) {
            posX = 500;
        }
    }

    if (posX != prevx || posY != prevy) {
        setPos(posX, posY);
        Command c;
        c.setAction(c.ACTION_MOVE_PLAYER);
        c.setPosX(posX);
        c.setPosY(posY);
        clientSocket->sendCommand(c);
    }
}

int PlayerBar::getSize() const {
    return size;
}

void PlayerBar::setSize(int size) {
    setRect(0, 0, size, 15);
    PlayerBar::size = size;
}

Socket *PlayerBar::getClientSocket() const {
    return clientSocket;
}

void PlayerBar::setClientSocket(Socket *clientSocket) {
    PlayerBar::clientSocket = clientSocket;
}
