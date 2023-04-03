//
// Created by oscaraad on 03/04/23.
//

#ifndef BATTLE_SPACE_GAMESCREEN_H
#define BATTLE_SPACE_GAMESCREEN_H

#include <QGraphicsView>

class GameScreen: public QGraphicsView{
    Q_OBJECT
public:
    GameScreen(int Dificultad, QWidget * parent = 0);
};


#endif //BATTLE_SPACE_GAMESCREEN_H
