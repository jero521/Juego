#ifndef MOVIMIENTOPRB_H
#define MOVIMIENTOPRB_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

//#define delta 0.01
//#define g 9.8

class MovimientoPrb: public QGraphicsItem
{
    double posx;
    double posy;
    double vel;
    double ang;
    double velX;
    double vely;
    int r;
public:
    MovimientoPrb();
    MovimientoPrb(double x, double y, double v, double a );
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void CalcularPosicion();
    void CalcularVelocidad();
    void ActualizarVelocidad();
    double getPosx() const;
    double getPosy() const;
};

#endif // MOVIMIENTOPRB_H
