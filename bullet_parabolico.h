#ifndef BULLET_PARABOLICO_H
#define BULLET_PARABOLICO_H


#include <QPixmap>
#include <QObject>
#include <math.h>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Bullet_parabolico: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    double posx;
    double posy;
    double vel=70;
    double ang=(30*3.14159)/180;
    double velX;
    double vely;
    int Dano=100;
public:
    Bullet_parabolico();
    void CalcularPosicion();
    void CalcularVelocidad();
    void ActualizarVelocidad();

    int getDano() const;

public slots:
        void move();
private:
        QMediaPlayer * sounbomba;

};
#endif // BULLET_PARABOLICO_H
