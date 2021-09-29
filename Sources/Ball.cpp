//
// Created by cuadriante on 22/9/21.
//

#include "../Headers/Ball.h"


Ball::Ball(QGraphicsItem *parent){
    int radius = 15;
    setRect(-5,-5,radius,radius);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

}

Ball::~Ball() {
}

