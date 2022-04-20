#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QMediaPlayer>


class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

int Vel=10;
int Dinero=50;
int Municiones=30;

public:

    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent * event);

    void setDinero(int newDinero);
    int getDinero() const;

    int getVel() const;
    void setVel(int newVel);

    int getMuniciones() const;


    void setMuniciones(int newMuniciones);

public slots:
    void spawn();
    void spawn_tanque();
    void spawn_rango();

private:
    QMediaPlayer * sonbala;

    //QPixmap per;
};

#endif // PLAYER_H
