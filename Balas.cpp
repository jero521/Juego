#include "Balas.h"
#include <QFont>



Balas::Balas(QGraphicsItem *parent)
{
    // inciar el puntaje
    balas = 50;

    // dibujar el texto

    setPlainText(QString("MUNICIONES: ")+QString::number(balas));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Balas::increase(int ganancia)
{
    balas+=ganancia;
    setPlainText(QString("MUNICIONES: ")+QString::number(balas));
}
void Balas::decrease()
{
    balas--;
    setPlainText(QString("MUMICIONES: ")+QString::number(balas)); // health
}

int Balas::getbalas()
{
    return balas;
}
