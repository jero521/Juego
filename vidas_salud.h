#ifndef VIDAS_SALUD_H
#define VIDAS_SALUD_H
#include <QGraphicsTextItem>



class vidas_salud : public QGraphicsTextItem
{

    //Atrivutos//
    int Salud;
    int Vidas;


public:
    vidas_salud(QGraphicsItem * parent = 0);

    //Funciones//
    int Getvida();
    void Decrease();
    int Getsalud();




};

#endif // VIDAS_SALUD_H
