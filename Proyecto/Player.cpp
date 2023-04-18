//
// Created by oscaraad on 05/04/23.
//

#include "Player.h"
#include <QDir>

/**
 * @brief Metodo constructor de la clase Player
 */
Player::Player(QGraphicsItem *parent)
        : QGraphicsPixmapItem(parent), cantidadBalas(10), vida(100) {
    // Configurar imagen del jugador
    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/ship.png");
    setPixmap(imagen.scaled(50, 50));
}


/**
 * @brief Disminuye las balas que el jugador tiene disponibles
 */
void Player::disminuirBalas() {
    cantidadBalas--;
}

/**
 * @brief Disminuye la vida que el jugador tiene disponible
 * @param cantidad Cantidad de vida que se le va a disminuir al Jugador
 */
void Player::disminuirVida(int cantidad) {
    vida -= cantidad;
}

/**
 * @brief Aumenta la vida del jugador
 * @param cantidad Cantidad de vida que se le va a aumentar al jugador
 */
void Player::aumentarVida(int cantidad) {
    vida += cantidad;
}


