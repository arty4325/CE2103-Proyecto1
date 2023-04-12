


//
// Created by oscaraad on 03/04/23.
//

#ifndef BATTLE_SPACE_GAMESCREEN_H
#define BATTLE_SPACE_GAMESCREEN_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "ListaSimple.h"
#include "Player.h"

class GameScreen: public QGraphicsView{
Q_OBJECT
private:
    Player *player;
    ListaSimple dataList;
    int cantBullets;
    int cantVidas;
    int poteDisparo;
    int faseJuego;
    int oleadaJuego;
public:
    GameScreen(int Dificultad, QWidget * parent = 0);
public slots:
    void animate(const ListaSimple &dataList);
    void shootBullets();
    //void fireBullets(const ListaSimple &dataList);
};


#endif //BATTLE_SPACE_GAMESCREEN_H