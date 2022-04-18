#include "Bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QList>
#include <Enemy.h>
#include <Enemy_tanque.h>
#include <Enemy_rango.h>
#include <Game.h>

extern Game *game; // llamar una variable externa para interactuar con ella

int Bullet::getDano() const
{
    return Dano;
}

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

        if(typeid(*(colliding_items[i]))==typeid (Enemy) || typeid(*(colliding_items[i]))==typeid (Enemy_tanque  ) || typeid(*(colliding_items[i]))==typeid (Enemy_rango)){

               game->score->increase();
               delete colliding_items[i];
               delete this;
               if(game->score->getScore()>=5){
                   game->timer->start(1000);

               }
               return;
        }
    }

    //mover bala
    setPos(x()+10,y());

    if(pos().x()>800){

        scene()->removeItem(this);
        delete this;
    }
}

