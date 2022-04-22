#include "game.h"
#include "enemy.h"
#include "enemy_rango.h"
#include "enemy_tanque.h"
#include <QTimer>
#include "button.h"
#include <QBrush>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <regalo.h>
#include <string>

Game::Game(QWidget *parent)
{
    // crear la scena

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);

}

void Game::menu()
{
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/Imagenes/Anochecer.png")));
    M_Fondo = new QMediaPlayer();
    M_Fondo->setMedia(QUrl("qrc:/Sonidos/musica de fondo.mp3"));
    M_Fondo->play();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Survive 24 hours"));
    QFont titleFont("comic sans",80);
    titleText->setFont(titleFont);

    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // crear boton play

    Button * playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 -playButton->boundingRect().width()/2;
    int byPos = 300;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // crear boton salir

    Button * quitButton = new Button(QString("Exit"));
    int qxPos = this->width()/2 -quitButton->boundingRect().width()/2;
    int qyPos = 375;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    Button * RetryButton = new Button(QString("Retry"));
    int rxPos = this->width()/2 -RetryButton->boundingRect().width()/2;
    int ryPos = 450;
    RetryButton->setPos(rxPos,ryPos);
    connect(RetryButton,SIGNAL(clicked()),this,SLOT(retry()));
    scene->addItem(RetryButton);
}

void Game::retry()
{

    QFile file("C:/Users/camilo/Desktop/Juego/guardado.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    int datos[5];
    qint32 datico,datico1,datico2,datico3,datico4;
    in>>datico;
    in>>datico1;
    in>>datico2;
    in>>datico3;
    in>>datico4;
    file.close();
    qDebug()<<datico<<" "<<datico1<<" "<<datico2<<" "<<datico3<<" "<<datico4;

    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/Imagenes/Amanecer.png")));
    // crear el jugador

    Button * quitButton = new Button(QString("Exit"));
    int qxPos = 1100;
    int qyPos = 0;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    player = new Player();
    player->setPixmap(QPixmap(":/Imagenes/Pj.png"));
    player->setPos(400,430);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    // crear puntaje

    score = new Score();
    score->setScore(datico1);
    score->setMuertos(datico2);
    scene->addItem(score);
    // creamos la vida

    health =new Health();
    health->setHealth(datico);
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    balas =new Balas();
    balas->setBalas(datico3);
    balas->setPos(balas->x(),balas->y()+50);
    scene->addItem(balas);

    bombas =new Bombas();
    bombas->setBombas(datico4);
    bombas->setPos(bombas->x(),bombas->y()+75);
    scene->addItem(bombas);


    //mostrar enemigos


    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(3000);

    QTimer *timer1 = new QTimer();
    QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn_tanque()));
    timer1->start(4000);

    QTimer *timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn_rango()));
    timer2->start(5000);

    QTimer *timer3 = new QTimer();
    QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(spawn1()));
    timer3->start(1500);

    QTimer *timer4 = new QTimer();
    QObject::connect(timer4,SIGNAL(timeout()),player,SLOT(spawn1_tanque()));
    timer4->start(2000);

    QTimer *timer5 = new QTimer();
    QObject::connect(timer5,SIGNAL(timeout()),player,SLOT(spawn1_rango()));
    timer5->start(5000);

    QTimer *timer6 = new QTimer();
    QObject::connect(timer6,SIGNAL(timeout()),player,SLOT(spawn_regalo()));
    timer6->start(60000);

    QTimer *timer7 = new QTimer();
    QObject::connect(timer7,SIGNAL(timeout()),player,SLOT(spawn_pro()));
    timer7->start(9000);
}


void Game::start()
{
scene->clear();
setBackgroundBrush(QBrush(QImage(":/Imagenes/Amanecer.png")));
// crear el jugador

Button * quitButton = new Button(QString("Exit"));
int qxPos = 1100;
int qyPos = 0;
quitButton->setPos(qxPos,qyPos);
connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
scene->addItem(quitButton);

player = new Player();
player->setPixmap(QPixmap(":/Imagenes/Pj.png"));
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

balas =new Balas();
balas->setPos(balas->x(),balas->y()+50);
scene->addItem(balas);

bombas =new Bombas();
bombas->setPos(bombas->x(),bombas->y()+75);
scene->addItem(bombas);


//mostrar enemigos


QTimer *timer = new QTimer();
QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
timer->start(3000);

QTimer *timer1 = new QTimer();
QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn_tanque()));
timer1->start(4000);

QTimer *timer2 = new QTimer();
QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawn_rango()));
timer2->start(5000);

QTimer *timer3 = new QTimer();
QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(spawn1()));
timer3->start(1500);

QTimer *timer4 = new QTimer();
QObject::connect(timer4,SIGNAL(timeout()),player,SLOT(spawn1_tanque()));
timer4->start(2000);

QTimer *timer5 = new QTimer();
QObject::connect(timer5,SIGNAL(timeout()),player,SLOT(spawn1_rango()));
timer5->start(5000);

QTimer *timer6 = new QTimer();
QObject::connect(timer6,SIGNAL(timeout()),player,SLOT(spawn_regalo()));
timer6->start(60000);

QTimer *timer7 = new QTimer();
QObject::connect(timer7,SIGNAL(timeout()),player,SLOT(spawn_pro()));
timer7->start(9000);
}
