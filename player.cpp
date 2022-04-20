#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "bullet_parabolico.h"
#include "enemy.h"
#include <QTimer>
#include <enemy_tanque.h>
#include <enemy_rango.h>



void Player::setDinero(int newDinero)
{
    Dinero = newDinero;
}

int Player::getVel() const
{
    return Vel;
}

void Player::setVel(int newVel)
{
    Vel = newVel;
}

int Player::getDinero() const
{
    return Dinero;
}

int Player::getMuniciones() const
{
    return Municiones;
}



void Player::setMuniciones(int newMuniciones)
{
    Municiones = newMuniciones;
}

Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    QTimer *timer = new QTimer(this);


    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //mover al jugador


    if((event->key() == Qt::Key_Left) || (event->key() == Qt::Key_A)){


        if(pos().x()>0)
        setPos(x()-getVel(),y());
    }
    else if ((event->key() == Qt::Key_Right) || (event->key() == Qt::Key_D)){


        if (pos().x() + pixmap().width() < scene()->width())
        setPos(x()+getVel(),y());
    }
    else if(event->key()==Qt::Key_Space){

        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

    }
    else if(event->key()==Qt::Key_X){

        Bullet_parabolico * bullet_parabolico = new Bullet_parabolico();
        bullet_parabolico->setPos(x(),y());
        scene()->addItem(bullet_parabolico);

    }
    else if((event->key() == Qt::Key_Up) || (event->key() == Qt::Key_W)){
       for(int i=0; i<20; i++){

            setPos(x(),y()-getVel());

       }
       for(int j=20; j>0; j--)

            setPos(x(),y()+getVel());

    }
}



void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spawn_tanque()
{
    Enemy_tanque * enemy_tanque = new Enemy_tanque();
    scene()->addItem(enemy_tanque);
}
void Player::spawn_rango()
{
    Enemy_rango * enemy_rango = new Enemy_rango();
    scene()->addItem(enemy_rango);
}
