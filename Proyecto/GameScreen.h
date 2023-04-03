


//
// Created by oscaraad on 03/04/23.
//

#ifndef BATTLE_SPACE_GAMESCREEN_H
#define BATTLE_SPACE_GAMESCREEN_H

#include <QGraphicsView>
#include "ListaSimple.h"

class GameScreen: public QGraphicsView{
Q_OBJECT
public:
    GameScreen(int Dificultad, QWidget * parent = 0);
    void animate(const ListaSimple &dataList);
    
};


#endif //BATTLE_SPACE_GAMESCREEN_H