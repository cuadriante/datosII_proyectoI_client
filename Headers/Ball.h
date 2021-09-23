//
// Created by cuadriante on 22/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_BALL_H
#define DATOSII_PROYECTOI_CLIENT_BALL_H


#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "GameWindow.h"

class Ball: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Ball(QGraphicsItem *parent=NULL);
    ~Ball() override;

private:
    double Vx;
    double Vy;


public slots:
    void move();
    void screenLimitCollision();
    void playerBarCollision();
    double getItemCenter();
};


//class Ball: public QGraphicsRectItem{
//Q_OBJECT
//public:
//    // constructors
//    Ball(QGraphicsItem* parent=NULL);
//
//    // public methods
//    double getCenterX();
//
//public slots:
//    // public slots
//    void move();
//
//private:
//    // private attributes
//    double xVelocity;
//    double yVelocity;
//
//    // private methods
//    void screenLimitCollision();
//    void handlePaddleCollision();
//    void handleBlockCollision();
//};

#endif //DATOSII_PROYECTOI_CLIENT_BALL_H
