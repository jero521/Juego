#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Health : public QGraphicsTextItem{
  public:
    Health(QGraphicsItem * parent = 0);
    void decrease();
    void increase();
    int getHealth();

    void setHealth(int newHealth);

private:
    int health;
    QMediaPlayer * soungolpe;

};




#endif // HEALTH_H
