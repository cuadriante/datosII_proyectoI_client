//
// Created by cuadriante on 22/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_BALL_H
#define DATOSII_PROYECTOI_CLIENT_BALL_H



#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
#include <QDebug>
#include <QKeyEvent>
#include <QApplication>
#include <unistd.h>



class Ball: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ball(QGraphicsItem *parent=NULL);
    ~Ball() override;

private:
    double Vx;
    double Vy;


public slots:
//    void move();
//    void screenLimitCollision();
//    void playerBarCollision();
//    void blockCollision();
//    double getItemCenter();
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
