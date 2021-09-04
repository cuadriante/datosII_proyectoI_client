#include <iostream>
#include "ClientSocket.h"

ClientSocket* clientSocket;

void * runClient(void *){
    try{
        clientSocket->connectSocket();
    } catch(string ex){
        cout << ex << endl;
    }
    pthread_exit(NULL);
}

int main() {
    clientSocket = new ClientSocket;
    pthread_t clientThread;
    pthread_create(&clientThread, 0, runClient, NULL);
    pthread_detach(clientThread);

    string json = "Holi desde el cliente."; // placeholder para el json que vamos a usar

    while(1){
        string msn;
        cin >> msn;
        if (msn == "exit"){
            break;
        }
        clientSocket->setMessage(json.c_str());
    }
    delete clientSocket;
    return 0;
}
