//
// Created by oscaraad on 12/04/23.
//

#ifndef BATTLE_SPACE_MEDIUMENEMY_H
#define BATTLE_SPACE_MEDIUMENEMY_H
#include <QGraphicsPixmapItem>

class MediumEnemy : public QGraphicsPixmapItem{
public:
    MediumEnemy(QGraphicsItem *parent = nullptr);

    void disminuirVida(int cantidad);

    int getVida();

private:
    int vida;
};


#endif //BATTLE_SPACE_MEDIUMENEMY_H
