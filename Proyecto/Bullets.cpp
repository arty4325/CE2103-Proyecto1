//
// Created by oscaraad on 11/04/23.
//

#include <QGraphicsItem>
#include "Bullets.h"
#include <QDir>

Bullets::Bullets(QGraphicsItem *parent)
: QGraphicsPixmapItem(parent), damage(100) {
    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/Bullet.png");
    setPixmap(imagen.scaled(50, 50));
}


void Bullets::disminuirDano() {
    damage = damage*0.8;
}

int Bullets::getDano() {
    return damage;
}
