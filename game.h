#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"
#include <QMediaPlayer>
#include <QTimer>


class Game: public QGraphicsView{



public:


    Game(QWidget * parent = 0);

    QGraphicsScene *scene;
    Player * player;
    Score * score;
    Health * health;
    QTimer * timer;
    QMediaPlayer * M_Fondo;


    const int width = 1200;
    const int height = 600;



};


#endif // GAME_H
