#ifndef ENEMY_H
#define ENEMY_H

#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:

int ganancia=10;
int velocidad=5;
int danio=100;
public:
Enemy(QGraphicsItem * parent = 0);

int getGanancia() const;

int getVelocidad() const;
void setVelocidad(int newVelocidad);


public slots:
    void move();





};




#endif // ENEMY_H
