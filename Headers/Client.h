//
// Created by cuadriante on 19/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_CLIENT_H
#define DATOSII_PROYECTOI_CLIENT_CLIENT_H

/** @brief Client class used for communication with server.

    Connects to server and sends and receives commands.
    @author cuadriante
    @date September 2021
    */

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h> //librerias para red
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h> // threads for multiprogramming
#include <vector> //para almacenar varios clientes
#include <unistd.h>
#include <QDebug>
#include <fcntl.h>
#include "Socket.h"

using namespace std;

class Client{

private:
    int clientSocketId; /**<initial client socket id*/
    struct sockaddr_in clientSocketInfo; /**<initial client socket information*/
    int clientSocketInfoLen = sizeof(clientSocketInfo); /**<initial length of client socket information*/
    int serverSocketPort = 4050; /**<initial server socket port*/
    Socket * clientSocket; /**<initial client socket*/

public:
    /**Constructor.
     *
     */
    Client();
    /**Connects socket to server.
     *
     * @return
     */
    bool connectSocket();
    /** Returns command comming from server.
     *
     * @return
     */
    Command * getNextCommand();
    /** Returns client socket.
     *
     * @return
     */
    Socket *getClientSocket() const;
};


#endif //DATOSII_PROYECTOI_CLIENT_CLIENT_H
