#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <enemy.h>
#include "game.h"
#include <QList>


extern Game * game;

int Enemy::getSalud() const
{
    return salud;
}

void Enemy::setSalud(int newSalud)
{
    salud = newSalud;
}

int Enemy::getGanancia() const
{
    return ganancia;
}

Enemy::Enemy(QGraphicsItem *parent)
{
    // aparecer random

    //int random_numer = rand() %700;
    setPos(700,500);

    // dibujamos el enemigo
    setRect(0,0,100,100);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);


}


void Enemy::move()
{
    setPos(x()-5,y());

   if(pos().x()<0){
      game->health->Decrease();
      scene()->removeItem(this);
      delete this;
      }

}

