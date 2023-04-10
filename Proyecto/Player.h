//
// Created by oscaraad on 05/04/23.
//

#ifndef BATTLE_SPACE_PLAYER_H
#define BATTLE_SPACE_PLAYER_H

#include <QGraphicsPixmapItem>

class Player : public QGraphicsPixmapItem {
public:
    Player(QGraphicsItem *parent = nullptr);

    void disminuirBalas();
    void disminuirVida(int cantidad);
    void aumentarVida(int cantidad);

private:
    int cantidadBalas;
    int vida;
};


#endif //BATTLE_SPACE_PLAYER_H
