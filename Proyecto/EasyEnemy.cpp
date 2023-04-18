//
// Created by oscaraad on 12/04/23.
//

#include "EasyEnemy.h"
#include <QDir>

/**
 * @brief Metodo constructor de la clase EasyEnemy
 */
EasyEnemy::EasyEnemy(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), vida(100) {
        QString direc = QDir::currentPath();
        QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/enemigoVerde.png");
        setPixmap(imagen.scaled(50, 50));
}
/**
 * @brief Permite disminuir la vida del enemigo facil
 * @param La cantidad de vida que se le va a disminuir al enemigo facil
 */
void EasyEnemy::disminuirVida(int cantidad) {
    vida -= cantidad;
}

/**
 * @brief Permite obtejer la vida que tiene en ese momento el enemigo facil
 * @return El valor de vida que tiene el enemigo en ese momento
 */
int EasyEnemy::getVida(){
    return vida;
}