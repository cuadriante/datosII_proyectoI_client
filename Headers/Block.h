//
// Created by cuadriante on 21/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_BLOCK_H
#define DATOSII_PROYECTOI_CLIENT_BLOCK_H

/** @brief Block class used for displaying blocks.

    Blocks with set type and qualities.
    @author cuadriante
    @date September 2021
    */

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




class Block: public QObject, public QGraphicsRectItem {
Q_OBJECT

private:
    int id; /**<initial id*/
    int type; /**<initial type*/
    int hitsToBreak; /**<initial hits to break*/


public:
    /** Constructor.
     *
     * @param parent
     */
    Block(QGraphicsItem *parent = NULL);
    /** Destructor.
     *
     */
    ~Block() override;
    /** Returns type.
     *
     * @return
     */
    int getType() const;
    /** Sets type.
     *
     * @param type
     */
    void setType(int type);
    /** Returns hits to break.
     *
     * @return
     */
    int getHitsToBreak() const;
    /** Sets hits to break.
     *
     * @param hitsToBreak
     */
    void setHitsToBreak(int hitsToBreak);
    /** Returns id.
     *
     * @return
     */
    int getId() const;
    /** Sets id.
     *
     * @param id
     */
    void setId(int id);

};

#endif //DATOSII_PROYECTOI_CLIENT_BLOCK_H
