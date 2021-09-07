//
// Created by cuadriante on 6/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H
#define DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H

#include <QGraphicsRectItem>


class PlayerBar: public QGraphicsRectItem{
public:
    PlayerBar(QGraphicsItem *parent=NULL);
    void keyPressEvent (QKeyEvent * event);
};


#endif //DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H
