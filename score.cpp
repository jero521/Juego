#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
{
    // inciar el puntaje
    score = 0;
    muertos = 0;

    // dibujar el texto

    setPlainText(QString("CREDITOS: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(int ganancia)
{
    score+=ganancia;
    muertos++;
    setPlainText(QString("CREDITOS: ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}

int Score::getMuertos()
{
    return muertos;
}

void Score::setScore(int newScore)
{
    score = newScore;
    setPlainText(QString("CREDITOS: ")+QString::number(score));
}

void Score::setMuertos(int newMuertos)
{
    muertos = newMuertos;
}
void Score::decrease(int costo)
{
    score-=costo;
    setPlainText(QString("VIDAS: ")+QString::number(score)); // health
}
