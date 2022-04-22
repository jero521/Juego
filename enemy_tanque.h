#ifndef ENEMY_TANQUE_H
#define ENEMY_TANQUE_H

#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>
class Enemy_tanque: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:

int ganancia=30;
int velocidad=5;
int danio=100;
public:
Enemy_tanque(QGraphicsItem * parent = 0);

int getGanancia() const;

int getVelocidad() const;
void setVelocidad(int newVelocidad);


public slots:
    void move();



};



#endif // ENEMY_TANQUE_H
