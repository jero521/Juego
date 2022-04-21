#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent = 0);
    void increase(int ganancia);
    int getScore();
    void decrease(int costo);
    int getMuertos();

private:
    int score;
    int muertos;
};
#endif // SCORE_H
