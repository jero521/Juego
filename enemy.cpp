#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include <enemy.h>
#include "game.h"
#include <QList>
#include <player.h>
#include <QtDebug>

extern Game * game;


int Enemy::getGanancia() const
{
    return ganancia;
}

int Enemy::getVelocidad() const
{
    return velocidad;
}

void Enemy::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}


Enemy::Enemy(QGraphicsItem *parent)
{

    setPos(1200,430);
    // dibujamos el enemigo
    setPixmap(QPixmap(":/Imagenes/E_normal.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);


}

void Enemy::move()
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
