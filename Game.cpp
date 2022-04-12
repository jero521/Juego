#include "Game.h"
#include "Enemy.h"
#include <QTimer>


void Game::Simular()
{
    double ang;
    ang=45;
    double rad=(ang*3.14159)/180;
    proyectil= new MovimientoPrb(80,500,30,rad);
    scene->addItem(proyectil);
    timer->start(5);
}

void Game::Actualizar()
{
    proyectil->CalcularVelocidad();
    proyectil->CalcularPosicion();
    proyectil->ActualizarVelocidad();

}

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

    show();


}
