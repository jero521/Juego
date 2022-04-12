#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsRectItem{
    Q_OBJECT

int salud=100;
int ganancia=10;
public:
Enemy(QGraphicsItem * parent = 0);
int getSalud() const;
void setSalud(int newSalud);

int getGanancia() const;

public slots:
    void move();

};




#endif // ENEMY_H
