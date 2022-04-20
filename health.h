#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Health : public QGraphicsTextItem{
  public:
    Health(QGraphicsItem * parent = 0);
    void decrease();
    int getHealth();

  private:
    int health;
    QMediaPlayer * hit;
};



#endif // HEALTH_H
