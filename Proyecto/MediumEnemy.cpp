//
// Created by oscaraad on 12/04/23.
//

#include "MediumEnemy.h"
#include <QDir>
/**
 * @brief Metodo constructor de la clase MediumEnemy
 */
MediumEnemy::MediumEnemy(QGraphicsItem *parent)
: QGraphicsPixmapItem(parent), vida(200) {
    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/enemigoCafe.png");
    setPixmap(imagen.scaled(50, 50));
}

/**
 * @brief Permite disminuir la vida de el enemigo medio
 * @param cantidad La cantidad de vida que se le va a disminuir
 */
void MediumEnemy::disminuirVida(int cantidad) {
    vida -= cantidad;
}

/**
 * @brief Permite obtener la vida del enemigo medio
 * @return El valor de la vida del enemigo medio
 */
int MediumEnemy::getVida() {
    return vida;
}