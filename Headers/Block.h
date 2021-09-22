//
// Created by cuadriante on 21/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_BLOCK_H
#define DATOSII_PROYECTOI_CLIENT_BLOCK_H
#include <QGraphicsRectItem>
#include <QDebug>
#include <QKeyEvent>
#include <QBrush>

class Block: public QGraphicsRectItem {
private:
    int x;
    int y;
public:
    Block(QGraphicsItem *parent = NULL);


};

#endif //DATOSII_PROYECTOI_CLIENT_BLOCK_H
