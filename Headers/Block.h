//
// Created by cuadriante on 21/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_BLOCK_H
#define DATOSII_PROYECTOI_CLIENT_BLOCK_H
#include <QGraphicsRectItem>
#include <QDebug>
#include <QKeyEvent>
#include <QBrush>
#include <QGraphicsItem>

#include "GameWindow.h"

class Block: public QObject, public QGraphicsRectItem {
Q_OBJECT

public:
    Block(QGraphicsItem *parent = NULL);
    ~Block() override;
    void addBlockToGameWindow();
public slots:
    void draw();


};

#endif //DATOSII_PROYECTOI_CLIENT_BLOCK_H
