#include "game.h"
#include <QFile>
#include <QDebug>

#include <QApplication>

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->menu();

    return a.exec();
}

