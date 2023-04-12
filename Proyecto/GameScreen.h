


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

class GameScreen: public QGraphicsView{
Q_OBJECT
private:
    Player *player;
    ListaSimple dataList;
    SimpleList<Bullets*> bulletsList;
    SimpleList<EasyEnemy*> easyEnemys;

    QThread workerThread;
    SerialWorker* worker;
    QTimer* timer;
    int cantBullets;
    int cantVidas;
    int poteDisparo;
    int faseJuego;
    int oleadaJuego;


    int velocidadEnemigos;
    int EnemigosFaciles;
    int EnemigosMedios;
    int EnemigosDificiles;

    int infoOleadas;
public:
    GameScreen(int Dificultad, QWidget * parent = 0);
public slots:
    void animate(const ListaSimple &dataList);
    void shootBullets();
    void spawnEnemys();
    void moveEnemys();
    void checkCollisions();
    //void fireBullets(const ListaSimple &dataList);
};


#endif //BATTLE_SPACE_GAMESCREEN_H