#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "bullet_parabolico.h"
#include "enemy.h"
#include <QTimer>
#include <enemy_tanque.h>
#include <enemy_rango.h>
#include <enemy_pro.h>
#include <game.h>
#include <regalo.h>

extern Game *game;

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
    timer->start(80);
    QTimer *timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(100);
    sounball = new QMediaPlayer();
    sounball->setMedia(QUrl("qrc:/Sonidos/Sonido disparo.mp3"));
    sounfeo = new QMediaPlayer();
    sounfeo->setMedia(QUrl("qrc:/Sonidos/feo.mp3"));

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
        if(game->balas->getbalas()>0){
        Bullet * bullet = new Bullet();
        sounball->play();
        bullet->setPos(x()+155,y()+67);
        scene()->addItem(bullet);
        game->balas->decrease();
        }
    }
    else if(event->key()==Qt::Key_X){
      if(game->bombas->getbombas()>0){
        Bullet_parabolico * bullet_parabolico = new Bullet_parabolico();
        bullet_parabolico->setPos(x(),y());
        scene()->addItem(bullet_parabolico);
        game->bombas->decrease();
      }

    }
    else if(event->key()==Qt::Key_V){
        if(game->score->getScore()>=100){
        game->health->increase();
        game->score->decrease(100);
        }

    }
    else if(event->key()==Qt::Key_B){
        if(game->score->getScore()>=50){
        game->balas->increase(15);
        game->score->decrease(50);
        }

    }
    else if(event->key()==Qt::Key_N){
        if(game->score->getScore()>=50){
        game->bombas->increase(10);
        game->score->decrease(50);
        }

    }
    else if((event->key() == Qt::Key_Up) || (event->key() == Qt::Key_W)){

          for(int i=0; i<20; i++){
               setPos(x()+5,y()-20);

          }
          for(int j=0; j<20; j++){
               setPos(x()+10,y()+20);

          }


    }
    else if((event->key() == Qt::Key_Down) || (event->key() == Qt::Key_S)){

          for(int i=0; i<20; i++){
               setPos(x()-5,y()-20);

          }
          for(int j=0; j<20; j++){
               setPos(x()-10,y()+20);

          }

    }
}


