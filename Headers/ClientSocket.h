//
// Created by cuadriante on 3/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_CLIENTSOCKET_H
#define DATOSII_PROYECTOI_CLIENT_CLIENTSOCKET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h> //librerias para red
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h> // threads for multiprogramming
#include <vector> //para almacenar varios clientes
#include <unistd.h>
using namespace std;


class ClientSocket {
public:
    ClientSocket();
    void connectSocket();
    void sendMessage(const char* msn);

    string readMessage();

private:
    int descriptor;
    sockaddr_in info;
    static const int bufferSize = 1024;
    static void* Controller(void*);
};


#endif //DATOSII_PROYECTOI_CLIENT_CLIENTSOCKET_H
