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
    switch(type){
        case c.BLOCK_TYPE_COMMON:{
            //brush.setColor(Qt::lightGray);
            brush.setColor(Qt::gray);
            //brush.setColor(QColor(255,229,243));
            break;
        }
        case c.BLOCK_TYPE_DOUBLE:{
            brush.setColor(Qt::blue);
            //brush.setColor(Qt::gray);
            //brush.setColor(QColor(239,187,215));
            break;
        }
        case c.BLOCK_TYPE_TRIPLE:{
            brush.setColor(Qt::darkBlue);
            //brush.setColor(QColor(206,119,166));
            break;
        }
        case c.BLOCK_TYPE_INTERNAL:{
            brush.setColor(Qt::darkCyan);
            //brush.setColor(QColor(149,70,112));
            break;
        }
        case c.BLOCK_TYPE_DEEP:{
            brush.setColor(Qt::cyan);
            //brush.setColor(QColor(98,14,59));
            break;
        }
        case c.BLOCK_TYPE_SURPRISE:{
            brush.setColor(Qt::magenta);
            //brush.setColor(QColor(226,70,153));
            break;
        }
        case 0:{
            brush.setColor(Qt::darkGray);
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

int Block::getId() const {
    return id;
}

void Block::setId(int id) {
    Block::id = id;
}


