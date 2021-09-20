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

using namespace std;

class Client {
private:
    int clientSocketId;
    struct sockaddr_in clientSocketInfo;
    int clientSocketInfoLen = sizeof(clientSocketInfo);
    int serverSocketPort = 4050;
public:
    bool start();
    void play();

};


#endif //DATOSII_PROYECTOI_CLIENT_CLIENT_H
