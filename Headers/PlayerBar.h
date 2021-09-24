//
// Created by cuadriante on 6/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H
#define DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H

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


class PlayerBar: public QGraphicsRectItem{
public:
    PlayerBar(QGraphicsItem *parent=NULL);
    void keyPressEvent (QKeyEvent * event);
    double getItemCenter();
};


#endif //DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H
