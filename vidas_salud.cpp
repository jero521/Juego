#include "vidas_salud.h"
#include <QFont>


vidas_salud::vidas_salud(QGraphicsItem *parent)
{
    Vidas = 3;

   // dibujar el text

  setPlainText(QString("Health: ")+QString::number(Vidas)); // health
  setDefaultTextColor(Qt::red);
  setFont(QFont("times",16));
}

int vidas_salud::Getvida()
{    
return Vidas;
}

void vidas_salud::Decrease()
{


   Vidas--;
   setPlainText(QString("Vidas: ")+QString::number(Vidas)); // vidas

}

int vidas_salud::Getsalud()
{
    return Salud;
}