void Player::spawn()
{

    if(game->score->getMuertos()>=0 && game->score->getMuertos()<50 ){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    QFile file("C:/Users/camilo/Desktop/Juego/guardado.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<(qint32)game->health->getHealth()<<endl;
    out<<(qint32)game->score->getScore()<<endl;
    out<<(qint32)game->score->getMuertos()<<endl;
    out<<(qint32)game->balas->getbalas()<<endl;
    out<<(qint32)game->bombas->getbombas()<<endl;
    file.close();
    }
    else if(game->score->getMuertos()>=50 && game->score->getMuertos()<200){
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
        Enemy * enemy1 = new Enemy();
        scene()->addItem(enemy1);
        QFile file("C:/Users/camilo/Desktop/Juego/guardado.txt");
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out<<(qint32)game->health->getHealth()<<endl;
        out<<(qint32)game->score->getScore()<<endl;
        out<<(qint32)game->score->getMuertos()<<endl;
        out<<(qint32)game->balas->getbalas()<<endl;
        out<<(qint32)game->bombas->getbombas()<<endl;
        file.close();
    }
}

void Player::spawn_tanque()
{
    if(game->score->getMuertos()>=10 && game->score->getMuertos()<80){
    Enemy_tanque * enemy_tanque = new Enemy_tanque();
    scene()->addItem(enemy_tanque);
    Enemy_tanque * enemy_tanque1 = new Enemy_tanque();
    scene()->addItem(enemy_tanque1);
    }
    else if(game->score->getMuertos()>=80 && game->score->getMuertos()<200){
        Enemy_tanque * enemy_tanque = new Enemy_tanque();
        scene()->addItem(enemy_tanque);
        Enemy_tanque * enemy_tanque1 = new Enemy_tanque();
        scene()->addItem(enemy_tanque1);
        Enemy_tanque * enemy_tanque2 = new Enemy_tanque();
        scene()->addItem(enemy_tanque2);
    }
}
void Player::spawn_rango()
{
    if(game->score->getMuertos()>=40 && game->score->getMuertos()<120){
    game->setBackgroundBrush(QBrush(QImage(":/Imagenes/Anochecer.png")));
    Enemy_rango * enemy_rango = new Enemy_rango();
    scene()->addItem(enemy_rango);
    Enemy_rango * enemy_rango1 = new Enemy_rango();
    scene()->addItem(enemy_rango1);
    Enemy_rango * enemy_rango2 = new Enemy_rango();
    scene()->addItem(enemy_rango2);
    }
    else if(game->score->getMuertos()>=120 && game->score->getMuertos()<200){
        Enemy_rango * enemy_rango = new Enemy_rango();
        scene()->addItem(enemy_rango);
        Enemy_rango * enemy_rango1 = new Enemy_rango();
        scene()->addItem(enemy_rango1);
        Enemy_rango * enemy_rango2 = new Enemy_rango();
        scene()->addItem(enemy_rango2);
        Enemy_rango * enemy_rango3 = new Enemy_rango();
        scene()->addItem(enemy_rango3);
    }
}

void Player::spawn1()
{

     if (game->score->getMuertos()>=200 && game->score->getMuertos()<210){
         sounfeo->play();
     }

     if(game->score->getMuertos()>=200 && game->score->getMuertos()<400){
        game->setBackgroundBrush(QBrush(QImage(":/Imagenes/Noche.png")));
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
        Enemy * enemy1 = new Enemy();
        scene()->addItem(enemy1);
        QFile file("C:/Users/camilo/Desktop/Juego/guardado.txt");
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out<<(qint32)game->health->getHealth()<<endl;
        out<<(qint32)game->score->getScore()<<endl;
        out<<(qint32)game->score->getMuertos()<<endl;
        out<<(qint32)game->balas->getbalas()<<endl;
        out<<(qint32)game->bombas->getbombas()<<endl;
        file.close();
    }
}

void Player::spawn1_tanque()
{

    if(game->score->getMuertos()>=200 && game->score->getMuertos()<400){
        Enemy_tanque * enemy_tanque = new Enemy_tanque();
        scene()->addItem(enemy_tanque);
        Enemy_tanque * enemy_tanque1 = new Enemy_tanque();
        scene()->addItem(enemy_tanque1);
        Enemy_tanque * enemy_tanque2 = new Enemy_tanque();
        scene()->addItem(enemy_tanque2);
    }
}
void Player::spawn1_rango()
{

     if(game->score->getMuertos()>=250 && game->score->getMuertos()<400){
        game->M_Fondo->play();
        Enemy_rango * enemy_rango = new Enemy_rango();
        scene()->addItem(enemy_rango);
        Enemy_rango * enemy_rango1 = new Enemy_rango();
        scene()->addItem(enemy_rango1);
        Enemy_rango * enemy_rango2 = new Enemy_rango();
        scene()->addItem(enemy_rango2);
        Enemy_rango * enemy_rango3 = new Enemy_rango();
        scene()->addItem(enemy_rango3);
    }
}

void Player::spawn_regalo()
{
    if(game->score->getMuertos()>=0 && game->score->getMuertos()<400){
    Regalo * regalo = new Regalo();
    scene()->addItem(regalo);
    }
}

void Player::spawn_pro()
{
    if(game->score->getMuertos()>=0 && game->score->getMuertos()<400){
    Enemy_pro * enemy_pro = new Enemy_pro();
    scene()->addItem(enemy_pro);
    }
    if(game->score->getMuertos()>=400){
        game->setBackgroundBrush(QBrush(QImage(":/Imagenes/Amanecer.png")));
        game->M_Fondo->setMedia(QUrl("qrc:/Sonidos/final.mp3"));
        game->M_Fondo->play();
    }
}

