//
// Created by oscaraad on 03/04/23.
//


#include <QWidget>
#include <QThread>
#include <iostream>
#include <QGraphicsRectItem>
#include "GameScreen.h"
#include "SerialWorker.h"


using namespace std;
QThread workerThread; // variable global para el hilo

GameScreen::GameScreen(int Dificultad, QWidget *parent)
{
    if (Dificultad == 1){
        cantBullets = 10;
        cantVidas = 3;
        poteDisparo = 0;
        faseJuego = 0;
        oleadaJuego = 0;
    }

    QGraphicsScene *scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, 1000, 700);


    rectangle = new QGraphicsRectItem(0, 0, 50, 50);
    rectangle -> setPos(100, 100);
    scene -> addItem(rectangle);


    qRegisterMetaType<ListaSimple>("ListaSimple");
    SerialWorker *worker = new SerialWorker();
    worker ->moveToThread(&workerThread);

    QObject::connect(worker, &SerialWorker::dataReceived, this, &GameScreen::animate);

    workerThread.start();


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000, 700);


    show();
}

void GameScreen::animate(const ListaSimple &dataList) {
    //dataList.printList();
    //cout << dataList.getPosVal(4) << endl;


    if (dataList.getPosVal(5) <= 300) {
        cout << "El objeto se mueve para abajo" << endl;
        QPointF  rectPos = rectangle -> pos();
        rectangle -> setPos(rectPos.x(), rectPos.y() + 10 );
    }
    else if (dataList.getPosVal(5)  >= 600) {
        cout << "El objeto se mueve para arriba" << endl;
        QPointF  rectPos = rectangle -> pos();
        rectangle -> setPos(rectPos.x(), rectPos.y() - 10 );
    }
}

