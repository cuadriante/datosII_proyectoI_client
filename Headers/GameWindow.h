//
// Created by cuadriante on 6/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H
#define DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>


class GameWindow: public QGraphicsView {

public:
    //attributes
    QGraphicsScene * scene;
    // constructor
    GameWindow(QWidget* parent=NULL);

    void addBlock(int x, int y);
    void start();

};

#endif //DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H
