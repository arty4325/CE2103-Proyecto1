


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
#include <iostream>

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
    string labelsPoderes[4][2] = {
            {"Balas ilimitadas 5s", "Jugador 25% rapido"},
            {"Elim naves en pantalla", "Elim todos los dif media de oleada"},
            {"Baja vida naves 25%", "Balas mas rapidas"},
            {"Elimina ultima fase", "Congela naves enem"}
    };

    Player *player;
    ListaSimple dataList;
    SimpleList<Bullets*> bulletsList;
    SimpleList<Bullets*> bulletCollector;
    SimpleList<EasyEnemy*> easyEnemys;
    SimpleList<MediumEnemy*> mediumEnemys;
    SimpleList<string> labelsPowers;
    SimpleList<string> primeraStrat;
    SimpleList<string> segundaStrat;
    SimpleList<string> terceraStrat;
    SimpleList<string> cuartaStrat;
    SimpleList<DifficultEnemy*> difficultEnemys;
    //SimpleList<SimpleList<int>> stratsLoaded;
    SimpleList<int> firstStrat;
    SimpleList<int> secondStrat;




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
    int tempCantBullets;
    int cantVidas;
    int velocidadJugador;
    int velocidadBalas;
    int onePixel;
    int twoPixels;
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
    int tempSelecPower;
    // En el arreglo el orden de la info es:
    // velocidad, enemigos faciles, enemigos medios, enemigos dificiles

    int infoOleadas[5][4] = {
            {10, 0, 0},
            {15, 5, 0},
            {15, 10, 0},
            {15, 15, 0},
            {10, 25, 0}
    };



    bool hasChoosedPower;
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
    void exePower(int tempSelecStrat, int tempSelecPower);
    void pararEjecucion();

    void stopFirstFirt();
    void stopFirstSecond();
    void stopSecondSecond();
    //void stopThirdFirst();
    //void stopThirdSecond();
    //void stopFourthFirst();
    void stopFourthSecond();


    //void fireBullets(const ListaSimple &dataList);
};


#endif //BATTLE_SPACE_GAMESCREEN_H