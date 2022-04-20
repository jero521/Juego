#include <health.h>
#include <QFont>

Health::Health(QGraphicsItem *parent)
{
    //health inicial
     health = 3;

    // dibujar el text

   setPlainText(QString("Health: ")+QString::number(health)); // health
   setDefaultTextColor(Qt::red);
   setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ")+QString::number(health)); // health
    hit = new QMediaPlayer;
    if(health==0){

    hit->setMedia(QUrl("qrc:/Sonidos/muerte.mp3"));
    }
    else{
        hit->setMedia(QUrl("qrc:/Sonidos/Golpeada.mp3"));
    }
    hit->play();

}

int Health::getHealth()
{
        return health;
}

