#include <Health.h>
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
}

int Health::getHealth()
{
        return health;
}


