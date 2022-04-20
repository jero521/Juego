#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
{
    // inciar el puntaje
    score = 0;

    // dibujar el texto

    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}
