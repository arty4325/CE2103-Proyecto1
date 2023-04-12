//
// Created by oscaraad on 03/04/23.
//


#include <QWidget>
#include <QThread>
#include <QTimer>
#include <iostream>
#include <QGraphicsRectItem>
#include <QSerialPort>
#include <QDir>
#include <QRandomGenerator>
#include "GameScreen.h"
#include "SerialWorker.h"
#include "Player.h"
#include "Bullets.h"
#include "EasyEnemy.h"
#include "MediumEnemy.h"
//#include "SimpleList.h"


using namespace std;
QThread workerThread; // variable global para el hilo

GameScreen::GameScreen(int Dificultad, QWidget *parent)
{
    if (Dificultad == 1){
        cantBullets = 400;
        cantVidas = 3;
        oleada = 0;
        // En el arreglo el orden de la info es:
        // velocidad, enemigos faciles, enemigos medios, enemigos dificiles

        /*
        int infoOleadas[5][4] = {
                {10, 10, 0, 0},
                {8, 15, 5, 0},
                {6, 15, 10, 0},
                {4, 15, 15, 0},
                {2, 10, 25, 0}
        };
        */


        //primeraOleada = true;
        cambioOleada = false;
        velocidadEnemigos = infoOleadas[0][0];
        EnemigosFaciles = infoOleadas[0][1];
        EnemigosMedios = infoOleadas[0][2];
        EnemigosDificiles = infoOleadas[0][3];
    }




    QString path = QDir::currentPath();
    std::string pathStr = path.toStdString();
    std::cout << "Directorio actual: " << pathStr << std::endl;

    QTimer *oleadaTimer = new QTimer(this);
    connect(oleadaTimer, &QTimer::timeout, this, &GameScreen::checkOleada);
    oleadaTimer -> setInterval(1000);
    oleadaTimer -> start();



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

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &GameScreen::moveEnemys);
    moveTimer ->setInterval(velocidadEnemigos);
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
    worker = new SerialWorker();
    worker ->moveToThread(&workerThread);

    QObject::connect(worker, &SerialWorker::dataReceived, this, &GameScreen::animate);


    workerThread.start();


    //worker -> writeData("6");

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

    for (int i = 0; i < bulletsList.getSize(); i++){
        Bullets* bullet = bulletsList.getPosVal(i);
        bullet ->setPos(bullet->pos().x() + 10, bullet -> pos().y());
    }


    //cout << player -> pos().y() << endl;
    if ((dataList.getPosVal(5) <= 300) && (player -> pos().y() < 500)) {
        //cout << "El objeto se mueve para abajo" << endl;
        //QPointF  rectPos = rectangle -> pos();
        //rectangle -> setPos(rectPos.x(), rectPos.y() + 10 );
        player->setPos(player->pos().x(), player->pos().y() + 20);
    }
    else if ((dataList.getPosVal(5)  >= 600) && (player -> pos().y() > 100)){
        //cout << "El objeto se mueve para arriba" << endl;
        //QPointF  rectPos = rectangle -> pos();
        //rectangle -> setPos(rectPos.x(), rectPos.y() - 10 );
        player->setPos(player->pos().x(), player->pos().y() - 20);
    }
}

void GameScreen::shootBullets(){
    //cout << dataList.getPosVal(3) << endl;

    int waitTime = dataList.getPosVal(3)*5;


    Bullets* bullets = new Bullets();
    bullets->setPos(player->pos().x(),player->pos().y());
    scene()->addItem(bullets);


    //test.insertHead(bullets);
    bulletsList.insertHead(bullets);

}

