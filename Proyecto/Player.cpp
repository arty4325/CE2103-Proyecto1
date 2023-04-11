//
// Created by oscaraad on 05/04/23.
//

#include "Player.h"
#include <QDir>


Player::Player(QGraphicsItem *parent)
        : QGraphicsPixmapItem(parent), cantidadBalas(10), vida(100) {
    // Configurar imagen del jugador
    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/ship.png");
    setPixmap(imagen.scaled(50, 50));
}



void Player::disminuirBalas() {
    cantidadBalas--;
}

void Player::disminuirVida(int cantidad) {
    vida -= cantidad;
}

void Player::aumentarVida(int cantidad) {
    vida += cantidad;
}


