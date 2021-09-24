//
// Created by cuadriante on 19/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_CLIENT_H
#define DATOSII_PROYECTOI_CLIENT_CLIENT_H

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
    int clientSocketId;
    struct sockaddr_in clientSocketInfo;
    int clientSocketInfoLen = sizeof(clientSocketInfo);
    int serverSocketPort = 4050;
    Socket * clientSocket;
    //GameWindow * gameWindow;
public:
    Client();
    bool connectSocket();
    //void gameLoop();
    Command * getNextCommand();

};


#endif //DATOSII_PROYECTOI_CLIENT_CLIENT_H
