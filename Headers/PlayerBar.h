//
// Created by cuadriante on 6/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H
#define DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H

/** @brief PlayerBar class used for displaying player.

    Used for player to move horizontally using keys.
    @author cuadriante
    @date September 2021
    */

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
#include "Socket.h"



class PlayerBar: public QGraphicsRectItem{
private:
    int size; /**<initial size*/
    Socket * clientSocket = NULL; /**<initial client socket*/

public:
    /** Constructor. Initiallizes rect item.
     *
     * @param parent
     */
    PlayerBar(QGraphicsItem *parent=NULL);

    /** Key Press event. CHecks for left and right keyboard click and moves paddle.
     *
     * @param event
     */
    void keyPressEvent (QKeyEvent * event);

    /** Returns size.
     *
     * @return
     */
    int getSize() const;

    /** Size setter.
     *
     * @param size
     */
    void setSize(int size);
    /** Returns client socket.
     *
     * @return
     */
    Socket *getClientSocket() const;
    /** Sets client socket.
     *
     * @param clientSocket
     */
    void setClientSocket(Socket *clientSocket);
};


#endif //DATOSII_PROYECTOI_CLIENT_PLAYERBAR_H
