//
// Created by cuadriante on 6/9/21.
//

#ifndef DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H
#define DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H

/** @brief GameWindow class used for displaying displaying game.

    Creates game window elements and displays them.
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

#include "Client.h"
#include "../Headers/PlayerBar.h"
#include "../Headers/Block.h"
#include "../Headers/GameLoop.h"
#include "../Headers/Ball.h"

using namespace std;

class GameWindow: public QGraphicsView {
    Q_OBJECT



private:
    Ball * ball; /**<initial ball*/
    vector<Block *> blocklist; /**<initial blockList*/
    PlayerBar * playerBar; /**<initial player bar*/
    vector<Block *> otherPlayers; /**<initial PlayerList*/
    QLabel * pointsLabel; /**<initial points label*/
    QLabel * depthLabel; /**<initial depth level label*/
    QLabel * surpriseLabel; /**<initial surprise label*/
    QLabel * titleLabel; /**<initial title label*/
    QLabel * playerLabel; /**<initial player label*/
    QString playerName; /**<initial player name string*/
    int totalPoints = 0; /**<initial total points*/
    int depthLevel = 0; /**<initial depth level*/
    QLineEdit *nameTextInput;
    QPushButton *nameInputButton;
    bool won = false;


public:
    QGraphicsScene * scene; /**Graphic scene*/
    /** Constructor
     *
     * @param parent
     */
    GameWindow(QWidget* parent=NULL);
    /** Adds block to game window.
     *
     * @param id
     * @param x
     * @param y
     * @param type
     */
    void addBlock(int id, int x, int y, int type, int hitsToBreak);
    /** Initializes game.
     *
     */
    void start();
    /** Returns ball.
     *
     * @return
     */
    Ball *getBall() const;
    /** Returns list of blocks in game.
     *
     * @return
     */
    const vector<Block *> &getBlocklist() const;
    /** Sets block list to be displayed.
     *
     * @param blocklist
     */
    void setBlocklist(const vector<Block *> &blocklist);
    /** Returns rect item to be moved by player.
     *
     * @return
     */
    PlayerBar *getPlayerBar() const;
    /** Sets rect item to be used by player.
     *
     * @param playerBar
     */
    void setPlayerBar(PlayerBar *playerBar);
    /** Sets score label, displays current points gained.
     *
     * @param score
     */
    void setScoreLabel(int score);
    /** Sets depth level, displays current.
     *
     * @param depthLevel
     */
    void setDepthLabel(int depthLevel);
    /** Sets surprise label when surprise block is destroyed.
     *
     */
    void setSurpriseLabel();
    /** Returns surprise label.
     *
     * @return
     */
    QLabel *getSurpriseLabel() const;
    /** Creates initial labels.
     *
     */
    void createLabels();

    vector<Block *> &getOtherPlayers();

    void askForPlayerName();
    void endGame();

    bool isWon() const;

    void setWon(bool won);

private slots:
    void clickedSlot();


};

#endif //DATOSII_PROYECTOI_CLIENT_GAMEWINDOW_H
