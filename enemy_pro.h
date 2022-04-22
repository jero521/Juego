#ifndef ENEMY_PRO_H
#define ENEMY_PRO_H
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>

class Enemy_pro: public QObject,public QGraphicsPixmapItem{
         Q_OBJECT
public:
    int ganancia=50;
    int velocidad=20;
public:
    Enemy_pro(QGraphicsItem * parent = 0);

    int getGanancia() const;

    int getVelocidad() const;
    void setVelocidad(int newVelocidad);

public slots:
    void move();
};

#endif // ENEMY_PRO_H
