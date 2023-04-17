//
// Created by oscaraad on 03/04/23.
//


#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include <string>
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

    if (Dificultad == 0){
        for(int i = 0; i <= 5; i++){
            for(int k = 0; k <= 4; k++){
                if (infoOleadas[i][k] != 0){
                    infoOleadas[i][k] -= 5;
                }
            }
        }
        fase = 1;
        cantBullets = 600;
        cantVidas = 15;
        oleada = 0;
        // En el arreglo el orden de la info es:
        // velocidad, enemigos faciles, enemigos medios, enemigos dificiles

        //primeraOleada = true;
        cambioOleada = false;
        //velocidadEnemigos = infoOleadas[0][0];
        velocidadEnemigos = 10;
        EnemigosFaciles = infoOleadas[0][0];
        EnemigosMedios = infoOleadas[0][1];
        EnemigosDificiles = infoOleadas[0][2];
    }
    if (Dificultad == 1){

        fase = 2;
        cantBullets = 400;
        cantVidas = 10;
        oleada = 0;
        // En el arreglo el orden de la info es:
        // velocidad, enemigos faciles, enemigos medios, enemigos dificiles

        //primeraOleada = true;
        cambioOleada = false;
        //velocidadEnemigos = infoOleadas[0][0];
        velocidadEnemigos = 8;
        EnemigosFaciles = infoOleadas[0][0];
        EnemigosMedios = infoOleadas[0][1];
        EnemigosDificiles = infoOleadas[0][2];
    }
    if (Dificultad == 2){
        for(int i = 0; i <= 5; i++){
            for(int k = 0; k <= 4; k++){
                infoOleadas[i][k] += 5;
            }
        }
        fase = 2;
        cantBullets = 200;
        cantVidas = 5;
        oleada = 0;
        // En el arreglo el orden de la info es:
        // velocidad, enemigos faciles, enemigos medios, enemigos dificiles

        //primeraOleada = true;
        cambioOleada = false;
        //velocidadEnemigos = infoOleadas[0][0];
        velocidadEnemigos = 6;
        EnemigosFaciles = infoOleadas[0][0];
        EnemigosMedios = infoOleadas[0][1];
        EnemigosDificiles = infoOleadas[0][2];
    }


    // En esta parte se va a estar definiendo los labels que dan cierta info del jugo
    labelBalas = new QLabel(this);
    labelBalas -> setText("Balas disponibles: " + QString::number(cantBullets));
    labelBalas->setStyleSheet("background-color: white; color: red;");
    labelBalas -> show();

    labelCollector = new QLabel(this);
    labelCollector ->setText("Balas en Collector: " + QString::number(bulletCollector.getSize()) + "    ");
    labelCollector -> setStyleSheet("background-color: white; color: red;");
    labelCollector -> move(0, 20);
    labelCollector -> show();

    labelOleada = new QLabel(this);
    labelOleada -> setText("Oleada: " + QString::number(oleada));
    labelOleada -> setStyleSheet("background-color: white; color: red;");
    labelOleada->move(150, 0);
    labelOleada -> show();

    labelVidas = new QLabel(this);
    labelVidas ->setText("Vidas: " + QString::number(cantVidas));
    labelVidas -> setStyleSheet("background-color: white; color: red;");
    labelVidas -> move(150, 20);
    labelVidas -> show();

    labelEnemOleadas =  new QLabel(this);
    labelEnemOleadas ->setText("Faciles: " + QString::number(EnemigosFaciles) +
    " Medios " + QString::number(EnemigosMedios) +
    " Dificiles: " + QString::number(EnemigosDificiles));
    labelEnemOleadas ->setStyleSheet("background-color: white; color: red;");
    labelEnemOleadas -> move(300, 0);
    labelEnemOleadas -> show();

    labelFase = new QLabel(this);
    labelFase ->setText("Fase: " + QString::number(fase));
    labelFase ->setStyleSheet("background-color: white; color: red;");
    labelFase -> move(300, 20);
    labelFase -> show();

    QString path = QDir::currentPath();
    std::string pathStr = path.toStdString();
    std::cout << "Directorio actual: " << pathStr << std::endl;

    QTimer *oleadaTimer = new QTimer(this);
    connect(oleadaTimer, &QTimer::timeout, this, &GameScreen::checkOleada);
    oleadaTimer -> setInterval(1000);
    oleadaTimer -> start();



    // Esto es lo que permite manejar a las balas
    timer = new QTimer(this);
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
    labelCollector ->setText("Balas en Collector: " + QString::number(bulletCollector.getSize()));

    for (int i = 0; i < bulletsList.getSize(); i++){
        Bullets* bullet = bulletsList.getPosVal(i);
        bullet ->setPos(bullet->pos().x() + 10, bullet -> pos().y());
        if (bullet->pos().x() >= 1000){
            //cout << "SE SALIO " << endl;
            bulletsList.deletePos(i);
            bullet->disminuirDano();
            bulletCollector.insertHead(bullet);
        }
    }

    if ((dataList.getPosVal(5) <= 300) && (player -> pos().y() < 500)) {
        player->setPos(player->pos().x(), player->pos().y() + 20);
    }
    else if ((dataList.getPosVal(5)  >= 600) && (player -> pos().y() > 100)){
        player->setPos(player->pos().x(), player->pos().y() - 20);
    }
}

