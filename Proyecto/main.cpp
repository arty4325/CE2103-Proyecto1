#include <QCoreApplication>
#include <QApplication>
#include <QThread>
#include <QTextStream>
#include "SerialWorker.h"
#include "MenuDificultades.h"
#include "ListaSimple.h"
#include <iostream>
using namespace std;


MenuDificultades * menuGeneral;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    menuGeneral = new MenuDificultades();
    menuGeneral -> show();



    return a.exec();

}
