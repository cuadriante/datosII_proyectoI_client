//
// Created by cuadriante on 6/9/21.
//

#include "../Headers/KeyBindedRect.h"
#include <QDebug>
#include <QKeyEvent>

void KeyBindedRect::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10, y());
    }
    qDebug() <<"Key pressed.";


}
