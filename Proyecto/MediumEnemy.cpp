//
// Created by oscaraad on 12/04/23.
//

#include "MediumEnemy.h"
#include <QDir>
/**
 * @brief
 * @param parent
 */
MediumEnemy::MediumEnemy(QGraphicsItem *parent)
: QGraphicsPixmapItem(parent), vida(200) {
    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/enemigoCafe.png");
    setPixmap(imagen.scaled(50, 50));
}

void MediumEnemy::disminuirVida(int cantidad) {
    vida -= cantidad;
}

int MediumEnemy::getVida() {
    return vida;
}