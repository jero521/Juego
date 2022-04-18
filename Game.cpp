#include "Game.h"
#include "Enemy.h"
#include "Enemy_rango.h"
#include "enemy_tanque.h"
#include <QTimer>


Game::Game(QWidget *parent)
{
    // crear la scena

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    // crear el jugador

    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(400,500);
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

    show();


}
