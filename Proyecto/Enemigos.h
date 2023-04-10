//
// Created by oscaraad on 10/04/23.
//

#ifndef BATTLE_SPACE_ENEMIGOS_H
#define BATTLE_SPACE_ENEMIGOS_H


#include <QGraphicsPixmapItem>

class Enemigos : public QGraphicsPixmapItem{
public:
    Enemigos(QGraphicsItem *parent = nullptr);

    void disminuirVida(int cantidad);

private:
    int vida;

};


#endif //BATTLE_SPACE_ENEMIGOS_H
