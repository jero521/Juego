#ifndef BOMBAS_H
#define BOMBAS_H

#include <QGraphicsTextItem>

class Bombas: public QGraphicsTextItem
{
public:
    Bombas(QGraphicsItem * parent = 0);
    void increase(int ganancia);
    void decrease();
    int getbombas();

    void setBombas(int newBombas);

private:
    int bombas;
};

#endif // BOMBAS_H
