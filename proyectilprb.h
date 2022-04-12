#ifndef PROYECTILPRB_H
#define PROYECTILPRB_H
#include <math.h>
#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>
#include <QTimer>

//#define delta 0.01
//#define g 9.8

class Proyectilprb :  public QObject, public QGraphicsItem
{
    //atributos
    double posx;
    double posy;
    double vel;
    double ang;
    double velX;
    double vely;
    int r;
public:
    Proyectilprb();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void CalcularPosicion();
    void CalcularVelocidad();
    void ActualizarVelocidad();
    double getPosx() const;
    double getPosy() const;
public slots:
    void move();
};


#endif // PROYECTILPRB_H
