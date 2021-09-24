//
// Created by cuadriante on 19/9/21.
//

#include "../Headers/Client.h"


Client::Client() {
}

bool Client::connectSocket() {


    clientSocketId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocketId <= 0){
        cout << "Error: Could not create clientSocket" << endl;
        return false;
    }

    int opt = 1;

    if (setsockopt(clientSocketId, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        cout << "Error: Could not set clientSocket options." << endl;
        return false;
    }

    clientSocketInfo.sin_family = AF_INET;
    clientSocketInfo.sin_addr.s_addr = INADDR_ANY; // accepts anything
    clientSocketInfo.sin_port = htons(serverSocketPort);
    memset(&clientSocketInfo.sin_zero, 0, sizeof(clientSocketInfo.sin_zero)); //used to clean attribute, access directly to its direction

    if ((connect(clientSocketId, (sockaddr *) &clientSocketInfo, (socklen_t) sizeof(clientSocketInfo))) < 0){
        cout << "Error: could not connect to server." << endl;
        return false;
    }

// Put the socket in non-blocking mode:
    if(fcntl(clientSocketId, F_SETFL, fcntl(clientSocketId, F_GETFL) | O_NONBLOCK) < 0) {
        // handle error
        cout << "Error: Socket is nonblocking.";
        return false;
    }

    cout << "Successfully connected to server." << endl;

    this->clientSocket = new Socket(clientSocketId);




    return true;
}

Command * Client::getNextCommand() {

    Command *c = clientSocket->readCommand();
    return c;

}
