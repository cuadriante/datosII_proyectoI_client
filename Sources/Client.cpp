//
// Created by cuadriante on 19/9/21.
//

#include "../Headers/Client.h"
#include "../Headers/Socket.h"
#include "../Headers/Command.h"

bool Client::start() {
    clientSocketId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocketId <= 0){
        cout << "Error: Could not create socket" << endl;
        return false;
    }

    int opt = 1;

    if (setsockopt(clientSocketId, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        cout << "Error: Could not set socket options." << endl;
        return false;
    }

    clientSocketInfo.sin_family = AF_INET;
    clientSocketInfo.sin_addr.s_addr = INADDR_ANY; // accepts anything
    clientSocketInfo.sin_port = htons(serverSocketPort);
    memset(&clientSocketInfo.sin_zero, 0, sizeof(clientSocketInfo.sin_zero)); //used to clean attribute, access directly to its direction

    if ((connect(clientSocketId, (sockaddr *) &clientSocketInfo, (socklen_t) sizeof(clientSocketInfo))) < 0){
        cout << "Error: could not connect to server." << endl;
    }
    cout << "Successfully connected to server." << endl;


    return true;
}

void Client::play() {
    Socket socket(clientSocketId);
    cout << "Game start." << endl;
    while(1){
        ptree * pt = socket.readPtree();
        if (pt != NULL) {
            Command command;
            command.readFromPtree(pt);
            int action = command.getAction();
            cout << "action: " << action << endl;
            cout << "posX: " << command.getNewPlayerX() << endl;
        }
    }
}
