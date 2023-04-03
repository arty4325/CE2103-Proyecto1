//
// Created by oscaraad on 03/04/23.
//


#include <QWidget>
#include "GameScreen.h"

GameScreen::GameScreen(int Dificultad, QWidget *parent){
    QGraphicsScene *scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, 1000, 1000);

    show();
}