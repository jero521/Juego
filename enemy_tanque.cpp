#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include <enemy_tanque.h>
#include "game.h"
#include <player.h>
#include <QList>
#include <QtDebug>


extern Game * game;




int Enemy_tanque::getGanancia() const
{
    return ganancia;
}

int Enemy_tanque::getVelocidad() const
{
    return velocidad;
}

void Enemy_tanque::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}


Enemy_tanque::Enemy_tanque(QGraphicsItem *parent)
{

    setPos(1200,370);
    // dibujamos el enemigo
    setPixmap(QPixmap(":/Imagenes/E_pesado.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);


}

void Enemy_tanque::move()
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
