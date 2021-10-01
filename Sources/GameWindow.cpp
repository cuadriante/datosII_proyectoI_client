//
// Created by cuadriante on 6/9/21.
//
/**
 *
 */


#include "../Headers/GameWindow.h"


GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    //initialization
    scene = new QGraphicsScene(0,0,600,600);
    setScene(scene);
    this->setWindowTitle("Crazy Breakout");
    this->setStyleSheet("background-color:rgb(225, 170, 199);");


}

void GameWindow::start() {
    // create text line edit for name input
//    QDialog * nameDialog = new QDialog(this);
//    nameDialog->setVisible(true);
//    nameDialog->setModal(true);

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

    createLabels();


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

void GameWindow::askForPlayerName() {
    titleLabel = new QLabel(this);
    titleLabel->setText("Crazy Breakout \n ver 0.1");
    QFont font = titleLabel->font();
    font.setPointSize(30);
    font.setBold(true);
    titleLabel->setFont(font);
    titleLabel->setStyleSheet("QLabel { color : rgb(100, 0, 58); }");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setGeometry(132, 100, 350, 100);
    titleLabel->setVisible(true);

    nameTextInput = new QLineEdit(this);
    nameTextInput->setAlignment(Qt::AlignCenter);
    nameTextInput->setPlaceholderText("Player name");
    nameTextInput->setStyleSheet("color : white;");
    nameTextInput->setMaxLength(20);
    nameTextInput->setGeometry(240, 250, 120, 25);
    nameTextInput->setVisible(true);

    nameInputButton = new QPushButton(this);
    nameInputButton->setGeometry(266, 290, 70, 25);
    nameInputButton->setText("PLAY");
    nameInputButton->setVisible(true);
    nameInputButton->setStyleSheet("color: white;");
    connect(nameInputButton, SIGNAL(clicked()), this, SLOT(clickedSlot()));
}

void GameWindow::createLabels() {// create points pointsLabel



    // create player name label
    playerLabel = new QLabel(this);
    playerLabel->setText("Player: " + playerName);
    playerLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    playerLabel->setStyleSheet("color: white;");
    playerLabel->setGeometry(470, 420, 100, 100);
    playerLabel->setVisible(true);

    pointsLabel = new QLabel(this);
    pointsLabel->setStyleSheet("color: white;");
    pointsLabel->setText("Score: 0");
    pointsLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    pointsLabel->setGeometry(470, 400, 100, 100);
    pointsLabel->setVisible(true);

    // create player name label
    // create depth level label
    depthLabel = new QLabel(this);
    depthLabel->setStyleSheet("color: white;");
    depthLabel->setText("Depth Level: 0");
    depthLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    depthLabel->setGeometry(470, 380, 110, 100);
    depthLabel->setVisible(true);

    // create surprise label
    surpriseLabel = new QLabel(this);
    surpriseLabel->setText("Surprise !!");
    surpriseLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    surpriseLabel->setStyleSheet("color: white;");
    surpriseLabel->setGeometry(470, 360, 100, 100);


}

void GameWindow::addBlock(int id, int x, int y, int type, int hitsToBreak) {
    Block * block = new Block();
    block->setId(id);
    block->setType(type);
    block->setPos(x,y);
    blocklist.push_back(block);
    scene->addItem(block);
    if (hitsToBreak <= 0){
        block->setVisible(false);
    }
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
    pointsLabel->setText("Score: " + qString);
    //pointsLabel->setStyleSheet("color: RGB 255, 255, 255;");
    pointsLabel->setVisible(true);
}

void GameWindow::setDepthLabel(int depthLevel) {
    string text = to_string(depthLevel);
    const QString& qString= text.c_str();
    //depthLabel->setStyleSheet("color: white;");
    depthLabel->setText("Depth Level: " + qString);
    depthLabel->setVisible(true);
}

void GameWindow::setSurpriseLabel(){
    //surpriseLabel->setStyleSheet("color: white;");
    surpriseLabel->setVisible(true);
}

QLabel *GameWindow::getSurpriseLabel() const {
    return surpriseLabel;
}

vector<Block *> &GameWindow::getOtherPlayers() {
    return otherPlayers;
}

void GameWindow::clickedSlot() {
    playerName  = nameTextInput->text();
    qDebug() << "Button pressed";
    qDebug() << playerName;

    titleLabel->setVisible(false);
    nameInputButton->setVisible(false);
    nameTextInput->setVisible(false);

    start();


}

void GameWindow::endGame() {
    for(Block * otherPlayer: otherPlayers){
        otherPlayer->setVisible(false);
    }
    for(Block * block: blocklist){
        block->setVisible(false);
    }
    playerBar->setVisible(false);
    depthLabel->setVisible(false);
    pointsLabel->setVisible(false);
    surpriseLabel->setVisible(false);
    playerLabel->setVisible(false);

    if (!won) {
        titleLabel->setText("You lost :(. \n Try again?");
        titleLabel->setVisible(true);
    } else {

        string text = to_string(totalPoints);
        const QString& qString= text.c_str();
        titleLabel->setText("You won! \n  Your score: " + qString);
        titleLabel->setVisible(true);
    }


}

bool GameWindow::isWon() const {
    return won;
}

void GameWindow::setWon(bool won) {
    GameWindow::won = won;
}

