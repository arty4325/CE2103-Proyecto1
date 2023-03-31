#include <QCoreApplication>
#include <QThread>
#include <QTextStream>
#include "SerialWorker.h"
#include <iostream>
using namespace std;
QThread workerThread;  // variable global para el hilo

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Creamos un objeto SerialWorker y lo movemos al hilo workerThread
    SerialWorker *worker = new SerialWorker();
    worker->moveToThread(&workerThread);

    // Conectamos la señal dataReceived() del objeto worker a una función lambda que imprime los datos recibidos
    QObject::connect(worker, &SerialWorker::dataReceived, [](const QString& data) {
        cout << "Se recibe informacion" << endl;
        QTextStream(stdout) << data << endl;
    });

    // Conectamos la señal finished() del objeto worker al método quit() del objeto QCoreApplication
    QObject::connect(worker, &SerialWorker::finished, &a, &QCoreApplication::quit);

    // Iniciamos el hilo
    workerThread.start();

    // Ejecutamos la aplicación
    int result = a.exec();

    // Esperamos a que el hilo termine
    workerThread.quit();
    workerThread.wait();

    // Liberamos la memoria del objeto worker
    delete worker;

    return result;
}
