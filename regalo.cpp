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

    setPos(800,500);
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
if(y()>300 && y()<600){
    setPos(x(),y()-getVelocidad());
}
if(y()>300 && y()<600){
    setPos(x(),y()+getVelocidad());
}



}
/*
  setPos(x()-getVelocidad(),y());
static float cont =0;
float posX = 100*100*qCos(qDegreesToRadians(cont));
cont += 5.0f;

float posY = 100*100*qSin(qDegreesToRadians(cont));
cont += 5.0f;
 qDebug()<<"posx: "<<posX<<" posy: "<<posY<<'\n';
setPos(x()+posX,y()+posY);
*/
