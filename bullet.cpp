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
#include <player.h>

extern Game *game; // llamar una variable externa para interactuar con ella

int Bullet::getDano() const
{
    return Dano;
}

Bullet::Bullet()
{
    //dibujar la bala
    //setRect(100,50,50,10);
    //setPos(700,430);
    setPixmap(QPixmap(":/Imagenes/Otros/bullet.png"));


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

               return;
        }
    }

    //mover bala
    setPos(x()+10,y());

     if(pos().x()>1200){

        scene()->removeItem(this);
        delete this;
    }

}
