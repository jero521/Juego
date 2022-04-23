#include "bullet_parabolico.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QList>
#include <enemy.h>
#include <enemy_tanque.h>
#include <enemy_rango.h>
#include <game.h>
#include <player.h>

#define delta 0.03
#define g 15.8

extern Game *game; // llamar una variable externa para interactuar con ella

int Bullet_parabolico::getDano() const
{
    return Dano;
}



Bullet_parabolico::Bullet_parabolico()
{
    //dibujar la bala
    setPixmap(QPixmap(":/Imagenes/Cannon_Ball.png"));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(4);
    sounbomba = new QMediaPlayer();
    sounbomba->setMedia(QUrl("qrc:/Sonidos/bomba.mp3"));
}
void Bullet_parabolico::CalcularPosicion()
{
     posx+=velX*delta;
     posy+=vely*delta-0.5*g*delta*delta;
     qDebug()<<"posx: "<<posx<<" posy: "<<posy<<'\n';
     setPos(posx,-posy);
}

void Bullet_parabolico::CalcularVelocidad()
{
    velX=vel*cos(ang);
    vely=vel*sin(ang)-g*delta;
}

void Bullet_parabolico::ActualizarVelocidad()
{
    vel=sqrt(velX*velX+vely*vely);
    ang=atan2(vely,velX);
}


void Bullet_parabolico::move()
{

    QList <QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n=colliding_items.size();i<n;++i){

        if(typeid(*(colliding_items[i]))==typeid (Enemy) || typeid(*(colliding_items[i]))==typeid (Enemy_tanque) || typeid(*(colliding_items[i]))==typeid (Enemy_rango) || typeid ( *(colliding_items[i]))==typeid (Player)){


            if(typeid(*(colliding_items[i]))==typeid (Enemy)){
               game->score->increase(10);
               delete colliding_items[i];
               delete this;
               sounbomba->play();
               return;
        }

          else if(typeid(*(colliding_items[i]))==typeid (Enemy_tanque)){
              game->score->increase(20);
              delete colliding_items[i];
              delete this;
              sounbomba->play();
              return;
        }

            else if(typeid(*(colliding_items[i]))==typeid (Enemy_rango)){
                game->score->increase(50);
                delete colliding_items[i];
                delete this;
                sounbomba->play();
                return;
          }
            else if(typeid(*(colliding_items[i]))==typeid (Player)){
                game->health->decrease();
                delete this;
                sounbomba->play();
                if(game->health->getHealth()<0){
                    delete colliding_items[i];
                }

                return;
          }


        }

    }

    //mover bala
    CalcularVelocidad();
    CalcularPosicion();
    ActualizarVelocidad();

    if(pos().x()>1200 || pos().y()>600){

        scene()->removeItem(this);
        delete this;
        sounbomba->play();
        qDebug()<<"Borrado Ballet";

    }
}
