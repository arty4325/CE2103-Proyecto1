//
// Created by oscaraad on 10/04/23.
//

#include "Enemigos.h"
#include <QDir>

/**
 * @brief Metodo constructor de la clase Enemigos
 */
Enemigos::Enemigos(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), vida(1) {


    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/enemigoRojo/ship.png");
    setPixmap(imagen.scaled(-50, 50));
}

/**
 * @brief Permite disminuir la vida que
 * @param cantidad de vida que se le va a quitar al enemigo
 */
void Enemigos::disminuirVida(int cantidad) {
    vida -= cantidad;
}