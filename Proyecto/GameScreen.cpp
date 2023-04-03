//
// Created by oscaraad on 03/04/23.
//


#include <QWidget>
#include <QThread>
#include <iostream>
#include "GameScreen.h"
#include "SerialWorker.h"


using namespace std;
QThread workerThread; // variable global para el hilo

GameScreen::GameScreen(int Dificultad, QWidget *parent){
    QGraphicsScene *scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, 1000, 1000);


    qRegisterMetaType<ListaSimple>("ListaSimple");
    SerialWorker *worker = new SerialWorker();
    worker ->moveToThread(&workerThread);

    QObject::connect(worker, &SerialWorker::dataReceived, this, &GameScreen::animate);

    workerThread.start();

    show();
}

void GameScreen::animate(const ListaSimple &dataList) {
    dataList.printList();
}

