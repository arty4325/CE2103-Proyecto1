#include "SerialPort.h"

/**
 * @brief Metodo constructor de la clase Serial Port
 */
SerialPort::SerialPort()
{
    portName = "/dev/ttyACM0"; // Reemplazar con el puerto serial que esté utilizando
    baudRate = QSerialPort::Baud9600;
}

/**
 * @brief Metodo que permite abrir el Port Serial
 */
SerialPort::~SerialPort()
{
    if (isOpen()) {
        close();
    }
}

/**
 * @brief Inicializador del port serial
 */
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
