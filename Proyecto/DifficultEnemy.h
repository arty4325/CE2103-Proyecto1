//
// Created by oscaraad on 16/04/23.
//

#ifndef BATTLE_SPACE_DIFFICULTENEMY_H
#define BATTLE_SPACE_DIFFICULTENEMY_H
#include <QGraphicsPixmapItem>

class DifficultEnemy : public QGraphicsPixmapItem{
public:
    DifficultEnemy(QGraphicsItem *parent = nullptr);
    void disminuirVida(int cantidad);
    bool getDirection();
    void setDirection(bool value);
    int getVida();
private:
    int vida;
    bool direction; // true es arriba y false es abajo;
};


#endif //BATTLE_SPACE_DIFFICULTENEMY_H