void GameScreen::shootBullets(){

    int waitTime = dataList.getPosVal(3)*5;
    timer -> setInterval(500 + waitTime);
    labelBalas -> setText("Balas disponibles: " + QString::number(cantBullets));

    if (cantBullets != 0) {
        cantBullets -= 1;
        Bullets *bullets = new Bullets();
        bullets->setPos(player->pos().x(), player->pos().y());
        scene()->addItem(bullets);
        bulletsList.insertHead(bullets);
    } else {
        cout << "Se acabaron las balas " << endl;
        if (bulletCollector.getSize() > 0) {
            Bullets *bullets = new Bullets();
            bullets = bulletCollector.getHead()->value;
            bulletCollector.deleteHead();
            bullets->setPos(player->pos().x(), player->pos().y());
            //scene() -> addItem(bullets);
            bulletsList.insertHead(bullets);
        }
    }

    cout << "BALAS " << cantBullets << endl;


    //test.insertHead(bullets);


}

void GameScreen::spawnEnemys() {
    labelEnemOleadas ->setText("Faciles: " + QString::number(EnemigosFaciles) +
                               " Medios " + QString::number(EnemigosMedios) +
                               " Dificiles: " + QString::number(EnemigosDificiles));

    //cout << "PRUEBAS" << endl;
    int randomY = qrand() % 400;
    randomY += 100;
    //cout << randomY + 100 << endl;

    int num = QRandomGenerator::global() -> bounded(1, 4);

    if (num == 1 && EnemigosFaciles != 0) {
        //cout << EnemigosFaciles << " Aparecio un facil" << endl;
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
        //cout << "AUN NO SE DEFINE ESTE ENEMIGO" << endl;
        DifficultEnemy *difficultEnemy = new DifficultEnemy();
        difficultEnemy -> setDirection(true);
        difficultEnemy -> setPos(1050, randomY);
        scene() -> addItem(difficultEnemy);
        difficultEnemys.insertHead(difficultEnemy);
        EnemigosDificiles -= 1;
    } else if (EnemigosFaciles == 0 && EnemigosMedios == 0 && EnemigosDificiles == 0){
        //cout << "Suave un touqe, se acabo la oleada" << endl;
    }
    else {
        //cout << "NO APARECIO DE LO OTRO Y SE TUVO QUE LLAMAR A ESTO " << endl;
        return spawnEnemys();
    }



}

