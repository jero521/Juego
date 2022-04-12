#include "proyectilprb.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QList>
#include <Enemy.h>
#include <Game.h>

extern Game *game;

double Proyectilprb::getPosx() const
{
    return posx;
}

double Proyectilprb::getPosy() const
{
    return posy;
}

Proyectilprb::Proyectilprb()
{

    this->vel=2;
    this->ang=20;
    this->r=15;

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

QRectF Proyectilprb::boundingRect() const
{
    return QRectF(0,0,2*r,2*r);
}

void Proyectilprb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setBrush(Qt::red);
  painter->drawEllipse(boundingRect());
}

void Proyectilprb::CalcularPosicion()
{
     posx+=velX*0.001;
     posy+=vely*0.001-0.5*9.8*0.001*0.001;
     qDebug()<<"posx: "<<posx<<" posy: "<<posy<<'\n';
     setPos(posx,-posy);
}

void Proyectilprb::CalcularVelocidad()
{
    velX=vel*cos(ang);
    vely=vel*sin(ang)-9.8*0.001;
}

void Proyectilprb::ActualizarVelocidad()
{
    vel=sqrt(velX*velX+vely*vely);
    ang=atan2(vely,velX);
}
void Proyectilprb::move()
{

    QList <QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n=colliding_items.size();i<n;++i){

        if(typeid(*(colliding_items[i]))==typeid (Enemy)){

            //aumentar puntaje
            game->score->increase();


            // quitar de la scena
            //scene()->removeItem(colliding_items[i]);  // crashed
            //scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;


        }
    }

    //mover bala
    //setPos(x()+10,y());

    //if(pos().y() +rect().height()<0){

      //  scene()->removeItem(this);
       // delete this;

    //}
    CalcularVelocidad();
    CalcularPosicion();
    ActualizarVelocidad();

}
