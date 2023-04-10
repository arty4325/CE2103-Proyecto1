//
// Created by oscaraad on 10/04/23.
//

#include "Enemigos.h"
#include <QDir>


Enemigos::Enemigos(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), vida(1) {


    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/enemigoRojo/ship.png");
    setPixmap(imagen.scaled(-50, 50));
}

void Enemigos::disminuirVida(int cantidad) {
    vida -= cantidad;
}