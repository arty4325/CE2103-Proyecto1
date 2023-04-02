//
// Created by oscaraad on 02/04/23.
//

#include "MenuDificultades.h"
#include <QPushButton>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QRectF>
#include <iostream>
#include <QThread>
#include <QTextStream>
#include "SerialWorker.h"
using namespace std;

void MenuDificultades::medium() {
    cout << "Funciona el boton y la interfaz" << endl;
}

MenuDificultades::MenuDificultades(QWidget *parent) {
    // Se crea la escena
    QGraphicsScene *scene = new QGraphicsScene();
    scene ->setSceneRect(0, 0, 1000, 1000);
    int width = 800;
    int height = 600;

    QLabel *label = new QLabel("Proyecto I Datos II");
    QGraphicsProxyWidget *proxy_label = new QGraphicsProxyWidget();
    proxy_label ->setWidget(label);
    QFont font("Arial", 20, QFont::Helvetica);
    label ->setStyleSheet("background-color: white");
    label -> setFont(font);
    scene -> addItem(proxy_label);
    proxy_label -> setPos(380, 250);


    //Ahora se crea un boton el cual crea la ventana para ir al juego de dificultad media
    QPushButton * botonNormal = new QPushButton("Dificultad Normal");
    botonNormal ->setGeometry(0, 0, 170, 50);
    QGraphicsProxyWidget *proxy_normal = new QGraphicsProxyWidget();
    proxy_normal ->setWidget(botonNormal);
    scene -> addItem(proxy_normal);
    proxy_normal -> setPos(400, 500);
    connect(botonNormal, &QPushButton::released, this, &MenuDificultades::medium);


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    show();
    





}