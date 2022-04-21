#include "bombas.h"
#include <QFont>

Bombas::Bombas(QGraphicsItem *parent)
{
    // inciar el puntaje
    bombas = 30;

    // dibujar el texto

    setPlainText(QString("BOMBAS: ")+QString::number(bombas));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Bombas::increase(int ganancia)
{
    bombas+=ganancia;
    setPlainText(QString("BOMBAS: ")+QString::number(bombas));
}
void Bombas::decrease()
{
    bombas--;
    setPlainText(QString("BOMBAS: ")+QString::number(bombas)); // health
}

int Bombas::getbombas()
{
    return bombas;
}
