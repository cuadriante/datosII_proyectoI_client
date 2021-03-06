//
// Created by cuadriante on 22/9/21.
//

/** @brief Ball class used for displaying ball.

    Displays ball igame window in given coordinates.
    @author cuadriante
    @date September 2021
    */


#ifndef DATOSII_PROYECTOI_CLIENT_BALL_H
#define DATOSII_PROYECTOI_CLIENT_BALL_H



#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
#include <QDebug>
#include <QKeyEvent>
#include <QApplication>
#include <unistd.h>



class Ball: public QObject, public QGraphicsEllipseItem {

    Q_OBJECT

public:
    /** Constructor.
     *
     * @param parent
     */
    Ball(QGraphicsItem *parent=NULL);
    /** Destructor.
     *
     */
    ~Ball() override;

};

#endif //DATOSII_PROYECTOI_CLIENT_BALL_H
