//
// Created by cuadriante on 22/9/21.
//

#include "../Headers/Ball.h"

//extern Game* gameWindow;

//extern GameWindow* gameWindow;



Ball::Ball(QGraphicsItem *parent){
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    // move up right initially
    Vx= 5;
    Vy = -5;

    //QTimer* timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //timer->start(50);
}

//void Ball::move() {
//
//    screenLimitCollision();
//    playerBarCollision();
//    //blockCollision();
//    moveBy(Vx, Vy);
//}
//
Ball::~Ball() {
//
}


//
//void Ball::screenLimitCollision(){
////    double gameWindowWidth = gameWindow->width();
////
////    if (mapToScene(rect().topLeft()).x() <= 0){
////        Vx = -1 * Vx;
////    }
////
////    if (mapToScene(rect().topRight()).x() >= gameWindowWidth){
////        Vx = -1 * Vx;
////    }
////
////    if (mapToScene(rect().topLeft()).y() <= 0){
////        Vy = -1 * Vy;
////    }
//}
//
////void Ball::playerBarCollision() {
////    QList<QGraphicsItem*> cItems = collidingItems();
////    for (size_t i = 0, n = cItems.size(); i < n; ++i){
////        PlayerBar* playerBar = dynamic_cast<PlayerBar*>(cItems[i]);
////        if (playerBar){
////            Vy = -1 * Vy;
////            double ballX = getItemCenter();
////            double paddleX = playerBar->getItemCenter();
////            double dvx = ballX - paddleX;
////            Vx = (Vx + dvx)/15;
////            return;
////        }
////    }
////}
//
//double Ball::getItemCenter() {
//    return x() + rect().width()/2;
//
//}
//
//void Ball::blockCollision() {
////    QList<QGraphicsItem*> cItems = collidingItems();
////    for (size_t i = 0, n = cItems.size(); i < n; ++i){
////        Block* block = dynamic_cast<Block*>(cItems[i]);
////        // collides with block
////        if (block){
////            double yPad = 15;
////            double xPad = 15;
////            double ballx = pos().x();
////            double bally = pos().y();
////            double blockx = block->pos().x();
////            double blocky = block->pos().y();
////
////            // collides from bottom
////            if (bally > blocky + yPad && Vy < 0){
////                Vy = -1 * Vy;
////            }
////
////            // collides from top
////            if (blocky > bally + yPad && Vy > 0 ){
////                Vy = -1 * Vy;
////            }
////
////            // collides from right
////            if (ballx > blockx + xPad && Vx < 0){
////                Vx = -1 * Vx;
////            }
////
////            // collides from left
////            if (blockx > ballx + xPad && Vx > 0){
////                Vx = -1 * Vx;
////            }
////
////            // delete block(s)
////            gameWindow->scene->removeItem(block);
////            delete block;
////        }
////    }
//
//}
