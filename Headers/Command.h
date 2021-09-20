//
// Created by cuadriante on 19/9/21.
//

#ifndef DATOSII_PROYECTOI_SERVER_COMMAND_H
#define DATOSII_PROYECTOI_SERVER_COMMAND_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree//json_parser.hpp>


using boost::property_tree::ptree;

class Command {
public:
    static const int ACTION_NONE = 0;
    static const int ACTION_MOVEPLAYER = 1;

    void writeToPtree(ptree * pt);
    void readFromPtree(ptree * pt);
    void setAction(int action);
    void setNewPlayerX(int newPlayerX);
    int getAction();
    int getNewPlayerX();

private:
    int action;
    int newPlayerX;


};


#endif //DATOSII_PROYECTOI_SERVER_COMMAND_H
