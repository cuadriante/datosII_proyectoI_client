//
// Created by cuadriante on 21/9/21.
//

#include "../Headers/Block.h"
#include "../Headers/Command.h"

//extern GameWindow* gameWindow;

Block::Block(QGraphicsItem *parent) {
    setRect(0,0,100,15);

}

Block::~Block() {

}

int Block::getType() const {
    return type;
}

void Block::setType(int type) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    Command c;
    qDebug() << type;
    switch(type){
        case c.BLOCK_TYPE_COMMON:{
            brush.setColor(Qt::gray);
            break;
        }
        case c.BLOCK_TYPE_DOUBLE:{
            brush.setColor(Qt::darkCyan);
            break;
        }
        case c.BLOCK_TYPE_TRIPLE:{
            brush.setColor(Qt::blue);
            break;
        }
        case c.BLOCK_TYPE_INTERNAL:{
            brush.setColor(Qt::darkBlue);
            break;
        }
        case c.BLOCK_TYPE_DEEP:{
            brush.setColor(Qt::cyan);
            break;
        }
        case c.BLOCK_TYPE_SURPRISE:{
            brush.setColor(Qt::magenta);
            break;
        }

    }

    setBrush(brush);
    Block::type = type;
}

int Block::getHitsToBreak() const {
    return hitsToBreak;
}

void Block::setHitsToBreak(int hitsToBreak) {
    Block::hitsToBreak = hitsToBreak;
}


