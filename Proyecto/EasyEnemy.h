//
// Created by oscaraad on 12/04/23.
//

#ifndef BATTLE_SPACE_EASYENEMY_H
#define BATTLE_SPACE_EASYENEMY_H
#include <QGraphicsPixmapItem>


class EasyEnemy : public QGraphicsPixmapItem{
public:
    EasyEnemy(QGraphicsItem *parent = nullptr);

    void disminuirVida(int cantidad);

    int getVida();

private:
    int vida;
};


#endif //BATTLE_SPACE_EASYENEMY_H
