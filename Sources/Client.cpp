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
#include <fcntl.h>


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

//    while (true) {
    Command *c = clientSocket->readCommand();
    return c;
//    if (c != NULL) {
//        return c;
//    }
}
//
//            int action = c->getAction();
//            //cout << "received action" << action << endl;
//            //cout << "received id: " << c->getId() << endl;
 //           if (action == c->ACTION_CREATE_BLOCK) {
  //              int x = c->getPosX();
  //              int y = c->getPosY();


   //             gameWindow->addBlock(x, y);

   //        }
    //   }
//        QCoreApplication::processEvents();
//    }
//}

//void Client::gameLoop() {
//    cout << "." ;
//
//}


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
//                //GAMEWINDOW_SINGLETON->addBlockToScene(x, y);
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
