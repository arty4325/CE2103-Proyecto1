//
// Created by oscaraad on 11/04/23.
//

#ifndef BATTLE_SPACE_BULLETS_H
#define BATTLE_SPACE_BULLETS_H
#include <QGraphicsPixmapItem>

class Bullets : public QGraphicsPixmapItem{
public:
    Bullets(QGraphicsItem *parent = nullptr);

    void disminuirDano();
    int getDano();
private:
    int damage;
};


#endif //BATTLE_SPACE_BULLETS_H
