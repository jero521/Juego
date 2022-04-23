#include <health.h>
#include <QFont>
#include <game.h>
#include <button.h>
#include <QTextStream>
#include <QGraphicsTextItem>
extern Game * game;

Health::Health(QGraphicsItem *parent)
{
    //health inicial
     health = 3;

    // dibujar el text

   setPlainText(QString("VIDAS: ")+QString::number(health)); // health
   setDefaultTextColor(Qt::red);
   setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    soungolpe = new QMediaPlayer();
    if(health==0){
        game->M_Fondo->setMedia(QUrl("qrc:/Sonidos/game over.mp3"));
        game->M_Fondo->play();
        QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("GAME OVER"));
        QFont titleFont("comic sans",100);
        titleText->setFont(titleFont);
        int txPos = 230;
        int tyPos = 200;
        titleText->setPos(txPos,tyPos);
        game->scene->addItem(titleText);
    }
    else {
        soungolpe->setMedia(QUrl("qrc:/Sonidos/Golpeada.mp3"));
    }
    soungolpe->play();
    setPlainText(QString("VIDAS: ")+QString::number(health)); // health
}

int Health::getHealth()
{
    return health;
}

void Health::setHealth(int newHealth)
{
    health = newHealth;
    setPlainText(QString("VIDAS: ")+QString::number(health)); // health
}
void Health::increase()
{
    health++;
    setPlainText(QString("VIDAS: ")+QString::number(health));
}
