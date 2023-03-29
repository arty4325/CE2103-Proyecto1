//
// Created by oscaraad on 29/03/23.
//
#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>

class SerialPort : public QSerialPort
{
public:
    SerialPort();
    ~SerialPort();
    void initialize();

private:
    QString portName;
    qint32 baudRate;
};

#endif // SERIALPORT_H
