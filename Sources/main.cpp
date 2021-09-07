#include <iostream>
#include "../Headers/ClientSocket.h"
#include "../Headers/GameWindow.h"
#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include "../Headers/KeyBindedRect.h"
#include <QGraphicsView>

ClientSocket* clientSocket;

void * runClient(void *){
    try{
        clientSocket->connectSocket();
    } catch(string ex){
        cout << ex << endl;
    }
    pthread_exit(NULL);
}

int main(int argc, char** argv) {

    clientSocket = new ClientSocket;
    pthread_t clientThread;
    pthread_create(&clientThread, 0, runClient, NULL);
    pthread_detach(clientThread);

    string json = "hh"; // placeholder para el json que vamos a usar

    while(1){
        string msn;
        cin >> msn;
        if (msn == "start") {
            cout << "Game start" << endl;
            QApplication app(argc, argv); // todo esto hay que pasarlo a su propia funcion
            QGraphicsScene * scene = new QGraphicsScene();
            KeyBindedRect * rectItem = new KeyBindedRect();
            rectItem->setRect(0,0,100,10);
            scene->addItem(rectItem);// esto deberia hacerse cuando lo llama el server
            // hacer que el item sea el focus, porque solo asi puede edtectar keybinds
            rectItem->setFlag(QGraphicsItem::ItemIsFocusable);
            rectItem->setFocus();
            QGraphicsView * view = new QGraphicsView(scene);
            view->show(); // invisible by default



            //QPushButton button("Hello world !");
            //button.show();
            //GameWindow(app.);

            return app.exec();
        }
        if (msn == "exit"){
            break;
        }
        clientSocket->setMessage(json.c_str());
    }
    delete clientSocket;
    return 0;
}
