#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QList>
#include <enemy.h>
#include <game.h>

extern Game *game; // llamar una variable externa para interactuar con ella

Bullet::Bullet()
{
    //dibujar la bala
    setRect(100,50,50,10);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{

    QList <QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n=colliding_items.size();i<n;++i){

        if(typeid(*(colliding_items[i]))==typeid (Enemy)){

            //aumentar puntaje
            //game->score->increase();


            // quitar de la scena
            //scene()->removeItem(colliding_items[i]);  // crashed
            //scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;


        }
    }

    //mover bala
    setPos(x()+10,y());

    if(pos().y() +rect().height()<0){

        scene()->removeItem(this);
        delete this;

    }
}
