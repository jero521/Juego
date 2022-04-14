#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"




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

Player::Player(QGraphicsItem *parent)
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    //mover al jugador

    if(event->key()== Qt::Key_Left || Qt::Key_A){
        if(pos().x()>0)
        setPos(x()-getVel(),y());
    }
    else if (event->key() == Qt::Key_Right || Qt::Key_D){
        if (pos().x() + rect().width() < scene()->width())
        setPos(x()+getVel(),y());
    }
    else if(event->key()==Qt::Key_Space){

        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

    }

}


