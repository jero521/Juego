#ifndef ENEMY_RANGO_H
#define ENEMY_RANGO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy_rango: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:

int ganancia=10;
int velocidad=5;
int danio=100;
public:
Enemy_rango(QGraphicsItem * parent = 0);

int getGanancia() const;

int getVelocidad() const;
void setVelocidad(int newVelocidad);




public slots:
    void move();



};



#endif // ENEMY_RANGO_H
