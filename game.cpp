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
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);

    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // crear boton play

    Button * playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 -playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // crear boton salir

    Button * quitButton = new Button(QString("Exit"));
    int qxPos = this->width()/2 -quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::enteroACad(int n, char cadena[])
{
    int cont = 0;
    int aux = n;
    while (aux>0)
    {
        aux = aux/10;
        cont ++;
    }
    cadena[cont] = '\0';
    aux = n;
    int pos = cont - 1, digito;
    while (pos>=0 )
    {
     digito = aux%10;
     aux = aux/10;
     cadena[pos]=digito + '0';
     pos --;

    }

}
void Game::guardar()
{
    char datosvida[10],datoscreditos[10],datosmuertos[10],datosbalas[10],datosbombas[10];
    enteroACad(health->getHealth(),datosvida);
    enteroACad(score->getScore(),datoscreditos);
    enteroACad(score->getMuertos(),datosmuertos);
    enteroACad(balas->getbalas(),datosbalas);
    enteroACad(bombas->getbombas(),datosbombas);
    QByteArray Datov = (datosvida),Datosc = (datoscreditos), Datosm = (datosmuertos),
            Datosb = (datosbalas), Datosbo = (datosbombas);
    QFile vida;
    vida.setFileName("vidas");
    vida.write("hola");
    vida.close();


}
void Game::start()
{
scene->clear();
setBackgroundBrush(QBrush(QImage(":/Imagenes/Amanecer.png")));
// crear el jugador

Button * quitButton = new Button(QString("Guardar"));
int qxPos = 1100;
int qyPos = 0;
quitButton->setPos(qxPos,qyPos);
connect(quitButton,SIGNAL(clicked()),this,SLOT(guardar()));
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
timer6->start(100000);

QTimer *timer7 = new QTimer();
QObject::connect(timer7,SIGNAL(timeout()),player,SLOT(spawn_pro()));
timer7->start(9000);
}
