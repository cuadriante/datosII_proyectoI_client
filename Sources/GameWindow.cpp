//
// Created by cuadriante on 6/9/21.
//


#include "../Headers/GameWindow.h"


GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    //initialization
    scene = new QGraphicsScene(0,0,600,600);
    setScene(scene);
    this->setWindowTitle("Crazy Breakout");

}

void GameWindow::start() {
    //create player bar
    playerBar = new PlayerBar();
    playerBar->setPos(700,700);
    scene->addItem(playerBar);
    playerBar->setFlag(QGraphicsItem::ItemIsFocusable);
    playerBar->setFocus();

    // create initial pBall
    ball = new Ball();
    ball->setPos(0, 700);
    scene->addItem(ball);

    // create points pointsLabel
    pointsLabel = new QLabel(this);
    pointsLabel->setText("Points: 0");
    pointsLabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    pointsLabel->setGeometry(470, 400, 100, 100);
    pointsLabel->setVisible(true);

    // create depth level label
    depthLabel = new QLabel(this);
    depthLabel->setText("Depth Level: 0");
    depthLabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    depthLabel->setGeometry(470, 380, 100, 100);
    depthLabel->setVisible(true);


    Client* client = new Client();
    if (client->connectSocket()) {
        GameLoop * gameLoop = new GameLoop();
        scene->addItem(gameLoop);
        playerBar->setClientSocket(client->getClientSocket());
        gameLoop->receiveClient(client);
    } else {
        cout << "Could not connect to server." << endl;
        exit;
    }
}

void GameWindow::addBlock(int id, int x, int y, int type) {
    Block * block = new Block();
    block->setId(id);
    block->setType(type);
    block->setPos(x,y);
    blocklist.push_back(block);
    scene->addItem(block);
}

Ball *GameWindow::getBall() const {
    return ball;
}

const vector<Block *> &GameWindow::getBlocklist() const {
    return blocklist;
}

void GameWindow::setBlocklist(const vector<Block *> &blocklist) {
    GameWindow::blocklist = blocklist;
}

PlayerBar *GameWindow::getPlayerBar() const {
    return playerBar;
}

void GameWindow::setPlayerBar(PlayerBar *playerBar) {
    GameWindow::playerBar = playerBar;
}

void GameWindow::setScoreLabel(int score) {
    totalPoints = totalPoints + score;
    string text = to_string(totalPoints);
    const QString& qString= text.c_str();
    pointsLabel->setText("Points: " + qString);
    pointsLabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    pointsLabel->setGeometry(470, 400, 100, 100);
    pointsLabel->setVisible(true);

}

void GameWindow::setDepthLabel(int depthLevel) {
    string text = to_string(depthLevel);
    const QString& qString= text.c_str();
    depthLabel->setText("Depth Level: " + qString);
    depthLabel->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    depthLabel->setGeometry(470, 380, 100, 100);
    depthLabel->setVisible(true);

}
