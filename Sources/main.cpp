#include <iostream>
#include <sstream>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree//json_parser.hpp>
#include "../Headers/ClientSocket.h"
#include "../Headers/GameWindow.h"
#include <QApplication>
#include <QPushButton>
#include "../Headers/PlayerBar.h"
#include "../Headers/Command.h"
#include "../Headers/Socket.h"
#include "../Headers/Client.h"

ClientSocket* clientSocket;

//void * runClient(void *){
//    try{
//        clientSocket->connectSocket();
//        while(1){
//            clientSocket->readMessage();
//        }
//    } catch(string ex){
//        cout << ex << endl;
//    }
//    pthread_exit(NULL);
//}

GameWindow * gameWindow;

int main(int argc, char** argv) {
    Client client;
    if (client.start()) {
        client.play();
    }



//    clientSocket = new ClientSocket;
//    pthread_t clientThread;
//    pthread_create(&clientThread, 0, runClient, NULL);
//    //pthread_spi
//    pthread_detach(clientThread);
//    //string json = "hh"; // placeholder para el json que vamos a usar
//
//    while(1){
//        Socket socket();
//        Command command;
//        command.
//
//        string msn;
// //        cin >> msn;
// //       cout << msn << endl;
// //        if (msn == "start") {
// //            cout << "Game start" << endl;
// //            QApplication app(argc, argv); //  esto hay que pasarlo a su propia funcion
// //
// //            gameWindow = new GameWindow();
// //            gameWindow->show();
// //            gameWindow->start();
// //
// //            return app.exec();
// //        }
// //        if (msn == "exit"){
// //            break;
// //        }
// //        clientSocket->sendMessage(json.c_str());
//    }
//    delete clientSocket;
//    return 0;
}
