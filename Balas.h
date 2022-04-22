#ifndef BALAS_H
#define BALAS_H
#include <QGraphicsTextItem>

class Balas: public QGraphicsTextItem{
public:
    Balas(QGraphicsItem * parent = 0);
    void increase(int ganancia);
    void decrease();
    int getbalas();

    void setBalas(int newBalas);

private:
    int balas;
};
#endif // BALAS_H
