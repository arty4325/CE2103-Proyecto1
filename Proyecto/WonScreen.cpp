//
// Created by oscaraad on 16/04/23.
//

#include <QDir>
#include "WonScreen.h"
#include <iostream>
using namespace std;

/**
 * @brief pantalla que le dice al jugador que gano
 */
WonScreen::WonScreen(QWidget *parent){
    QGraphicsScene *scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, 1000, 700);
    QString direc = QDir::currentPath();
    QPixmap backgroundImage(direc.mid(0,direc.length() - 18) + "/Imagenes/youWin.png");
    if (backgroundImage.isNull()) {
        cout << "Error: no se pudo cargar la imagen de fondo.";
    }
    else {
        // Crear un objeto QBrush a partir de la imagen
        QBrush backgroundBrush(backgroundImage);

        // Establecer el pincel de fondo de la escena con el objeto QBrush
        scene->setBackgroundBrush(backgroundBrush);
    }
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000, 700);


    show();
}