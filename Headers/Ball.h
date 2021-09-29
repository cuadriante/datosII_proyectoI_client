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
};

#endif //DATOSII_PROYECTOI_CLIENT_BALL_H
