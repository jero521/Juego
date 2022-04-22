#include "enemy_pro.h"
#include "enemy_rango.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <player.h>
#include <QList>
#include <QtDebug>


extern Game * game;

int Enemy_pro::getGanancia() const
{
    return ganancia;
}

int Enemy_pro::getVelocidad() const
{
    return velocidad;
}

void Enemy_pro::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}



Enemy_pro::Enemy_pro(QGraphicsItem * parent )
{
    setPos(1200,470);
    // dibujamos el enemigo
    setPixmap(QPixmap(":/Imagenes/Bola de fuego.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);

}
void Enemy_pro::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n=colliding_items.size();i<n;++i){

        if(typeid(*(colliding_items[i]))==typeid (Player)){
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            if(game->health->getHealth()<=0){
                 delete colliding_items[i];
         }
        }

    }


    setPos(x()-getVelocidad(),y());

   if(pos().x()+pixmap().width()<0 ){
      scene()->removeItem(this);
      delete this;
      }
}
