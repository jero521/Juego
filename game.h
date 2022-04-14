#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
//#include "Score.h"
#include "vidas_salud.h"
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
    //Score * score;
    vidas_salud * health;
    MovimientoPrb * proyectil;
    QTimer * timer;



};


#endif // GAME_H
