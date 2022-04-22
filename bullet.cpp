#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QList>
#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QList>
#include <enemy.h>
#include <enemy_tanque.h>
#include <enemy_rango.h>
#include <game.h>


extern Game *game; // llamar una variable externa para interactuar con ella

int Bullet::getDano() const
{
    return Dano;
}

Bullet::Bullet()
{
    //dibujar la bala
    setPixmap(QPixmap(":/Imagenes/bullet.png"));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{

    QList <QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n=colliding_items.size();i<n;++i){

        if(typeid(*(colliding_items[i]))==typeid (Enemy) || typeid(*(colliding_items[i]))==typeid (Enemy_tanque  ) || typeid(*(colliding_items[i]))==typeid (Enemy_rango)){

            if(typeid(*(colliding_items[i]))==typeid (Enemy)){

               game->score->increase(3);
               delete colliding_items[i];
               delete this;           
               return;
        }

          else if(typeid(*(colliding_items[i]))==typeid (Enemy_tanque)){
              game->score->increase(6);
              delete colliding_items[i];
              delete this;
              return;
        }

            else if(typeid(*(colliding_items[i]))==typeid (Enemy_rango)){
                game->score->increase(10);
                delete colliding_items[i];
                delete this;
                return;
          }
        }
    }

    //mover bala
    setPos(x()+30,y());

    if(pos().x()>1200){


        scene()->removeItem(this);
        delete this;
    }
}
