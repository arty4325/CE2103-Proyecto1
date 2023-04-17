//
// Created by oscaraad on 16/04/23.
//

#ifndef BATTLE_SPACE_GAMEOVER_H
#define BATTLE_SPACE_GAMEOVER_H


#include <QGraphicsView>

class GameOver : public QGraphicsView{
public:
    GameOver(QWidget * parent = 0);


    QGraphicsScene *scene;
};


#endif //BATTLE_SPACE_GAMEOVER_H
