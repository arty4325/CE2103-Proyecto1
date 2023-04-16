//
// Created by oscaraad on 02/04/23.
//

#ifndef BATTLE_SPACE_MENUDIFICULTADES_H
#define BATTLE_SPACE_MENUDIFICULTADES_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class MenuDificultades: public QGraphicsView{
public:
    MenuDificultades(QWidget * parent = 0);

    void easy();
    void medium();
    void difficult();


    QGraphicsScene * scene;
};


#endif //BATTLE_SPACE_MENUDIFICULTADES_H
