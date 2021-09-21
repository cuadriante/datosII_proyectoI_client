//
// Created by cuadriante on 2/9/21.
//

#include "../Headers/Socket.h"

Socket::Socket(int socketId) {
    this->socketId = socketId;

}

void Socket::sendMessage(string message) {
    send(socketId, message.c_str(), message.size(), 0);
}

string Socket::readMessage() {
    //char buffer[bufferSize] = {0}; //number to be defined
    string output(bufferSize, 0);


    int bytes_received = read(socketId, &output[0], bufferSize-1);
    if (bytes_received<0) {
        cout << "Failed to read message." << endl;
        return "";
    }
    output.resize(bytes_received);
    //output[bytes_received] = 0;
    return output;
}

void Socket::sendPtree(ptree *ptree) {
    ostringstream buff;
    write_json(buff, *ptree, false);
    string json = buff.str();
    sendMessage(json);
}

ptree * Socket::readPtree() {
    string json = readMessage();
    if (json.empty()){
        return NULL;
    }
    //cout << json << endl;
    //json = "{\"action\":\"1\",\"posX\":\"200\"}";
    ptree * pt = new ptree();
    istringstream is (json);
    read_json (is, *pt);
    return pt;

}

