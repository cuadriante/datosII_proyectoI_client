//
// Created by cuadriante on 22/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_GAMELOOP_H
#define DATOSII_PROYECTOI_CLIENT_GAMELOOP_H

/** @brief GameLoop class used for game window thread.

    Creates thread for checking messages necessary for communication between server and client.
    @author cuadriante
    @date September 2021
    */

#include "GameWindow.h"

class GameLoop: public QObject, public QGraphicsRectItem {
    Q_OBJECT
private:
    Client * client; /**<initial client*/

public:
    /** Constructor.
     *
     * @param parent
     */
    GameLoop(QGraphicsItem *parent=NULL);
    /** Destructor.
     *
     */
    ~GameLoop() override;
    /** Gets client.
     *
     * @param client
     */
    void receiveClient(Client * client);

public slots:
    void loop();
};





#endif //DATOSII_PROYECTOI_CLIENT_GAMELOOP_H
