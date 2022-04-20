#include "game.h"
#include "enemy.h"
#include "enemy_rango.h"
#include "enemy_tanque.h"
#include <QTimer>


Game::Game(QWidget *parent)
{
    // crear la scena

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/Ciclos/Amanecer.png")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width,height);


    // crear el jugador

    player = new Player();
    player->setPixmap(QPixmap(":/Imagenes/Enemigos/Pj.png"));
    player->setPos(400,430);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    // crear puntaje

    score = new Score();
    scene->addItem(score);
    // creamos la vida

    health =new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //mostrar enemigos
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QTimer *timer1 = new QTimer();
    QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn_tanque()));
    timer1->start(5000);

    QTimer *timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn_rango()));
    timer2->start(9000);

    //Musica de fondo

    M_Fondo = new QMediaPlayer();
    M_Fondo->setMedia(QUrl("qrc:/Sonidos/musica de fondo.mp3"));
    M_Fondo->play();



    show();


}
