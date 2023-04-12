//
// Created by oscaraad on 03/04/23.
//


#include <QWidget>
#include <QThread>
#include <QTimer>
#include <iostream>
#include <QGraphicsRectItem>
#include <QDir>
#include "GameScreen.h"
#include "SerialWorker.h"
#include "Player.h"
#include "Bullets.h"



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

    QString path = QDir::currentPath();
    std::string pathStr = path.toStdString();
    std::cout << "Directorio actual: " << pathStr << std::endl;


    // Esto es lo que permite manejar a las balas
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameScreen::shootBullets);
    timer -> setInterval(500);
    timer -> start();

    // Ahora voy a hacer un timer que permita manejar la aparicion de los enemigos
    // Dependiendo de la oleada en la que se esta
    QTimer *spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &GameScreen::spawnEnemys);
    spawnTimer -> setInterval(500);
    spawnTimer -> start();

    QGraphicsScene *scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, 1000, 700);

    // Cargar la imagen

    QString direc = QDir::currentPath();
    QPixmap backgroundImage(direc.mid(0,direc.length() - 18) + "/Imagenes/fondo.jpg");
    if (backgroundImage.isNull()) {
        cout << "Error: no se pudo cargar la imagen de fondo.";
    }
    else {
        // Crear un objeto QBrush a partir de la imagen
        QBrush backgroundBrush(backgroundImage);

        // Establecer el pincel de fondo de la escena con el objeto QBrush
        scene->setBackgroundBrush(backgroundBrush);
    }


    //rectangle = new QGraphicsRectItem(0, 0, 50, 50);
    //rectangle -> setPos(100, 100);
    //scene -> addItem(rectangle);

    // Crear jugador y agregar a la escena
    player = new Player();
    player -> setPos(100, 100);
    scene -> addItem(player);


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
    //cout << dataList.getPosVal(3) << endl;
    //fireBullets(dataList);
    this->dataList = dataList;
    this->bulletsList = bulletsList;
    for (int i = 0; i < bulletsList.size(); i++){
        Bullets* bullet = bulletsList.at(i);
        bullet ->setPos(bullet->pos().x() + 10, bullet -> pos().y());
    }


    cout << player -> pos().y() << endl;
    if ((dataList.getPosVal(5) <= 300) && (player -> pos().y() < 500)) {
        cout << "El objeto se mueve para abajo" << endl;
        //QPointF  rectPos = rectangle -> pos();
        //rectangle -> setPos(rectPos.x(), rectPos.y() + 10 );
        player->setPos(player->pos().x(), player->pos().y() + 10);
    }
    else if ((dataList.getPosVal(5)  >= 600) && (player -> pos().y() > 100)){
        cout << "El objeto se mueve para arriba" << endl;
        //QPointF  rectPos = rectangle -> pos();
        //rectangle -> setPos(rectPos.x(), rectPos.y() - 10 );
        player->setPos(player->pos().x(), player->pos().y() - 10);
    }
}

void GameScreen::shootBullets(){
    //cout << dataList.getPosVal(3) << endl;

    int waitTime = dataList.getPosVal(3)*5;


    Bullets* bullets = new Bullets();
    bullets->setPos(player->pos().x(),player->pos().y());
    scene()->addItem(bullets);

    bulletsList.append(bullets);

}

void GameScreen::spawnEnemys() {
    cout << "PRUEBAS" << endl;

}