void GameScreen::spawnEnemys() {
    //cout << "PRUEBAS" << endl;
    int randomY = qrand() % 400;
    randomY += 100;
    //cout << randomY + 100 << endl;

    int num = QRandomGenerator::global() -> bounded(1, 4);

    if (num == 1 && EnemigosFaciles != 0) {
        cout << EnemigosFaciles << " Aparecio un facil" << endl;
        EasyEnemy *easyEnemy = new EasyEnemy();
        easyEnemy->setPos(1050, randomY);
        scene()->addItem(easyEnemy);
        easyEnemys.insertHead(easyEnemy);
        EnemigosFaciles -= 1;
    } else if (num == 2 && EnemigosMedios != 0){
        MediumEnemy *mediumEnemy = new MediumEnemy();
        mediumEnemy -> setPos(1050, randomY);
        scene() -> addItem(mediumEnemy);
        mediumEnemys.insertHead(mediumEnemy);
        EnemigosMedios -= 1;
    } else if (num == 3 && EnemigosDificiles != 0){
        cout << "AUN NO SE DEFINE ESTE ENEMIGO" << endl;
    } else if (EnemigosFaciles == 0 && EnemigosMedios == 0 && EnemigosDificiles == 0){
        cout << "Suave un touqe, se acabo la oleada" << endl;
    }
    else {
        cout << "NO APARECIO DE LO OTRO Y SE TUVO QUE LLAMAR A ESTO " << endl;
        return spawnEnemys();
    }



}

void GameScreen::moveEnemys() {
    //cout << easyEnemys.getSize() << endl;
    for (int i = 0; i < easyEnemys.getSize(); i++){
        EasyEnemy* tempEnemy = easyEnemys.getPosVal(i);
        tempEnemy -> setPos(tempEnemy->pos().x() - 1, tempEnemy->pos().y());
        if (tempEnemy-> pos().x() <= 0 ){
            cout << "SE SALIO" << endl;
            worker -> writeData("6");
            scene() -> removeItem(tempEnemy);
            easyEnemys.deletePos(i);
            delete tempEnemy;
            //worker -> writeData("6");
        }
    }
    for (int i = 0; i < mediumEnemys.getSize(); i++){
        MediumEnemy* tempEnemy = mediumEnemys.getPosVal(i);
        tempEnemy -> setPos(tempEnemy ->pos().x() - 2, tempEnemy->pos().y());
        if (tempEnemy -> pos().x() <= 0){
            cout << "SE SALIO MEDIUM " << endl;
            worker -> writeData("6");
            scene() ->removeItem(tempEnemy);
            mediumEnemys.deletePos(i);
            delete tempEnemy;
        }
    }
}


void GameScreen::checkCollisions() {
    for (int i = 0; i < bulletsList.getSize(); i++){
        for (int j = 0; j < easyEnemys.getSize(); j++) {
            Bullets* bullet = bulletsList.getPosVal(i);
            EasyEnemy* enemy = easyEnemys.getPosVal(j);
            if (bullet ->collidesWithItem(enemy)) {
                scene() -> removeItem(bullet);
                scene() -> removeItem(enemy);
                bulletsList.deletePos(i);
                easyEnemys.deletePos(j);
                delete bullet;
                delete enemy;
                //worker -> writeData("6");
            }
        }
        for (int j = 0; j < mediumEnemys.getSize(); j++){
            Bullets* bullet = bulletsList.getPosVal(i);
            MediumEnemy* enemy = mediumEnemys.getPosVal(j);
            if (bullet ->collidesWithItem(enemy)) {
                scene() ->removeItem(bullet);
                scene() -> removeItem(enemy);
                bulletsList.deletePos(i);
                mediumEnemys.deletePos(j);
                delete bullet;
                delete enemy;
            }
        }
    }
}


void GameScreen::checkOleada(){
    cout << "REVISA EN QUE OLEADA ESTA " << oleada << endl;
    if (EnemigosFaciles == 0 && EnemigosMedios == 0 && EnemigosDificiles == 0){
        cout << "Se acabo la oleada " << endl;
        oleada += 1;
        velocidadEnemigos = infoOleadas[oleada][0];
        EnemigosFaciles = infoOleadas[oleada][1];
        EnemigosMedios = infoOleadas[oleada][2];
        EnemigosDificiles = infoOleadas[oleada][3];
        moveTimer ->setInterval(velocidadEnemigos);
    }
    string strOleada = to_string(oleada);
    QByteArray byteArray = QByteArray::fromStdString(strOleada);
    worker -> writeData(byteArray);
}