void GameScreen::moveEnemys() {
    labelVidas ->setText("Vidas: " + QString::number(cantVidas));
    //cout << easyEnemys.getSize() << endl;
    for (int i = 0; i < easyEnemys.getSize(); i++){
        EasyEnemy* tempEnemy = easyEnemys.getPosVal(i);
        tempEnemy -> setPos(tempEnemy->pos().x() - 1, tempEnemy->pos().y());
        if (tempEnemy-> pos().x() <= 0 ){
            //cout << "SE SALIO" << endl;
            worker -> writeData("6");
            cantVidas -= 1;
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
            //cout << "SE SALIO MEDIUM " << endl;
            worker -> writeData("6");
            cantVidas -= 1;
            scene() ->removeItem(tempEnemy);
            mediumEnemys.deletePos(i);
            delete tempEnemy;
        }
    }

    for (int i = 0; i < difficultEnemys.getSize(); i ++){
        DifficultEnemy* tempEnemy = difficultEnemys.getPosVal(i);
        bool direc = tempEnemy->getDirection();
        if (direc){
            tempEnemy -> setPos(tempEnemy -> pos().x() - 2, tempEnemy -> pos().y() + 1);
        } else if (not direc){
            tempEnemy -> setPos(tempEnemy -> pos().x() - 2, tempEnemy -> pos().y() - 1);
        }
        if ((tempEnemy -> pos().y() <= 100) || (tempEnemy-> pos().y() >= 500) ){
            tempEnemy->setDirection( not tempEnemy->getDirection());
        }
        if (tempEnemy -> pos().x() <= 0){
            worker -> writeData("6");
            cantVidas -= 1;
            scene() -> removeItem(tempEnemy);
            difficultEnemys.deletePos(i);
            delete tempEnemy;
        }
    }
    if (cantVidas == 0){
        this -> close();
    }
}


void GameScreen::checkCollisions() {

    for (int i = 0; i < bulletsList.getSize(); i++){
        for (int j = 0; j < easyEnemys.getSize(); j++) {
            Bullets* bullet = bulletsList.getPosVal(i);
            EasyEnemy* enemy = easyEnemys.getPosVal(j);
            if (bullet ->collidesWithItem(enemy)) {

                //scene() -> removeItem(bullet);
                //scene() -> removeItem(enemy);
                //bulletsList.deletePos(i);
                //easyEnemys.deletePos(j);
                //delete bullet;
                //delete enemy;
                //worker -> writeData("6");
                enemy->disminuirVida(bullet->getDano());

                scene() -> removeItem(bullet);
                bulletsList.deletePos(i);
                delete bullet;

                if (enemy->getVida() <= 0){
                    easyEnemys.deletePos(j);
                    delete enemy;
                }


            }
        }
        for (int j = 0; j < mediumEnemys.getSize(); j++){
            Bullets* bullet = bulletsList.getPosVal(i);
            MediumEnemy* enemy = mediumEnemys.getPosVal(j);
            if (bullet ->collidesWithItem(enemy)) {
                //scene() ->removeItem(bullet);
                //scene() -> removeItem(enemy);
                //bulletsList.deletePos(i);
                //mediumEnemys.deletePos(j);
                //delete bullet;
                //delete enemy;

                enemy->disminuirVida(bullet->getDano());

                scene() -> removeItem(bullet);
                bulletsList.deletePos(i);
                delete bullet;

                if (enemy->getVida() <= 0){
                    mediumEnemys.deletePos(j);
                    delete enemy;
                }
            }
        }
    }
}


void GameScreen::checkOleada(){
    labelFase ->setText("Fase: " + QString::number(fase));
    labelOleada -> setText("Oleada: " + QString::number(oleada));
    //cout << "REVISA EN QUE OLEADA ESTA " << oleada << endl;
    if (EnemigosFaciles == 0 && EnemigosMedios == 0 && EnemigosDificiles == 0){
        cout << "Se acabo la oleada " << endl;
        oleada += 1;
        //velocidadEnemigos = infoOleadas[oleada][0];
        EnemigosFaciles = infoOleadas[oleada][0];
        EnemigosMedios = infoOleadas[oleada][1];
        EnemigosDificiles = infoOleadas[oleada][2];
        //moveTimer ->setInterval(velocidadEnemigos);
    }
    if (oleada == 5 && fase != 0){
        oleada = 0;
        velocidadEnemigos -= 2;
        EnemigosFaciles = infoOleadas[0][0];
        EnemigosMedios = infoOleadas[0][1];
        EnemigosDificiles = infoOleadas[0][2];

    }
    string strOleada = to_string(oleada);
    QByteArray byteArray = QByteArray::fromStdString(strOleada);
    worker -> writeData(byteArray);
}