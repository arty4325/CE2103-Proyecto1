//
// Created by oscaraad on 12/04/23.
//

#include "EasyEnemy.h"
#include <QDir>


EasyEnemy::EasyEnemy(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), vida(100) {
        QString direc = QDir::currentPath();
        QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/enemigoVerde.png");
        setPixmap(imagen.scaled(50, 50));
}

void EasyEnemy::disminuirVida(int cantidad) {
    vida -= cantidad;
}