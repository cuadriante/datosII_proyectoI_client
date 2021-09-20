//
// Created by cuadriante on 3/9/21.
//

#include "../Headers/ClientSocket.h"

ClientSocket::ClientSocket() {

}

void ClientSocket::connectSocket() {
//    // create descriptor
//    descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    if (descriptor < 0){
//        cout << "Error: Could not create socket.";
//    }
//    info.sin_family = AF_INET;
//    info.sin_addr.s_addr = inet_addr("127.0.0.1"); // accepts anything
//    info.sin_port = ntohs(4050);
//    memset(&info.sin_zero, 0, sizeof(info.sin_zero)); //used to clean attribute, access directly to its direction
//
//    if ((connect(descriptor, (sockaddr *) &info, (socklen_t) sizeof(info))) < 0){
//        cout << "Error: could not connect to server." << endl;
//    }
//    cout << "Successfully connected to server." << endl;
//
//    pthread_t thread;
//    pthread_create(&thread, 0, ClientSocket::Controller, (void *)this);
//    pthread_detach(thread);
//}
//
//void ClientSocket::sendMessage(const char *msn) {
//    send(descriptor, msn, strlen(msn), 0);
//}
//
//string ClientSocket::readMessage() {
//    char buffer[bufferSize] = {0};
//    int readSize = read(descriptor, buffer, bufferSize);
//    cout << "readsize: " << readSize << endl;
//    cout << "buffer: " << buffer << endl;
//    cout << "message was read" << endl;
//    return buffer;
}


//void *ClientSocket::Controller(void *obj) {
//    ClientSocket* clientSocket = (ClientSocket *)obj;
//    while(true){
//        string message;
//        char buffer[bufferSize] = {0}; //number to be defined
//        // establecer condicion para cerrar el while
//        while(1){
//            clientSocket->readMessage();
// //            memset(buffer, 0, bufferSize);
// //            int bytes = recv(clientSocket->descriptor, buffer, bufferSize, 0);
// //            message.append(buffer, bytes);
// //            if (bytes <= 0){ //reads message
// //                close(clientSocket->descriptor);
// //                pthread_exit(NULL);
// //            }
// //            if (bytes < bufferSize){ // stops reading
// //                break;
// //            }
//        }
//        cout << message << endl;
//    }
//    close(clientSocket->descriptor);
//    pthread_exit(NULL);
//}
//
