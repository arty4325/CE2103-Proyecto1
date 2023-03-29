#include <QCoreApplication>
#include <QTextStream>
#include "SerialPort.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SerialPort serialPort;
    serialPort.initialize();

    QTextStream(stdout) << "Leyendo datos del puerto serial...\n";
    while (serialPort.isOpen()) {
        if (serialPort.waitForReadyRead(100)) {
            QByteArray data = serialPort.readAll();
            QTextStream(stdout) << QString(data);
        }
    }

    return a.exec();
}



