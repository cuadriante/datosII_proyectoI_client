//
// Created by cuadriante on 6/9/21.
//


#include "../Headers/PlayerBar.h"


PlayerBar::PlayerBar(QGraphicsItem *parent) {
    setRect(0,0,100,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);

}

void PlayerBar::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10, y());
    }


}

double PlayerBar::getItemCenter() {
    return x() + rect().width()/2;
}
