#include "SerialPort.h"

SerialPort::SerialPort()
{
    portName = "/dev/ttyACM0"; // Reemplazar con el puerto serial que esté utilizando
    baudRate = QSerialPort::Baud9600;
}

SerialPort::~SerialPort()
{
    if (isOpen()) {
        close();
    }
}

void SerialPort::initialize()
{
    setPortName(portName);
    setBaudRate(baudRate);
    setDataBits(QSerialPort::Data8);
    setParity(QSerialPort::NoParity);
    setStopBits(QSerialPort::OneStop);
    setFlowControl(QSerialPort::NoFlowControl);
    open(QIODevice::ReadWrite);
}
