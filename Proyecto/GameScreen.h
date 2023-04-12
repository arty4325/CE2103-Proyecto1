


//
// Created by oscaraad on 03/04/23.
//

#ifndef BATTLE_SPACE_GAMESCREEN_H
#define BATTLE_SPACE_GAMESCREEN_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QSerialPort>
#include <QThread>
#include <QTimer>
#include "ListaSimple.h"
#include "Player.h"
#include "Bullets.h"
#include "SimpleList.h"
#include "SimpleList.cpp"
#include "EasyEnemy.h"
#include "SerialWorker.h"
#include "MediumEnemy.h"

class GameScreen: public QGraphicsView{
Q_OBJECT
private:
    Player *player;
    ListaSimple dataList;
    SimpleList<Bullets*> bulletsList;
    SimpleList<EasyEnemy*> easyEnemys;
    SimpleList<MediumEnemy*> mediumEnemys;

    QThread workerThread;
    SerialWorker* worker;

    int oleada;

    int cantBullets;
    int cantVidas;
    int poteDisparo;
    int faseJuego;
    int oleadaJuego;

    QTimer* moveTimer;
    QTimer* timer;

    int velocidadEnemigos;
    int EnemigosFaciles;
    int EnemigosMedios;
    int EnemigosDificiles;

    int infoOleadas[5][4] = {
            {10, 10, 0, 0},
            {8, 15, 5, 0},
            {6, 15, 10, 0},
            {4, 15, 15, 0},
            {2, 10, 25, 0}
    };;

    bool cambioOleada;
    //bool primeraOleada;

public:
    GameScreen(int Dificultad, QWidget * parent = 0);
public slots:
    void animate(const ListaSimple &dataList);
    void shootBullets();
    void spawnEnemys();
    void moveEnemys();
    void checkCollisions();
    void checkOleada();
    //void fireBullets(const ListaSimple &dataList);
};


#endif //BATTLE_SPACE_GAMESCREEN_H