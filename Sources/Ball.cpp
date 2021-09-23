//
// Created by cuadriante on 22/9/21.
//

#include "../Headers/Ball.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

//extern Game* gameWindow;

extern GameWindow* gameWindow;

#include "../Headers/PlayerBar.h"
#include <QDebug>
#include <QKeyEvent>
#include <QBrush>
#include <QApplication>
#include <unistd.h>

Ball::Ball(QGraphicsItem *parent){
    setRect(0,0,25,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    // move up right initially
    Vx= 5;
    Vy = -5;

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Ball::move() {

    screenLimitCollision();
    playerBarCollision();
    //blockCollission();
    moveBy(Vx, Vy);
}

Ball::~Ball() {
//
}

void Ball::screenLimitCollision(){
    double gameWindowWidth = gameWindow->width();

    if (mapToScene(rect().topLeft()).x() <= 0){
        Vx = -1 * Vx;
    }

    if (mapToScene(rect().topRight()).x() >= gameWindowWidth){
        Vx = -1 * Vx;
    }

    if (mapToScene(rect().topLeft()).y() <= 0){
        Vy = -1 * Vy;
    }
}

void Ball::playerBarCollision() {
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        PlayerBar* playerBar = dynamic_cast<PlayerBar*>(cItems[i]);
        if (playerBar){
            Vy = -1 * Vy;
            double ballX = getItemCenter();
            double paddleX = playerBar->getItemCenter();
            double dvx = ballX - paddleX;
            Vx = (Vx + dvx)/15;
            return;
        }
    }
}

double Ball::getItemCenter() {
    return x() + rect().width()/2;

}
