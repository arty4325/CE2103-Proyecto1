//
// Created by oscaraad on 31/03/23.
//
#include "SerialWorker.h"

SerialWorker::SerialWorker(QObject *parent) : QObject(parent)
{
    m_serialPort.setBaudRate(QSerialPort::Baud9600);
    m_serialPort.setPortName("/dev/ttyACM0");
    m_serialPort.open(QIODevice::ReadOnly);

    connect(&m_serialPort, &QSerialPort::readyRead, this, &SerialWorker::readData);
}

void SerialWorker::readData()
{
    m_data += m_serialPort.readAll();

    if (m_data.endsWith("\n")) {
        emit dataReceived(QString(m_data));
        m_data.clear();
    }
}

