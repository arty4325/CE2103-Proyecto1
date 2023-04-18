//
// Created by oscaraad on 11/04/23.
//

#include <QGraphicsItem>
#include "Bullets.h"
#include <QDir>

/**
 * @brief Metodo constructor de la clase Bullets
 */
Bullets::Bullets(QGraphicsItem *parent)
: QGraphicsPixmapItem(parent), damage(100) {
    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/Bullet.png");
    setPixmap(imagen.scaled(50, 50));
}

/**
 * @brief Permite disminuir el dano de las balas en un 20%
 */
void Bullets::disminuirDano() {
    damage = damage*0.8;
}

/**
 * @brief Permite obtener el valor del dano generado por las balas
 * @return Retorna el valor del dano ejercido por la bala
 */
int Bullets::getDano() {
    return damage;
}

/**
 * @brief Permite designarle un dano a la bala
 * @param El valor de dano que se va a establecer
 */
void Bullets::setDano(int dano) {
    damage = dano;
}

