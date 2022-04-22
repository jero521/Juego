#ifndef GAME_H
#define GAME_H

#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"
#include "Balas.h"
#include "bombas.h"
#include <QTimer>
#include <QMediaPlayer>


class Game: public QGraphicsView{
     Q_OBJECT

public:
    Game(QWidget * parent = 0);

    void menu();


    QGraphicsScene *scene;
    Player * player;
    Score * score;
    Health * health;
    Balas * balas;
    Bombas * bombas;
    QTimer * timer;
    QMediaPlayer * M_Fondo;


public slots:
    void start();
    void retry();



};


#endif // GAME_H
