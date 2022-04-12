#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "movimientoprb.h"
#include <QTimer>


class Game: public QGraphicsView{

private slots:
    void Simular();
    void Actualizar();

public:
    Game(QWidget * parent = 0);

    QGraphicsScene *scene;
    Player * player;
    Score * score;
    Health * health;
    MovimientoPrb * proyectil;
    QTimer * timer;



};


#endif // GAME_H
