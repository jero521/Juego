#include <health.h>
#include <QFont>

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
        soungolpe->setMedia(QUrl("qrc:/Sonidos/muerte.mp3"));
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
}
void Health::increase()
{
    health++;
    setPlainText(QString("VIDAS: ")+QString::number(health));
}
