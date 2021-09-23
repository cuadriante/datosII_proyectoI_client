//
// Created by cuadriante on 21/9/21.
//

#include "../Headers/Block.h"

Block::Block(QGraphicsItem *parent) {
    setRect(0,0,100,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

}
