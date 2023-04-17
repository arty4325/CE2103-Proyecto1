


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
#include <QLabel>
#include "ListaSimple.h"
#include "Player.h"
#include "Bullets.h"
#include "SimpleList.h"
#include "SimpleList.cpp"
#include "EasyEnemy.h"
#include "SerialWorker.h"
#include "MediumEnemy.h"
#include "DifficultEnemy.h"
class GameScreen: public QGraphicsView{
Q_OBJECT
private:
    Player *player;
    ListaSimple dataList;
    SimpleList<Bullets*> bulletsList;
    SimpleList<Bullets*> bulletCollector;
    SimpleList<EasyEnemy*> easyEnemys;
    SimpleList<MediumEnemy*> mediumEnemys;
    SimpleList<string> labelsPowers;
    SimpleList<DifficultEnemy*> difficultEnemys;

    QThread workerThread;
    SerialWorker* worker;


    QLabel *labelBalas;
    QLabel *labelCollector;
    QLabel *labelOleada;
    QLabel *labelVidas;
    QLabel *labelEnemOleadas;
    QLabel *labelFase;
    QLabel *labelStrat;

    int oleada;
    int fase;

    int cantBullets;
    int cantVidas;
    int velocidadJugador;
    int poteDisparo;
    int faseJuego;
    int oleadaJuego;

    QTimer* moveTimer;
    QTimer* timer;
    QTimer* spawnTimer;
    QTimer* collisionTimer;
    QTimer* oleadaTimer;

    int velocidadEnemigos;
    int EnemigosFaciles;
    int EnemigosMedios;
    int EnemigosDificiles;
    int tempSelecStrat;
    // En el arreglo el orden de la info es:
    // velocidad, enemigos faciles, enemigos medios, enemigos dificiles

    int infoOleadas[5][4] = {
            {10, 0, 0},
            {15, 5, 0},
            {15, 10, 0},
            {15, 15, 0},
            {10, 25, 0}
    };



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