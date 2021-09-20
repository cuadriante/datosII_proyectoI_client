//
// Created by cuadriante on 19/9/21.
//

#include "../Headers/Command.h"

void Command::writeToPtree(ptree *pt) {
    pt->put("action", action);
    pt->put("newPlayerX", newPlayerX);
}

void Command::readFromPtree(ptree *pt) {
    action = pt->get<int>("action", 0);
    newPlayerX = pt->get<int>("newPlayerX", 0);
}

void Command::setAction(int action) {
    this->action = action;

}

void Command::setNewPlayerX(int newPlayerX) {
    this->newPlayerX = newPlayerX;

}

int Command::getAction() {
    return action;

}

int Command::getNewPlayerX() {
    return newPlayerX;

}
