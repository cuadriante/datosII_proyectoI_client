//
// Created by cuadriante on 21/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_BLOCK_H
#define DATOSII_PROYECTOI_CLIENT_BLOCK_H

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




class Block: public QObject, public QGraphicsRectItem {
Q_OBJECT

private:
    int id;
    int type;
    int hitsToBreak;


public:
    Block(QGraphicsItem *parent = NULL);
    ~Block() override;

    int getType() const;

    void setType(int type);

    int getHitsToBreak() const;

    void setHitsToBreak(int hitsToBreak);

    int getId() const;

    void setId(int id);

};

#endif //DATOSII_PROYECTOI_CLIENT_BLOCK_H
