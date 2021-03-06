//
// Created by cuadriante on 19/9/21.
//

#include "../Headers/Command.h"

void Command::setAction(int action) {
    this->action = action;

}

void Command::setPosX(int newPlayerX) {
    this->posX = newPlayerX;

}

int Command::getAction() {
    return action;

}

int Command::getPosX() {
    return posX;

}

int Command::getPosY() const {
    return posY;
}

void Command::setPosY(int posY) {
    Command::posY = posY;
}

const string &Command::getName() const {
    return name;
}

void Command::setName(const string &name) {
    Command::name = name;
}

int Command::getType() const {
    return type;
}

int Command::getId() const {
    return id;
}

void Command::setId(int id) {
    Command::id = id;
}

void Command::setType(int type) {
    Command::type = type;
}


int Command::getSize() const {
    return size;
}

void Command::setSize(int size) {
    Command::size = size;
}
