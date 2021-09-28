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

    QApplication app(argc, argv);

    gameWindow = new GameWindow();
    gameWindow->show();
    gameWindow->start();

    return app.exec();
}
