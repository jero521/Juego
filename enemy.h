#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "vidas_salud.h"

class Enemy: public QObject,public QGraphicsRectItem{
    Q_OBJECT

int salud=400;
int ganancia=10;


public:
    Enemy(QGraphicsItem * parent = 0);
    int getSalud() const;
    void setSalud(int newSalud);
    int getGanancia() const;
    vidas_salud * healt;


public slots:
    void move();

};




#endif // ENEMY_H
