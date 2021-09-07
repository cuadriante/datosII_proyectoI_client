//
// Created by cuadriante on 6/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_KEYBINDEDRECT_H
#define DATOSII_PROYECTOI_CLIENT_KEYBINDEDRECT_H

#include <QGraphicsRectItem>


class KeyBindedRect: public QGraphicsRectItem{
public:
    void keyPressEvent (QKeyEvent * event);
};


#endif //DATOSII_PROYECTOI_CLIENT_KEYBINDEDRECT_H
