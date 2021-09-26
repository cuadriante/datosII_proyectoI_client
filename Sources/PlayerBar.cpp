//
// Created by cuadriante on 6/9/21.
//


#include "../Headers/PlayerBar.h"


PlayerBar::PlayerBar(QGraphicsItem *parent) {
    setRect(0, 0, 100, 15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);

}

void PlayerBar::keyPressEvent(QKeyEvent *event) {
    if(clientSocket == NULL){
        return;
    }
    if (event->key() == Qt::Key_Left) {
        Command c;
        c.setAction(c.ACTION_MOVE_LEFT);
        clientSocket->sendCommand(c);
        //setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_Right) {
        Command c;
        c.setAction(c.ACTION_MOVE_RIGHT);
        clientSocket->sendCommand(c);
        //setPos(x() + 10, y());
    }


}

double PlayerBar::getItemCenter() {
    return x() + rect().width() / 2;
}

int PlayerBar::getSize() const {
    return size;
}

void PlayerBar::setSize(int size) {
    PlayerBar::size = size;
}

Socket *PlayerBar::getClientSocket() const {
    return clientSocket;
}

void PlayerBar::setClientSocket(Socket *clientSocket) {
    PlayerBar::clientSocket = clientSocket;
}
