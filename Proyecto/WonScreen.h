//
// Created by oscaraad on 16/04/23.
//

#ifndef BATTLE_SPACE_WONSCREEN_H
#define BATTLE_SPACE_WONSCREEN_H

#include <QGraphicsView>
#include <QWidget>

class WonScreen : public QGraphicsView{
public:
    WonScreen(QWidget * parent = 0);

    QGraphicsScene * scene;
};


#endif //BATTLE_SPACE_WONSCREEN_H
