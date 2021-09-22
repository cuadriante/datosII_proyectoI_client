//
// Created by cuadriante on 19/9/21.
//

#include "../Headers/Client.h"
#include "../Headers/Socket.h"
#include "../Headers/Command.h"
#include "../Headers/GameWindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QBrush>
#include <QGraphicsRectItem>
#include <pthread.h> // threads for multiprogramming

Client::Client(GameWindow * gameWindow) {
    this->gameWindow = gameWindow;
}

bool Client::start() {
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
    }
    cout << "Successfully connected to server." << endl;

    this->clientSocket = new Socket(clientSocketId);




    return true;
}

void Client::play() {
    cout << "Game start." << endl;
//    pthread_t thread;
//    pthread_create(&thread, 0, Client::checkForMessages, (void *)this);
//    pthread_detach(thread);
    while (true) {
        Command *c = clientSocket->readCommand();
        if (c != NULL) {

            int action = c->getAction();
            //cout << "received action" << action << endl;
            cout << "received id: " << c->getId() << endl;
            if (action == c->ACTION_CREATE_BLOCK) {
                int x = c->getPosX();
                int y = c->getPosY();

                gameWindow->addBlock(x, y);

            }
        }
        QCoreApplication::processEvents();
    }
}

//void Client::process() {
//    cout << "Checking for messages." << endl;
//    while(1){
//        //ptree * pt = clientSocket.readPtree();
//        Command * c = clientSocket->readCommand();
//        if (c != NULL) {
//
//            int action = c->getAction();
//            //cout << "received action" << action << endl;
//            cout << "received id: " << c->getId() << endl;
//            if (action == c->ACTION_CREATE_BLOCK) {
//                int x = c->getPosX();
//                int y = c->getPosY();
//
//                //GAMEWINDOW_SINGLETON->addBlock(x, y);
//
//            }
//
////            Command command;
////            command.readFromPtree(pt);
////            int action = command.getAction();
////            cout << "action: " << action << endl;
////            cout << "posX: " << command.getNewPlayerX() << endl;
//        } else {
//          //  sleep(1);
//        }
//
//    }
//
//}
//
