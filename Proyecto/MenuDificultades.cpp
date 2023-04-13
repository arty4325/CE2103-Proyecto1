//
// Created by oscaraad on 02/04/23.
//

#include "MenuDificultades.h"
#include "GameScreen.h"
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsProxyWidget>
#include <QRectF>
#include <iostream>
using namespace std;

void MenuDificultades::medium() {
    cout << "Funciona el boton y la interfaz" << endl;
    GameScreen * medium = new GameScreen(1);
    medium -> show();
    this -> close();
}

MenuDificultades::MenuDificultades(QWidget *parent) {
    // Se crea la escena
    QGraphicsScene *scene = new QGraphicsScene();
    scene ->setSceneRect(0, 0, 1000, 700);
    int width = 1000;
    int height = 1000;

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
    setFixedSize(1000, 700);

    show();
}