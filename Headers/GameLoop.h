//
// Created by cuadriante on 22/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_GAMELOOP_H
#define DATOSII_PROYECTOI_CLIENT_GAMELOOP_H

#include "GameWindow.h"

class GameLoop: public QObject, public QGraphicsRectItem {
    Q_OBJECT
private:
    Client * client;

public:
    GameLoop(QGraphicsItem *parent=NULL);
    ~GameLoop() override;
    void receiveClient(Client * client);

public slots:
    void loop();
};





#endif //DATOSII_PROYECTOI_CLIENT_GAMELOOP_H
