#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

int Dano=100;
public:
    Bullet();

    int getDano() const;

public slots:
        void move();

};

#endif // BULLET_H
