//
// Created by oscaraad on 11/04/23.
//

#include <QGraphicsItem>
#include "Bullets.h"
#include <QDir>

Bullets::Bullets(QGraphicsItem *parent)
: QGraphicsPixmapItem(parent) {
    QString direc = QDir::currentPath();
    QPixmap imagen(direc.mid(0, direc.length() - 18) + "/Imagenes/ship.png");
    setPixmap(imagen.scaled(50, 50));
}