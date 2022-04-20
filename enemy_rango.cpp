#include "enemy_rango.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <player.h>
#include <QList>
#include <QtDebug>

extern Game * game;




int Enemy_rango::getGanancia() const
{
    return ganancia;
}

int Enemy_rango::getVelocidad() const
{
    return velocidad;
}

void Enemy_rango::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}


Enemy_rango::Enemy_rango(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPos(700,520);
    // dibujamos el enemigo
   // setRect(0,0,80,80);
    setPixmap(QPixmap(":/Imagenes/Enemigos/E_rango.png"));
    setPos(400,430);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);


}

void Enemy_rango::move()
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

   if(pos().x()<0 && game->health->getHealth()>0){
      game->health->decrease();
      scene()->removeItem(this);
      delete this;
      }
   else if(pos().x()+pixmap().width()<0){
       scene()->removeItem(this);
       delete this;
       qDebug()<<"Borrado";
   }


}
