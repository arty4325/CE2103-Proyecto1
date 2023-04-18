//
// Created by oscaraad on 16/04/23.
//

#include <QGraphicsItem>
#include <QDir>
#include "DifficultEnemy.h"

/**
 * @brief Metodo construtor del enemigo Dificil
 */
DifficultEnemy::DifficultEnemy(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), vida(150) {
        QString direc = QDir::currentPath();
        QPixmap imagen(direc.mid(0, direc.length() - 18 )+ "/Imagenes/enemigoRojo.png");
        setPixmap(imagen.scaled(50, 50));
}

/**
 * @brief Permite disminuir la vida de un enemigo
 * @param La cantidad de vida que se le va a disminuir
 */
void DifficultEnemy::disminuirVida(int cantidad) {
    vida -= cantidad;
}

/**
 * @brief Permite obtener el valor de vida que en ese momento tiene el objeto
 * @return El valor de vida que tiene en ese momento el objeto
 */
int DifficultEnemy::getVida(){
    return vida;
}

/**
 * @brief Permite obtejer la direccion a la cual se esta moviendo el objeto (Arriba o Abajo)
 * @return un booleano que describe la direccion vertical a la que se mueve el objeto
 */
bool DifficultEnemy::getDirection(){
    return direction;
}

/**
 * @brief Permite definirle una direccion al objeto
 * @param el valor booleano que describe la direccion del objeto
 */
void DifficultEnemy::setDirection(bool value) {
    direction = value;
}

