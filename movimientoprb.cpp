#include "movimientoprb.h"

double MovimientoPrb::getPosx() const
{
    return posx;
}

double MovimientoPrb::getPosy() const
{
    return posy;
}

MovimientoPrb::MovimientoPrb()
{
this->r=15;
}
MovimientoPrb::MovimientoPrb(double x, double y, double v, double a)
{
    this->posx=x;
    this->posy=y;
    this->vel=v;
    this->ang=a;
    this->r=15;
    setPos(posx,-posy);
}
QRectF MovimientoPrb::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void MovimientoPrb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setBrush(Qt::red);
  painter->drawEllipse(boundingRect());
}

void MovimientoPrb::CalcularPosicion()
{
     posx+=velX*0.01;
     posy+=vely*0.01-0.5*9.8*0.01*0.01;
     qDebug()<<"posx: "<<posx<<" posy: "<<posy<<'\n';
     setPos(posx,-posy);
}

void MovimientoPrb::CalcularVelocidad()
{
    velX=vel*cos(ang);
    vely=vel*sin(ang)-9.8*0.01;
}

void MovimientoPrb::ActualizarVelocidad()
{
    vel=sqrt(velX*velX+vely*vely);
    ang=atan2(vely,velX);
}
