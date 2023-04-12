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
#include "EasyEnemy.h"
//#include "SimpleList.h"


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
    spawnTimer -> setInterval(2000);
    spawnTimer -> start();

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &GameScreen::moveEnemys);
    moveTimer ->setInterval(4);
    moveTimer -> start();

    QTimer *collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &GameScreen::checkCollisions);
    collisionTimer ->setInterval(4);
    collisionTimer -> start();
    

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


    //cout << player -> pos().y() << endl;
    if ((dataList.getPosVal(5) <= 300) && (player -> pos().y() < 500)) {
        //cout << "El objeto se mueve para abajo" << endl;
        //QPointF  rectPos = rectangle -> pos();
        //rectangle -> setPos(rectPos.x(), rectPos.y() + 10 );
        player->setPos(player->pos().x(), player->pos().y() + 10);
    }
    else if ((dataList.getPosVal(5)  >= 600) && (player -> pos().y() > 100)){
        //cout << "El objeto se mueve para arriba" << endl;
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


    //test.insertHead(bullets);
    bulletsList.append(bullets);
    //test.printList();
}

void GameScreen::spawnEnemys() {
    //cout << "PRUEBAS" << endl;
    int randomY = qrand() % 400;
    randomY += 100;
    //cout << randomY + 100 << endl;
    EasyEnemy* easyEnemy = new EasyEnemy();
    easyEnemy -> setPos(1050, randomY);
    scene() -> addItem(easyEnemy);

    easyEnemys.insertHead(easyEnemy);



}

void GameScreen::moveEnemys() {
    //cout << easyEnemys.getSize() << endl;
    for (int i = 0; i < easyEnemys.getSize(); i++){
        EasyEnemy* tempEnemy = easyEnemys.getPosVal(i);
        tempEnemy -> setPos(tempEnemy->pos().x() - 1, tempEnemy->pos().y());
    }
}


void GameScreen::checkCollisions() {
    for (int i = 0; i < bulletsList.size(); i++){
        for (int j = 0; j < easyEnemys.getSize(); j++) {
            Bullets* bullet = bulletsList.at(i);
            EasyEnemy* enemy = easyEnemys.getPosVal(j);
            if (bullet ->collidesWithItem(enemy)) {
                scene() -> removeItem(bullet);
                scene() -> removeItem(enemy);
                bulletsList.removeAt(i);
                easyEnemys.deletePos(j);
                delete bullet;
                delete enemy;

            }
        }
    }
}
