#ifndef REGALO_H
#define REGALO_H
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>
#include <math.h>

class Regalo: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    int velocidad=5;

public:
    Regalo(QGraphicsItem * parent = 0);
    int getVelocidad() const;
    void setVelocidad(int newVelocidad);

public slots:
    void move();
};

#endif // REGALO_H
