#include "regalo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <player.h>
#include <QList>
#include <QtDebug>
#include <QtMath>
extern Game * game;


int Regalo::getVelocidad() const
{
    return velocidad;
}

void Regalo::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}



Regalo::Regalo(QGraphicsItem *parent)
{
    int x = rand() %1100;
    setPos(x,0);
    // dibujamos el enemigo
    setPixmap(QPixmap(":/Imagenes/Regalo.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}
void Regalo::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();

        for(int i = 0, n=colliding_items.size();i<n;++i){

            if(typeid(*(colliding_items[i]))==typeid (Player)){
                game->health->increase();
                scene()->removeItem(this);
                delete this;

            }
        }
        setPos(x(),y()+getVelocidad());
       if(pos().y()+pixmap().width()>600 ){
          scene()->removeItem(this);
          delete this;
          }



}

