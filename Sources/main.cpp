
#include <map>
#include "../Headers/GameWindow.h"
#include <QApplication>

GameWindow * gameWindow;

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    gameWindow = new GameWindow();
    gameWindow->show();
    gameWindow->start();

    return app.exec();
}
