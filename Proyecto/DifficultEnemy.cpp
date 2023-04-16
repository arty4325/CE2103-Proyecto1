//
// Created by oscaraad on 16/04/23.
//

#include <QGraphicsItem>
#include <QDir>
#include "DifficultEnemy.h"


DifficultEnemy::DifficultEnemy(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), vida(150) {
        QString direc = QDir::currentPath();
        QPixmap imagen(direc.mid(0, direc.length() - 18 )+ "/Imagenes/enemigoRojo.png");
        setPixmap(imagen.scaled(50, 50));
}

void DifficultEnemy::disminuirVida(int cantidad) {
    vida -= cantidad;
}

int DifficultEnemy::getVida(){
    return vida;
}

bool DifficultEnemy::getDirection(){
    return direction;
}

void DifficultEnemy::setDirection(bool value) {
    direction = value;
}

